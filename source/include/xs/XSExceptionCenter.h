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
 * @header      XSExceptionCenter.h
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    XSExceptionCenter class functions
 */

#ifndef _XS_EXCEPTION_CENTER_H_
#define _XS_EXCEPTION_CENTER_H_
#pragma once

#include "XSMacros.h"

XS_EXTERN_C_BEGIN

#include "XSNotification.h"

/*!
 * @typedef     XSExceptionCenter
 * @abstract    Opaque type for the XSExceptionCenter objects
 */
typedef struct __XSExceptionCenter * XSExceptionCenter;

struct XSExceptionContext_Struct
{
    jmp_buf            * e_env;
    int                  caught;
    volatile int         e;
};

extern struct XSExceptionContext_Struct * XSExceptionContext;

#define XSThrow   for( ; ; longjmp( *( XSExceptionContext->e_env ), 1 ) ) XSExceptionContext->e = 

#define XSTry                                                   \
    {                                                           \
        jmp_buf * e_prev;                                       \
        jmp_buf   e_cur;                                        \
                                                                \
        e_prev                    = XSExceptionContext->e_env;  \
        XSExceptionContext->e_env = &e_cur;                     \
                                                                \
        if( setjmp( e_cur ) == 0 )                              \
        {                                                       \
            do

#define __XSCatch( action )                                                         \
            while( XSExceptionContext->caught = 0, XSExceptionContext->caught );    \
        }                                                                           \
        else                                                                        \
        {                                                                           \
            XSExceptionContext->caught = 1;                                         \
        }                                                                           \
                                                                                    \
        XSExceptionContext->e_env = e_prev;                                         \
    }                                                                               \
    if( !XSExceptionContext->caught || action )                                     \
    {}                                                                              \
    else

#define XSCatch( e ) __XSCatch( ( ( e ) = XSExceptionContext->e, 0 ) )

/*!
 * @function    XSExceptionCenter_Alloc
 * @abstract    Object allocator
 * @result      The allocated object
 */
XSStatic XSObject XSExceptionCenter_Alloc( void );

/*!
 * @function    XSExceptionCenter_Init
 * @abstract    Creates a notification center
 * @param       xsThis  The notification center
 * @result      The notification center
 */
XSObject XSExceptionCenter_Init( XSObject xsThis );

/*!
 * @function    XSExceptionCenter_DefaultCenter
 * @abstract    Gets the default notification center
 * @result      The default notification center
 */
XSStatic XSAutoreleased XSExceptionCenter XSExceptionCenter_DefaultCenter( void );

XS_EXTERN_C_END

#endif /* _XS_EXCEPTION_CENTER_H_ */
