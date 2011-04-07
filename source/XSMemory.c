/*******************************************************************************
 * Copyright (c) 2011, Jean-David Gadina <macmade@eosgarden.com>
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/
 
/* $Id$ */

/*!
 * @file        XSMemory.c
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    Memory management
 */

#include "XS.h"
#include "__XSMemory.h"

/*!
 * @function    XSAutoreleasePool_Create
 * @abstract    Creates a new auto-release pool
 * @description The newly created pool will be set as the active one, meaning
 *              objects auto-released after the pool creation will be placed
 *              inside it.
 * @result      The new auto-release pool object
 */
XSAutoreleasePool XSAutoreleasePool_Create( void )
{
    __XSAutoreleasePool * ap;
    
    if( __xsmemory_ar_pools_num == XS_MEMORY_MAX_AR_POOLS )
    {
        fprintf( stderr, "Error: maximum number of auto-release pools reached: %u\n", XS_MEMORY_MAX_AR_POOLS );
        exit( EXIT_FAILURE );
    }
    
    if( NULL == ( ap = __XSAutoreleasePool_Alloc() ) )
    {
        fprintf( stderr, "Error: unable to allocate memory for the auto-release pool\n" );
        exit( EXIT_FAILURE );
    }
    
    if( NULL == ( ap->objects = ( void ** )calloc( sizeof( void * ), XS_MEMORY_NUM_OBJECTS ) ) )
    {
        free( ap );
        fprintf( stderr, "Error: unable to allocate memory for the auto-release pool\n" );
        exit( EXIT_FAILURE );
    }
    
    ap->size                                         = XS_MEMORY_NUM_OBJECTS;
    ap->numObjects                                   = 0;
    __xsmemory_ar_pools[ __xsmemory_ar_pools_num++ ] = ap;
    
    return ( XSAutoreleasePool )ap;
}

/*!
 * @function    XSAutoreleasePool_Drain
 * @abstract    Removes objects from the current auto-release pool, sending the a release message.
 * @result      void
 */
void XSAutoreleasePool_Drain( void )
{
    __XSAutoreleasePool * ap;
    
    ap = __XSMemory_GetCurrentAutoreleasePool();
    
    __XSMemory_AutoreleasePoolDrain( ap );
}

/*!
 * @function    XSAlloc
 * @abstract    Allocates memory
 * descriton    Returned pointer will have to be passed to the XSRelease
 *              function in order to be free.
 * @param       size    The number of bytes to allocate
 * @param       ...     Reserved for internal runtime use
 * @result      A pointer to the allocated memory
 */
void * XSAlloc( size_t size, ... )
{
    va_list                    args;
    __XSMemoryObject         * o;
    char                     * ptr;
    XSClassID                  classID;
    const XSClassInfos const * cls;
    
    va_start( args, size );
    
    classID = va_arg( args, XSClassID );
    
    va_end( args );
    
    o = calloc( sizeof( __XSMemoryObject ) + size, 1 );
    
    if( o == NULL )
    {
        return NULL;
    }
    
    if( classID > 0 && XSRuntime_GetClassForClassID( classID ) != NULL )
    {
        o->classID = classID;
    }
    else
    {
        classID = 0;
    }
    
    o->retainCount = 1;
    o->size        = size;
    
    ptr     =  ( char * )o;
    ptr    += ( sizeof( __XSMemoryObject ) );
    o->data = ptr;
    
    if( classID > 0 )
    {
        cls = XSRuntime_GetClassForClassID( o->classID );
        
        if( cls->construct != NULL )
        {
            cls->construct( ptr );
        }
    }
    
    return ptr;
}

/*!
 * @function    XSRealloc
 * @abstract    Reallocates memory
 * @param       ptr     The pointer to reallocate
 * @param       size    The new size in bytes
 * @result      The new pointer to the reallocated memory
 */
void * XSRealloc( void * ptr, size_t size )
{
    __XSMemoryObject * o;
    void             * data;
    
    if( ptr == NULL )
    {
        return NULL;
    }
    
    o    = __XSMemory_GetMemoryObject( ptr );
    data = realloc( o->data, size );
    
    if( data == NULL )
    {
        return NULL;
    }
    
    o->data = data;
    o->size = size;
    
    return o->data;
}

/*!
 * @function    XSRetain
 * @abstract    Retains a memory pointer, preventing it to be freed
 * @description When retaining an object, the internal retain count is
 *              incremented. It means you own an object that you retain, and
 *              that you are responsible to release it using XSRelease.
 * @param       ptr     The pointer to retain
 * @result      The pointer passed, to allow function chaining
 */
void * XSRetain( void * ptr )
{
    __XSMemoryObject * o;
    
    if( ptr == NULL )
    {
        return NULL;
    }
    
    o = __XSMemory_GetMemoryObject( ptr );
    
    o->retainCount++;
    
    return ptr;
}

