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
 * @file        __XSBool.c
 * @brief       Private implementation for the XSBool class
 * @author      Jean-David Gadina <macmade@eosgarden.com>
 */

#include "XS.h"
#include "__XSBool.h"

/*!
 * @var         __XSBoolClass
 * @brief       Runtime class definition
 */
static const XSClassInfos __XSBoolClass =
{
    "XSBool",           /* Class name */
    sizeof( __XSBool ), /* Object size */
    NULL,               /* Constructor */
    NULL,               /* Destructor */
    XSBool_Init,        /* Default initializer */
    NULL,               /* Object copy */
    __XSBool_ToString,  /* Object description */
    __XSBool_Equals     /* Object comparison */
};

/*!
 * @var         __XSBoolClassID
 * @brief       Type ID for the runtime class
 */
XSClassID __XSBoolClassID;

void __XSBool_Initialize( void )
{
    __XSBoolClassID = XSRuntime_RegisterClass( &__XSBoolClass );
}

XSString __XSBool_ToString( XSObject object )
{
    if( ( ( __XSBool * )object )->value == YES )
    {
        return XSSTR( ( char * )"YES" );
    }
    
    return XSSTR( ( char * )"NO" );
}

BOOL __XSBool_Equals( XSObject object1, XSObject object2 )
{
    __XSBool * b1;
    __XSBool * b2;
    
    b1 = ( __XSBool * )object1;
    b2 = ( __XSBool * )object2;
    
    return ( b1->value == b2->value ) ? YES : NO;
}