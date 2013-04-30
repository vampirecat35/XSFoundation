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
 * @file        __XSTimer.c
 * @brief       Private implementation for the XSTimer class
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include "XS.h"
#include "__XSTimer.h"

/*!
 * @var         __XSTimerClass
 * @brief       Runtime class definition
 */
static const XSClassInfos __XSTimerClass =
{
    "XSTimer",              /* Class name */
    sizeof( __XSTimer ),    /* Object size */
    NULL,                   /* Constructor */
    NULL,                   /* Destructor */
    NULL,                   /* Default initializer */
    NULL,                   /* Object copy */
    NULL,                   /* Object description */
    NULL                    /* Object comparison */
};

/*!
 * @var         __XSTimerClassID
 * @brief       Type ID for the runtime class
 */
XSClassID __XSTimerClassID;

void __XSTimer_Initialize( void )
{
    __XSTimerClassID = XSRuntime_RegisterClass( &__XSTimerClass );
    
    XSRuntime_BindMethodToClassID( __XSTimerClassID, ( void ( * )( void ) )XSTimer_Init, "Init", "XSObject" );
    XSRuntime_BindMethodToClassID( __XSTimerClassID, ( void ( * )( void ) )XSTimer_RunOnce, "RunOnce", "void" );
    XSRuntime_BindMethodToClassID( __XSTimerClassID, ( void ( * )( void ) )XSTimer_RunAndRepeat, "RunAndRepeat", "void" );
    XSRuntime_BindMethodToClassID( __XSTimerClassID, ( void ( * )( void ) )XSTimer_Invalidate, "Invalidate", "void" );
    XSRuntime_BindMethodToClassID( __XSTimerClassID, ( void ( * )( void ) )XSTimer_IsValid, "IsValid", "BOOL" );
}

void __XSTimer_RunOnce( XSThread thread, void * object )
{
    __XSTimer * t;
    
    ( void )thread;
    
    t = ( __XSTimer * )object;
    
    usleep( t->msecs * 1000 );
    t->func( ( XSTimer )t );
     
}

void __XSTimer_RunAndRepeat( XSThread thread, void * object )
{
    __XSTimer * t;
    
    ( void )thread;
    
     t = ( __XSTimer * )object;
     
     while( t->valid == YES )
     {
        usleep( t->msecs * 1000 );
        t->func( ( XSTimer )t );
     }
}
