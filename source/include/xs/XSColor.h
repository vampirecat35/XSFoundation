/*******************************************************************************
 * Copyright (c) 2011, Jean-David Gadina - www.xs-labs.com
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
 * @file        XSColor.h
 * @brief       XSColor class functions
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#ifndef _XS_COLOR_H_
#define _XS_COLOR_H_
#pragma once

#include "XSMacros.h"

XS_EXTERN_C_BEGIN

/*!
 * @typedef     XSColor
 * @brief       Opaque type for the XSColor objects
 */
typedef struct __XSColor_Struct * XSColor;

/*!
 * @brief       Object allocator
 * @result      The allocated object
 */
XSStatic XSObject XSColor_Alloc( void );

/*!
 * @brief       Initialize a color object
 * @param       xsThis  The color object
 * @result      The color object
 */
XSObject XSColor_Init( XSObject xsThis );

/*!
 * @brief       Initializes a color with RGB components
 * @param       xsThis  The color object
 * @param       r       The red value
 * @param       g       The green value
 * @param       b       The blue value
 * @result      The color object
 */
XSColor XSColor_InitWithRGB( XSColor xsThis, XSFloat r, XSFloat g, XSFloat b );

/*!
 * @brief       Initializes a color with RGB components
 * @param       xsThis  The color object
 * @param       h       The hue value
 * @param       s       The saturation value
 * @param       l       The luminance value
 * @result      The color object
 */
XSColor XSColor_InitWithHSL( XSColor xsThis, XSFloat h, XSFloat s, XSFloat l );

/*!
 * @brief       Initializes a color with HSL components
 * @param       xsThis  The color object
 * @param       h       The hue value
 * @param       s       The saturation value
 * @param       v       The value value
 * @result      The color object
 */
XSColor XSColor_InitWithHSV( XSColor xsThis, XSFloat h, XSFloat s, XSFloat v );

/*!
 * @brief       Initializes a color with RGB components
 * @param       xsThis  The color object
 * @param       r       The red value
 * @param       g       The green value
 * @param       b       The blue value
 * @param       a       The alpha value
 * @result      The color object
 */
XSColor XSColor_InitWithRGBA( XSColor xsThis, XSFloat r, XSFloat g, XSFloat b, XSFloat a );

/*!
 * @brief       Initializes a color with RGB components
 * @param       xsThis  The color object
 * @param       h       The hue value
 * @param       s       The saturation value
 * @param       l       The luminance value
 * @param       a       The alpha value
 * @result      The color object
 */
XSColor XSColor_InitWithHSLA( XSColor xsThis, XSFloat h, XSFloat s, XSFloat l, XSFloat a );

/*!
 * @brief       Initializes a color with HSL components
 * @param       xsThis  The color object
 * @param       h       The hue value
 * @param       s       The saturation value
 * @param       v       The value value
 * @param       a       The alpha value
 * @result      The color object
 */
XSColor XSColor_InitWithHSVA( XSColor xsThis, XSFloat h, XSFloat s, XSFloat v, XSFloat a );

/*!
 * @brief       Initializes a color with HSVA components
 * @result      The color object
 */
XSAutoreleased XSStatic XSColor XSColor_BlackColor( void );

/*!
 * @brief       Create a black color object
 * @result      The color object
 */
XSAutoreleased XSStatic XSColor XSColor_WhiteColor( void );

/*!
 * @brief       Initializes a red color object
 * @result      The color object
 */
XSAutoreleased XSStatic XSColor XSColor_RedColor( void );

/*!
 * @brief       Initializes a green color object
 * @result      The color object
 */
XSAutoreleased XSStatic XSColor XSColor_GreenColor( void );

/*!
 * @brief       Initializes a blue color object
 * @result      The color object
 */
XSAutoreleased XSStatic XSColor XSColor_BlueColor( void );

/*!
 * @brief       Get the red component
 * @param       xsThis  The color object
 * @result      The red component
 */
XSFloat XSColor_GetRed( XSColor xsThis );

/*!
 * @brief       Get the green component
 * @param       xsThis  The color object
 * @result      The green component
 */
XSFloat XSColor_GetGreen( XSColor xsThis );

/*!
 * @brief       Get the blue component
 * @param       xsThis  The color object
 * @result      The blue component
 */
XSFloat XSColor_GetBlue( XSColor xsThis );

/*!
 * @brief       Get the hue component
 * @param       xsThis  The color object
 * @result      The hue component
 */
XSFloat XSColor_GetHue( XSColor xsThis );

/*!
 * @brief       Get the saturation component
 * @param       xsThis  The color object
 * @result      The saturation component
 */
XSFloat XSColor_GetSaturation( XSColor xsThis );

/*!
 * @brief       Get the luminance component
 * @param       xsThis  The color object
 * @result      The luminance component
 */
XSFloat XSColor_GetLuminance( XSColor xsThis );

/*!
 * @brief       Get the value component
 * @param       xsThis  The color object
 * @result      The value component
 */
XSFloat XSColor_GetValue( XSColor xsThis );

/*!
 * @brief       Get the alpha component
 * @param       xsThis  The color object
 * @result      The alpha component
 */
XSFloat XSColor_GetAlpha( XSColor xsThis );

/*!
 * @brief       Sets the red component
 * @param       xsThis  The color object
 * @param       v       The red component
 * @result      void
 */
void XSColor_SetRed( XSColor xsThis, XSFloat v );

/*!
 * @brief       Sets the green component
 * @param       xsThis  The color object
 * @param       v       The green component
 * @result      void
 */
void XSColor_SetGreen( XSColor xsThis, XSFloat v );

/*!
 * @brief       Sets the blue component
 * @param       xsThis  The color object
 * @param       v       The blue component
 * @result      void
 */
void XSColor_SetBlue( XSColor xsThis, XSFloat v );

/*!
 * @brief       Sets the hue component
 * @param       xsThis  The color object
 * @param       v       The hue component
 * @result      void
 */
void XSColor_SetHue( XSColor xsThis, XSFloat v );

/*!
 * @brief       Sets the saturation component
 * @param       xsThis  The color object
 * @param       v       The saturation component
 * @result      void
 */
void XSColor_SetSaturation( XSColor xsThis, XSFloat v );

/*!
 * @brief       Sets the luminance component
 * @param       xsThis  The color object
 * @param       v       The luminance component
 * @result      void
 */
void XSColor_SetLuminance( XSColor xsThis, XSFloat v );

/*!
 * @brief       Sets the value component
 * @param       xsThis  The color object
 * @param       v       The value component
 * @result      void
 */
void XSColor_SetValue( XSColor xsThis, XSFloat v );

/*!
 * @brief       Sets the alpha component
 * @param       xsThis  The color object
 * @param       v       The alpha component
 * @result      void
 */
void XSColor_SetAlpha( XSColor xsThis, XSFloat v );

XS_EXTERN_C_END

#endif /* _XS_COLOR_H_ */
