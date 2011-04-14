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
 * @file        __XSBag.c
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    ...
 */

#include "XS.h"
#include "__XSBag.h"

/*!
 * @var         __XSBagClass
 * @abstract    Runtime class definition
 */
static const XSClassInfos __XSBagClass =
{
    "XSBag",            /* Class name */
    sizeof( __XSBag ),  /* Object size */
    NULL,               /* Constructor */
    __XSBag_Destruct,   /* Destructor */
    NULL,               /* Object copy */
    __XSBag_ToString,   /* Object description */
    NULL                /* Object comparison */
};

/*!
 * @var         __XSBagClassID
 * @abstract    Type ID for the runtine class
 */
XSClassID __XSBagClassID;

void __XSBag_Initialize( void )
{
    __XSBagClassID = XSRuntime_RegisterClass( &__XSBagClass );
}

void __XSBag_Destruct( void * object )
{
    __XSBag  * bag;
    XSUInteger i;
    
    bag = ( __XSBag * )object;
    
    if( bag->values != NULL )
    {
        for( i = 0; i < bag->count; i++ )
        {
            if( bag->values[ i ] != NULL )
            {
                XSRelease( bag->values[ i ] );
            }
        }
        
        XSRelease( bag->values );
    }
}

XSString __XSBag_ToString( void * object )
{
    XSUInteger i;
    __XSBag  * bag;
    XSString   description;
    
    description = XSString_Init( XSString_Alloc() );
    bag         = ( __XSBag * )object;
    
    XSString_AppendFormat( description, ( char * )"%lu items: {\n", bag->count );
    
    for( i = 0; i < bag->count; i++ )
    {
        if( bag->values[ i ] == NULL )
        {
            XSString_AppendCString( description, ( char * )"    (null),\n" );
        }
        else if( XSRuntime_IsInstance( bag->values[ i ] ) )
        {
            XSString_AppendFormat( description, ( char * )"    %s,\n", ( char * )XSRuntime_ObjectDescription( bag->values[ i ] ) );
        }
        else
        {
            XSString_AppendFormat( description, ( char * )"    %p,\n", bag->values[ i ] );
        }
    }
    
    XSString_AppendCString( description, ( char * )"}" );
    
    return XSAutorelease( description );
}
