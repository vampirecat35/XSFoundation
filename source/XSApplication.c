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
 * @file        XSApplication.c
 * @brief       Implementation for the XSApplication class
 * @author      Jean-David Gadina <macmade@eosgarden.com>
 */

#include "XS.h"
#include "__XSApplication.h"

extern XSClassID __XSApplicationClassID;

static __XSApplication    * __xsapp = NULL;
static XSAutoreleasePool    __xsarp = NULL;
static BOOL __xsapp_argv_processed  = NO;

struct XSExceptionContext_Struct   __XSExceptionContext;
struct XSExceptionContext_Struct * XSExceptionContext;

XSStatic XSApplication XSApplication_Alloc( void )
{
    return ( XSObject )XSRuntime_CreateInstance( __XSApplicationClassID );
}

XSObject XSApplication_Init( XSObject xsThis )
{
    return xsThis;
}

XSStatic XSApplication XSApplication_Start( int argc, const char ** argv )
{
    #ifdef _WIN32
    WSADATA wsaData;
    #endif
    
    XSExceptionContext        = &__XSExceptionContext;
    XSExceptionContext->e_env = 0;
    
    XSRuntime_Initialize();
    
    __xsapp = ( __XSApplication * )XSApplication_Init( XSApplication_Alloc() );
    __xsarp = XSAutoreleasePool_Init( XSAutoreleasePool_Alloc() );
    
    __xsapp->argc       = argc - 1;
    __xsapp->argv       = argv + 1;
    __xsapp->executable = argv[ 0 ];
    
    XSNotificationCenter_DefaultCenter();
    
    #ifdef _WIN32
    WSAStartup( MAKEWORD( 2, 0 ), &wsaData );
    #endif
    
    return ( XSApplication )__xsapp;
}

XSStatic void XSApplication_Exit( void )
{
    XSRelease( __xsarp );
    XSRelease( __xsapp );
    XSRelease( XSNotificationCenter_DefaultCenter() );
    XSRelease( XSNull_Null() );
    
    __xsarp = NULL;
    __xsapp = NULL;
    
    #ifdef _WIN32
    WSACleanup();
    #endif
    
    pthread_exit( NULL );
}

XSStatic XSApplication XSApplication_SharedApplication( void )
{
    return ( XSApplication )__xsapp;
}

void XSApplication_PrintHelp( XSApplication xsThis, const char * description )
{
    const char          * exec;
    const char          * help;
    __XSApplication     * _app;
    XSApplicationArgument arg;
    XSUInteger            i;
    
    if( xsThis == NULL )
    {
        return;
    }
    
    _app = ( __XSApplication * )xsThis;
    
    if( NULL == ( exec = strrchr( _app->executable, '/' ) ) )
    {
        exec = _app->executable;
    }
    else
    {
        exec++;
    }
    
    printf( "#----------------------------------------------------------------------------------------------------------------------\n" );
    printf( "# %s - %s\n", exec, description );
    printf( "#----------------------------------------------------------------------------------------------------------------------\n" );
    
    if( _app->arg_count > 0 )
    {
        printf( "# \n#    Arguments:\n# \n" );
        
        for( i = 0; i < _app->arg_count; i++ )
        {
            arg = _app->args[ i ];
            
            printf( "#    %s ", XSApplicationArgument_GetName( arg ) );
            
            switch( XSApplicationArgument_GetType( arg ) )
            {
                case XSApplicationArgumentTypeFlag:
                    
                    printf( "\n" );
                    break;
                    
                case XSApplicationArgumentTypeInteger:
                    
                    printf( "[ integer ]\n" );
                    break;
                    
                case XSApplicationArgumentTypeUnsignedInteger:
                    
                    printf( "[ positive integer ]\n" );
                    break;
                    
                case XSApplicationArgumentTypeString:
                    
                    printf( "[ string ]\n" );
                    break;
                    
                case XSApplicationArgumentTypeFloat:
                    
                    printf( "[ float ]\n" );
                    break;
                    
                default:
                    
                    printf( "[ value ]\n" );
                    break;
            }
            
            if( NULL == ( help = XSApplicationArgument_GetHelp( arg ) ) )
            {
                printf( "#    No description available\n# \n" );
            }
            else
            {
                printf( "#    %s\n# \n", help );
            }
        }
    
        printf( "#----------------------------------------------------------------------------------------------------------------------\n" );
    }
}

