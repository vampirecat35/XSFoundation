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
 * @header      XSNumber.c
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    ...
 */

#include "XS.h"
#include "__XSNumber.h"

extern XSClassID __XSNumberClassID;

XSStatic XSNumber XSNumber_Alloc( void )
{
    return ( XSNumber )XSRuntime_CreateInstance( __XSNumberClassID );
}

XSNumber XSNumber_InitWithBool( XSNumber xsThis, BOOL value )
{
    __XSNumber * num;
    
    num            = ( __XSNumber * )xsThis;
    num->boolValue = value;
    num->types     = __XSNUMBER_TYPE_BOOL;
    
    ( void )value;
    
    return xsThis;
}

XSNumber XSNumber_InitWithChar( XSNumber xsThis, char value )
{
    __XSNumber * num;
    
    num             = ( __XSNumber * )xsThis;
    num->sCharValue = value;
    num->types      = __XSNUMBER_TYPE_SCHAR;
    
    ( void )value;
    
    return xsThis;
}

XSNumber XSNumber_InitWithUnsignedChar( XSNumber xsThis, unsigned char value )
{
    __XSNumber * num;
    
    num             = ( __XSNumber * )xsThis;
    num->uCharValue = value;
    num->types      = __XSNUMBER_TYPE_UCHAR;
    
    ( void )value;
    
    return xsThis;
}

XSNumber XSNumber_InitWithShort( XSNumber xsThis, short value )
{
    __XSNumber * num;
    
    num              = ( __XSNumber * )xsThis;
    num->sShortValue = value;
    num->types       = __XSNUMBER_TYPE_SSHORT;
    
    ( void )value;
    
    return xsThis;
}

XSNumber XSNumber_InitWithUnsignedShort( XSNumber xsThis, unsigned short value )
{
    __XSNumber * num;
    
    num              = ( __XSNumber * )xsThis;
    num->uShortValue = value;
    num->types       = __XSNUMBER_TYPE_USHORT;
    
    ( void )value;
    
    return xsThis;
}

XSNumber XSNumber_InitWithInt( XSNumber xsThis, int value )
{
    __XSNumber * num;
    
    num            = ( __XSNumber * )xsThis;
    num->sIntValue = value;
    num->types     = __XSNUMBER_TYPE_SINT;
    
    ( void )value;
    
    return xsThis;
}

XSNumber XSNumber_InitWithUnsignedInt( XSNumber xsThis, unsigned int value )
{
    __XSNumber * num;
    
    num            = ( __XSNumber * )xsThis;
    num->uIntValue = value;
    num->types     = __XSNUMBER_TYPE_UINT;
    
    ( void )value;
    
    return xsThis;
}

XSNumber XSNumber_InitWithLong( XSNumber xsThis, long value )
{
    __XSNumber * num;
    
    num             = ( __XSNumber * )xsThis;
    num->sLongValue = value;
    num->types      = __XSNUMBER_TYPE_SLONG;
    
    ( void )value;
    
    return xsThis;
}

XSNumber XSNumber_InitWithUnsignedLong( XSNumber xsThis, unsigned long value )
{
    __XSNumber * num;
    
    num             = ( __XSNumber * )xsThis;
    num->uLongValue = value;
    num->types      = __XSNUMBER_TYPE_ULONG;
    
    ( void )value;
    
    return xsThis;
}

XSNumber XSNumber_InitWithLongLong( XSNumber xsThis, long long value )
{
    __XSNumber * num;
    
    num                 = ( __XSNumber * )xsThis;
    num->sLongLongValue = value;
    num->types          = __XSNUMBER_TYPE_SLONGLONG;
    
    ( void )value;
    
    return xsThis;
}

XSNumber XSNumber_InitWithUnsignedLongLong( XSNumber xsThis, unsigned long long value )
{
    __XSNumber * num;
    
    num                 = ( __XSNumber * )xsThis;
    num->uLongLongValue = value;
    num->types          = __XSNUMBER_TYPE_ULONGLONG;
    
    ( void )value;
    
    return xsThis;
}

XSNumber XSNumber_InitWithFloat( XSNumber xsThis, float value )
{
    __XSNumber * num;
    
    num             = ( __XSNumber * )xsThis;
    num->floatValue = value;
    num->types      = __XSNUMBER_TYPE_FLOAT;
    
    ( void )value;
    
    return xsThis;
}

XSNumber XSNumber_InitWithDouble( XSNumber xsThis, double value )
{
    __XSNumber * num;
    
    num              = ( __XSNumber * )xsThis;
    num->doubleValue = value;
    num->types       = __XSNUMBER_TYPE_DOUBLE;
    
    ( void )value;
    
    return xsThis;
}

XSNumber XSNumber_InitWithInteger( XSNumber xsThis, XSInteger value )
{
    __XSNumber * num;
    
    num                = ( __XSNumber * )xsThis;
    num->sIntegerValue = value;
    num->types         = __XSNUMBER_TYPE_SINTEGER;
    
    ( void )value;
    
    return xsThis;
}

XSNumber XSNumber_InitWithUnsignedInteger( XSNumber xsThis, XSUInteger value )
{
    __XSNumber * num;
    
    num                = ( __XSNumber * )xsThis;
    num->uIntegerValue = value;
    num->types         = __XSNUMBER_TYPE_UINTEGER;
    
    ( void )value;
    
    return xsThis;
}

void XSNumber_SetBoolValue( XSNumber xsThis, BOOL value )
{
    XSNumber_InitWithBool( xsThis, value );
}

void XSNumber_SetCharValue( XSNumber xsThis, char value )
{
    XSNumber_InitWithBool( xsThis, value );
}

void XSNumber_SetUnsignedCharValue( XSNumber xsThis, unsigned char value )
{
    XSNumber_InitWithUnsignedChar( xsThis, value );
}

void XSNumber_SetShortValue( XSNumber xsThis, short value )
{
    XSNumber_InitWithShort( xsThis, value );
}

void XSNumber_SetUnsignedShortValue( XSNumber xsThis, unsigned short value )
{
    XSNumber_InitWithUnsignedShort( xsThis, value );
}

void XSNumber_SetIntValue( XSNumber xsThis, int value )
{
    XSNumber_InitWithInt( xsThis, value );
}

void XSNumber_SetUnsignedIntValue( XSNumber xsThis, unsigned int value )
{
    XSNumber_InitWithUnsignedInt( xsThis, value );
}

void XSNumber_SetLongValue( XSNumber xsThis, long value )
{
    XSNumber_InitWithLong( xsThis, value );
}

void XSNumber_SetUnsignedLongValue( XSNumber xsThis, unsigned long value )
{
    XSNumber_InitWithUnsignedLong( xsThis, value );
}

void XSNumber_SetLongLongValue( XSNumber xsThis, long long value )
{
    XSNumber_InitWithLongLong( xsThis, value );
}

void XSNumber_SetUnsignedLongLongValue( XSNumber xsThis, unsigned long long value )
{
    XSNumber_InitWithUnsignedLongLong( xsThis, value );
}

void XSNumber_SetFloatValue( XSNumber xsThis, float value )
{
    XSNumber_InitWithFloat( xsThis, value );
}

void XSNumber_SetDoubleValue( XSNumber xsThis, double value )
{
    XSNumber_InitWithDouble( xsThis, value );
}

void XSNumber_SetIntegerValue( XSNumber xsThis, XSInteger value )
{
    XSNumber_InitWithInteger( xsThis, value );
}

void XSNumber_SetUnsignedIntegerValue( XSNumber xsThis, XSUInteger value )
{
    XSNumber_InitWithUnsignedInteger( xsThis, value );
}
