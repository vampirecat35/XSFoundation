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
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    ...
 */

#include "XS.h"
#include "__XSApplication.h"

/*!
 * @var         __XSApplicationClass
 * @abstract    Runtime class definition
 */
static const XSRuntimeClass __XSApplicationClass =
{
    "XSApplication",            /* Class name */
    __XSApplication_Init,       /* Constructor */
    __XSApplication_Dealloc,    /* Destructor */
    NULL,                       /* Object copy */
    NULL                        /* Object description */
};

/*!
 * @var         __XSApplicationTypeID
 * @abstract    Type ID for the runtine class
 */
static XSTypeID __XSApplicationTypeID;

/*!
 * @function    __XSApplication_Initialize
 * @abstract    Runtime initialization
 * @result      void
 */
void __XSApplication_Initialize( void )
{
    __XSApplicationTypeID = XSRuntime_RegisterClass( &__XSApplicationClass );
}

/*!
 * @function    __XSApplication_Alloc
 * @abstract    Object allocator
 * @result      A pointer to the allocated object
 */
XSApplication * __XSApplication_Alloc( void )
{
    return ( XSApplication * )XSRuntime_CreateInstance( __XSApplicationTypeID, sizeof( XSApplication ) );
}

/*!
 * @function    __XSApplication_Init
 * @abstract    Constructor
 * @param       object  A pointer to the object
 * @result      void
 */
void __XSApplication_Init( void * object )
{
    XSApplication * app;
    
    app = ( XSApplication * )object;
    
    app->args      = XSAlloc( 25 * sizeof( XSApplicationArgumentRef ) );
    app->arg_alloc = 25;
    app->arg_count = 0;
}
 
 /*!
 * @function    __XSApplication_Dealloc
 * @abstract    Destructor
 * @param       object  A pointer to the object
 * @result      void
 */
void __XSApplication_Dealloc( void * object )
{
    XSUInteger      i;
    XSApplication * app;
    
    app = ( XSApplication * )object;
    
    for( i = 0; i < app->arg_count; i++ )
    {
        XSRelease( app->args[ i ] );
    }
    
    XSRelease( app->args );
}

/*!
 * @function    __XSApplication_ProcessArguments
 * @abstract    Processes the command line arguments
 * @param       app     The application object
 * @result      void
 */
void __XSApplication_ProcessArguments( XSApplication * app )
{
    XSInteger                i;
    const char             * name;
    char                   * value;
    XSApplicationArgumentRef arg;
    
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
        
        arg  = XSApplication_GetArgument( ( XSApplicationRef )app, name );
        
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
                    
                default:
                    
                    i++;
                    break;
            }
        }
        
        i++;
    }
}