void XSApplication_RegisterArgument( XSApplication xsThis, const char * name, XSApplicationArgumentType type, const char * help )
{
    __XSApplication     * _app;
    XSApplicationArgument arg;
    
    if( xsThis == NULL )
    {
        return;
    }
    
    _app = ( __XSApplication * )xsThis;
    arg  = XSApplicationArgument_Init( XSApplicationArgument_Alloc(), name, type, help );
    
    if( _app->arg_count == _app->arg_alloc )
    {
        XSRealloc( _app->args, _app->arg_count + 25 );
        
        _app->arg_alloc += 25;
    }
    
    _app->args[ _app->arg_count++ ] = arg;
}

XSApplicationArgument XSApplication_GetArgument( XSApplication xsThis, const char * name )
{
    XSUInteger        i;
    __XSApplication * _app;
    
    if( xsThis == NULL )
    {
        return NULL;
    }
    
    _app = ( __XSApplication * )xsThis;
    
    for( i = 0; i < _app->arg_count; i++ )
    {
        if( strcmp( name, XSApplicationArgument_GetName( _app->args[ i ] ) ) == 0 )
        {
            return _app->args[ i ];
        }
    }
    
    return NULL;
}

BOOL XSApplication_HasArgument( XSApplication xsThis, const char * name )
{
    if( xsThis == NULL )
    {
        return NO;
    }
    
    if( __xsapp_argv_processed == NO )
    {
        __XSApplication_ProcessArguments( ( __XSApplication * )xsThis );
        
        __xsapp_argv_processed = YES;
    }
    
    return XSApplication_GetArgument( xsThis, name ) != NULL;
}

BOOL XSApplication_GetFlag( XSApplication xsThis, const char * name )
{
    XSApplicationArgument arg;
    
    if( xsThis == NULL )
    {
        return NO;
    }
    
    if( __xsapp_argv_processed == NO )
    {
        __XSApplication_ProcessArguments( ( __XSApplication * )xsThis );
        
        __xsapp_argv_processed = YES;
    }
    
    arg  = XSApplication_GetArgument( xsThis, name );
    
    if( arg == NULL )
    {
        return NO;
    }
    
    return XSApplicationArgument_GetFlag( arg );
}

XSInteger XSApplication_GetInteger( XSApplication xsThis, const char * name )
{
    XSApplicationArgument arg;
    
    if( xsThis == NULL )
    {
        return 0;
    }
    
    if( __xsapp_argv_processed == NO )
    {
        __XSApplication_ProcessArguments( ( __XSApplication * )xsThis );
        
        __xsapp_argv_processed = YES;
    }
        
    arg  = XSApplication_GetArgument( xsThis, name );
    
    if( arg == NULL )
    {
        return 0;
    }
    
    return XSApplicationArgument_GetIntegerValue( arg );
}

XSUInteger XSApplication_GetUnsignedInteger( XSApplication xsThis, const char * name )
{
    XSApplicationArgument arg;
    
    if( xsThis == NULL )
    {
        return 0;
    }
    
    if( __xsapp_argv_processed == NO )
    {
        __XSApplication_ProcessArguments( ( __XSApplication * )xsThis );
        
        __xsapp_argv_processed = YES;
    }
    
    arg  = XSApplication_GetArgument( xsThis, name );
    
    if( arg == NULL )
    {
        return 0;
    }
    
    return XSApplicationArgument_GetUnsignedIntegerValue( arg );
}

XSString XSApplication_GetString( XSApplication xsThis, const char * name )
{
    XSApplicationArgument arg;
    
    if( xsThis == NULL )
    {
        return NULL;
    }
    
    if( __xsapp_argv_processed == NO )
    {
        __XSApplication_ProcessArguments( ( __XSApplication * )xsThis );
        
        __xsapp_argv_processed = YES;
    }
    
    arg  = XSApplication_GetArgument( xsThis, name );
    
    if( arg == NULL || XSApplicationArgument_GetStringValue( arg ) == NULL )
    {
        return NULL;
    }
    
    return XSSTR( ( char * )XSApplicationArgument_GetStringValue( arg ) );
}

XSFloat XSApplication_GetFloat( XSApplication xsThis, const char * name )
{
    XSApplicationArgument arg;
    
    if( xsThis == NULL )
    {
        return 0;
    }
    
    if( __xsapp_argv_processed == NO )
    {
        __XSApplication_ProcessArguments( ( __XSApplication * )xsThis );
        
        __xsapp_argv_processed = YES;
    }
        
    arg  = XSApplication_GetArgument( xsThis, name );
    
    if( arg == NULL )
    {
        return 0;
    }
    
    return XSApplicationArgument_GetFloatValue( arg );
}

XSAutoreleased XSArray XSApplication_GetUnnamedArguments( XSApplication xsThis )
{
    XSApplication * _app;
    
    if( xsThis == NULL )
    {
        return NULL;
    }
    
    _app = ( XSApplication * )xsThis;
    
    return NULL;
}