/*!
 * @function    XSRelease
 * @abstract    Releases a memory pointer
 * @description When releasing an object, the internal retain count is
 *              decremented. When it reaches 0, the pointer will be
 *              automatically freed.
 * @param       ptr     The pointer to release
 * @result      The pointer passed, to allow function chaining
 */
void * XSRelease( void * ptr )
{
    __XSMemoryObject         * o;
    const XSClassInfos const * cls;
    
    if( ptr == NULL )
    {
        return NULL;
    }
    
    o = __XSMemory_GetMemoryObject( ptr );
    
    o->retainCount--;
    
    if( o->retainCount == 0 )
    {
        if( o->classID != 0 )
        {
            cls = XSRuntime_GetClassForClassID( o->classID );
            
            if( cls->destruct != NULL )
            {
                cls->destruct( ptr );
            }
        }
        
        free( o );
        
        return NULL;
    }
    
    return ptr;
}

/*!
 * @function    XSAutorelease
 * @abstract    Marks a memory pointer as auto-releasable
 * @description The pointer will be placed in the instance of the current
 *              auto-release pool, and will receive a release message the next
 *              the auto-release pool is drained.
 * @param       The memory pointer to mark as auto-releasable
 * @result      The pointer passed, to allow function chaining
 */
void * XSAutorelease( void * ptr )
{
    __XSAutoreleasePool * ap;
    
    if( ptr == NULL )
    {
        return NULL;
    }
    
    ap = __XSMemory_GetCurrentAutoreleasePool();
    
    if( ap == NULL )
    {
        fprintf( stderr, "Warning: autoreleasing object %p with no auto-release pool in place - leaking memory\n", ptr );
    }
    
    if( ap->numObjects == ap->size )
    {
        ap->objects = ( void ** )realloc( ap->objects, sizeof( void * ) * ( ap->size + XS_MEMORY_NUM_OBJECTS ) );
        
        if( ap->objects == NULL )
        {
            fprintf( stderr, "Error: unable to allocate memory for the auto-release pool\n" );
            exit( EXIT_FAILURE );
        }
        
        ap->size += XS_MEMORY_NUM_OBJECTS;
    }
    
    ap->objects[ ap->numObjects++ ] = ptr;
    
    return ptr;
}

/*!
 * @function    XSAutoAlloc
 * @abstract    Allocates auto-releasable memory
 * @description When using this function, the object will automatically receive
 *              a release message the next time the current auto-release pool
 *              is drained. It means you don't own it, and that you are not
 *              responsible to release it explicitely.
 * @param       size    The size to allocate in bytes
 * @result      A pointer to the allocated memory,
 */
void * XSAutoAlloc( size_t size )
{
    void * ptr;
    
    ptr = XSAlloc( size );
    
    XSAutorelease( ptr );
    
    return ptr;
}

/*!
 * @function    XSCopy
 * @abstract    Copies a pointer
 * @description This function executes a soft-copy. When using a structure with
 *              pointers, only the first level is copied.
 *              Note that you are responsible to release the copied pointer
 *              by using the XSRelease function.
 * @param       ptr     The pointer to copy
 * @result      The copy of the new pointer
 */
void * XSCopy( void * ptr )
{
    __XSMemoryObject         * o;
    void                     * ptr2;
    const XSClassInfos const * cls;
    
    if( ptr == NULL )
    {
        return NULL;
    }
    
    o = __XSMemory_GetMemoryObject( ptr );
    
    if( o->classID != 0 )
    {
        cls  = XSRuntime_GetClassForClassID( o->classID );
        ptr2 = XSAlloc( o->size, o->classID );
        
        if( ptr2 == NULL )
        {
            return NULL;
        }
        
        memcpy( ptr2, o->data, o->size );
        
        if( cls->copy != NULL )
        {
            cls->copy( ptr, ptr2 );
        }
    }
    else
    {
        ptr2 = XSAlloc( o->size );
        
        if( ptr2 == NULL )
        {
            return NULL;
        }
        
        memcpy( ptr2, o->data, o->size );
    }
    
    return ptr2;
}

/*!
 * @function    XSEquals
 * @abstract    Compares two pointers/objects
 * @param       ptr1    The first pointer/object
 * @param       ptr2    The second pointer/object
 * @result      True if the two pointers/objects are equals, otherwise false
 */
BOOL XSEquals( void * ptr1, void * ptr2 )
{
    ( void )ptr1;
    ( void )ptr2;
    
    return NO;
}

/*!
 * @function    XSHash
 * @abstract    Hashes a pointer/object
 * @param       ptr     The pointer/object to hash
 * @result      The hash of the pointer/object
 */
XSString XSHash( void * ptr )
{
    ( void )ptr;
    
    return NULL;
}

/*!
 * @function    XSGetRetainCount
 * @abstract    Gets the retain count for a pointer
 * @param       ptr     The pointer
 * @result      The retain count
 */
XSUInteger XSGetRetainCount( void * ptr )
{
    __XSMemoryObject * o;
    
    if( ptr == NULL )
    {
        return 0;
    }
    
    o = __XSMemory_GetMemoryObject( ptr );
    
    return o->retainCount;
}
