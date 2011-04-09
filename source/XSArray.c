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
 * @header      XSArray.c
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    ...
 */

#include "XS.h"
#include "__XSArray.h"

extern XSClassID __XSArrayClassID;

XSStatic XSArray XSArray_Alloc( void )
{
    return ( XSArray )XSRuntime_CreateInstance( __XSArrayClassID );
}

XSArray XSArray_Init( XSArray xsThis )
{
    return XSArray_InitWithCapacity( xsThis, XSARRAY_DEFAULT_CAPACITY );
}

XSArray XSArray_InitWithCapacity( XSArray xsThis, XSUInteger capacity )
{
    void      ** store;
    __XSArray  * array;
    
    if( NULL == ( store = ( void ** )XSAlloc( capacity * sizeof( void * ) ) ) )
    {
        return NULL;
    }
    
    array           = ( __XSArray * )xsThis;
    array->values   = store;
    array->capacity = capacity;
    array->count    = 0;
    
    return ( XSArray )array;
}

XSArray XSArray_InitWithValues( XSArray xsThis, void * value1, ... )
{
    va_list args;
    void  * value;
    
    if( value1 == NULL )
    {
        return xsThis;
    }
    
    XSArray_Init( xsThis );
    XSArray_AppendValue( xsThis, value1 );
    va_start( args, value1 );
    
    while( NULL != ( value = va_arg( args, void * ) ) )
    {
        XSArray_AppendValue( xsThis, value );
    }
    
    va_end( args );
    
    return xsThis;
}

XSUInteger XSArray_Count( XSArray xsThis )
{
    return ( ( __XSArray * )xsThis )->count;
}

void XSArray_AppendValue( XSArray xsThis, void * value )
{
    __XSArray * _array;
    void     ** store;
    
    _array = ( __XSArray * )xsThis;
    
    if( _array->count == _array->capacity )
    {
        if( NULL == ( store = ( void ** )XSRealloc( _array->values, ( _array->count + _array->capacity ) * sizeof( void * ) ) ) )
        {
            return;
        }
        
        _array->values   = store;
        _array->capacity = _array->count + _array->capacity;
    }
    
    _array->values[ _array->count++ ] = XSRetain( value );
}

void XSArray_InsertValueAtIndex( XSArray xsThis, void * value, XSUInteger i )
{
    __XSArray  * _array;
    void      ** store;
    XSUInteger   j;
    
    _array = ( __XSArray * )xsThis;
    
    if( i >= _array->count )
    {
        XSArray_AppendValue( xsThis, value );
    }
    
    if( _array->count + 1 > _array->capacity )
    {
        if( NULL == ( store = ( void ** )XSRealloc( _array->values, ( _array->count + _array->capacity ) * sizeof( void * ) ) ) )
        {
            return;
        }
        
        _array->values   = store;
        _array->capacity = _array->count + _array->capacity;
    }
    
    for( j = _array->count; j == i; j++ )
    {
        _array->values[ j ] = _array->values[ j - 1 ];
    }
    
    _array->values[ i ] = XSRetain( value );
}

void * XSArray_ReplaceValueAtIndex( XSArray xsThis, void * value, XSUInteger i )
{
    __XSArray * _array;
    void      * old;
    
    _array = ( __XSArray * )xsThis;
    
    if( i > _array->count )
    {
        return NULL;
    }
    
    old                 = _array->values[ i ];
    _array->values[ i ] = XSRetain( value );
    
    if( XSGetRetainCount( old ) == 1 )
    {
        XSRelease( old );
        
        return NULL;
    }
    
    return XSRelease( old );
}

void * XSArray_ValueAtIndex( XSArray xsThis, XSUInteger i )
{
    __XSArray * _array;
    
    _array = ( __XSArray * )xsThis;
    
    if( i >= _array->count )
    {
        return NULL;
    }
    
    return _array->values[ i ];
}

void * XSArray_RemoveValueAtIndex( XSArray xsThis, XSUInteger i )
{
    __XSArray  * _array;
    XSUInteger   j;
    
    _array = ( __XSArray * )xsThis;
    
    if( i > _array->count )
    {
        return NULL;
    }
    
    for( j = i; j < _array->count - 1; j++ )
    {
        _array->values[ j ] = _array->values[ j + 1 ];
    }
    
    _array->values[ _array->count-- ] = NULL;
    
    return NULL;
}

BOOL XSArray_ContainsValue( XSArray xsThis, void * value )
{
    __XSArray  * _array;
    XSUInteger   i;
    
    _array = ( __XSArray * )xsThis;
    
    for( i = 0; i < _array->count; i++ )
    {
        if( _array->values[ i ] == value )
        {
            return YES;
        }
    }
    
    return NO;
}

XSUInteger XSArray_Index( XSArray xsThis )
{
    __XSArray  * _array;
    
    _array = ( __XSArray * )xsThis;
    
    return _array->cur;
}

void * XSArray_Current( XSArray xsThis )
{
    __XSArray  * _array;
    
    _array = ( __XSArray * )xsThis;
    
    return _array->values[ _array->cur ];
}

void * XSArray_Next( XSArray xsThis )
{
    __XSArray  * _array;
    
    _array = ( __XSArray * )xsThis;
    
    if( ( _array->cur + 1 ) == _array->count )
    {
        return NULL;
    }
    
    return _array->values[ ++_array->cur ];
}

void * XSArray_Previous( XSArray xsThis )
{
    __XSArray  * _array;
    
    _array = ( __XSArray * )xsThis;
    
    if( _array->cur == 0 )
    {
        return _array->values[ 0 ];
    }
    
    return _array->values[ --_array->cur ];
}

void XSArray_Rewind( XSArray xsThis )
{
    __XSArray  * _array;
    
    _array      = ( __XSArray * )xsThis;
    _array->cur = 0;
}
