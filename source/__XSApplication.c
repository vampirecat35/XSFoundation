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
 * @file        __XSApplication.c
 * @brief       Private implementation for the XSApplication class
 * @author      Jean-David Gadina <macmade@eosgarden.com>
 */

#include "XS.h"
#include "__XSApplication.h"

/*!
 * @var         __XSApplicationClass
 * @brief       Runtime class definition
 */
static const XSClassInfos __XSApplicationClass =
{
    "XSApplication",            /* Class name */
    sizeof( __XSApplication ),  /* Object size */
    __XSApplication_Construct,  /* Constructor */
    __XSApplication_Destruct,   /* Destructor */
    XSApplication_Init,         /* Default initializer */
    __XSApplication_Copy,       /* Object copy */
    NULL,                       /* Object description */
    NULL                        /* Object comparison */
};

/*!
 * @var         __XSApplicationClassID
 * @brief       Type ID for the runtime class
 */
XSClassID __XSApplicationClassID;

void __XSApplication_Initialize( void )
{
    __XSApplicationClassID = XSRuntime_RegisterClass( &__XSApplicationClass );
}

void __XSApplication_Construct( XSObject object )
{
    __XSApplication * app;
    
    app = ( __XSApplication * )object;
    
    app->args      = XSAlloc( 25 * sizeof( XSApplicationArgument ) );
    app->arg_alloc = 25;
    app->arg_count = 0;
}

void __XSApplication_Destruct( XSObject object )
{
    XSUInteger        i;
    __XSApplication * app;
    
    app = ( __XSApplication * )object;
    
    for( i = 0; i < app->arg_count; i++ )
    {
        XSRelease( app->args[ i ] );
    }
    
    XSRelease( app->args );
}

void __XSApplication_Copy( XSObject source, XSObject destination )
{
    __XSApplication * a1;
    __XSApplication * a2;
    XSUInteger        i;
    
    a1 = ( __XSApplication * )source;
    a2 = ( __XSApplication * )destination;
    
    a2->args = XSCopy( a1->args );
    
    for( i = 0; i < a1->arg_count; i++ )
    {
        XSRetain( a2->args[ i ] );
    }
}

void __XSApplication_ProcessArguments( __XSApplication * app )
{
    XSInteger                i;
    const char             * name;
    char                   * value;
    XSApplicationArgument arg;
    
    i = 0;
    
    while( i < app->argc )
    {
        name  = app->argv[ i ];
        value = NULL;
        
        if( ( value = strstr( name, "=" ) ) != NULL )
        {
            *( value ) = 0;
            
            value++;
        }
        
        arg  = XSApplication_GetArgument( ( XSApplication )app, name );
        
        if( arg == NULL )
        {
            i++;
        }
        else
        {
            switch( XSApplicationArgument_GetType( arg ) )
            {
                case XSApplicationArgumentTypeFlag:
                    
                    XSApplicationArgument_SetFlag( arg );
                    i++;
                    break;
                    
                case XSApplicationArgumentTypeInteger:
                    
                    if( app->argc == i + 1 && value == NULL )
                    {
                        break;
                    }
                    
                    XSApplicationArgument_SetIntegerValue( arg, ( XSInteger )atoi( ( value != NULL ) ? value : app->argv[ ++i ] ) );
                    break;
                    
                case XSApplicationArgumentTypeUnsignedInteger:
                    
                    if( app->argc == i + 1 && value == NULL )
                    {
                        break;
                    }
                    
                    XSApplicationArgument_SetUnsignedIntegerValue( arg, ( XSUInteger )atoi( ( value != NULL ) ? value : app->argv[ ++i ] ) );
                    break;
                    
                case XSApplicationArgumentTypeString:
                    
                    if( app->argc == i + 1 && value == NULL )
                    {
                        break;
                    }
                    
                    XSApplicationArgument_SetStringValue( arg, ( value != NULL ) ? value : app->argv[ ++i ] );
                    break;
                    
                case XSApplicationArgumentTypeFloat:
                    
                    if( app->argc == i + 1 && value == NULL )
                    {
                        break;
                    }
                    
                    XSApplicationArgument_SetFloatValue( arg, ( XSFloat )atof( ( value != NULL ) ? value : app->argv[ ++i ] ) );
                    break;
                    
                default:
                    
                    i++;
                    break;
            }
        }
        
        i++;
    }
}
