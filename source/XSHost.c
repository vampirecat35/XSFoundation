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
 * @header      XSHost.c
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    Implementation for the XSHost class
 */

#include "XS.h"
#include "__XSHost.h"

extern XSClassID __XSHostClassID;

XSStatic XSObject XSHost_Alloc( void )
{
    return ( XSObject )XSRuntime_CreateInstance( __XSHostClassID );
}

XSObject XSHost_Init( XSHost xsThis, XSString host, XSUInteger port )
{
    __XSHost           * _host;
    struct addrinfo      hints;
    struct addrinfo    * infos;
    struct addrinfo    * res;
    void               * ip;
    struct sockaddr_in * ipv4;
    char                 ipstr[ INET6_ADDRSTRLEN ];
    XSString             portstr;
    
    if( xsThis == NULL || host == NULL || port == 0 )
    {
        return xsThis;
    }
    
    portstr = XSString_Init( XSString_Alloc() );
    _host   = ( __XSHost * )xsThis;
    
    XSString_AppendFormat( portstr, ( char * )"%lu", port );
    memset( &hints, 0, sizeof( struct addrinfo ) );
    
    hints.ai_family   = INADDR_ANY;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE;
    
    if( getaddrinfo( XSString_CString( host ), XSString_CString( portstr ), &hints, &infos ) != 0 )
    {
        XSRelease( portstr );
        return xsThis;
    }
    
    for( res = infos; res != NULL; res = infos->ai_next )
    {
        if( res->ai_family == AF_INET )
        {
            ipv4 = ( struct sockaddr_in * )res->ai_addr;
            ip   = &( ipv4->sin_addr );
            
            inet_ntop( res->ai_family, ip, ipstr, INET6_ADDRSTRLEN );
            
            break;
        }
    }
    
    _host->host = XSCopy( host );
    _host->ip   = XSString_InitWithCString( XSString_Alloc(), ipstr );
    _host->port = port;
    
    memcpy( _host->infos, infos, sizeof( struct addrinfo ) );
    memcpy( _host->sock,  ipv4,  sizeof( struct sockaddr_in ) );
        
    XSRelease( portstr );
    freeaddrinfo( infos );
    
    return xsThis;
}

XSObject XSHost_InitWithURL( XSHost xsThis, XSURL url )
{
    return XSHost_Init( xsThis, XSURL_GetDomain( url ), XSURL_GetPort( url ) );
}

XSString XSHost_GetHost( XSHost xsThis )
{
    if( xsThis == NULL )
    {
        return NULL;
    }
    
    return ( ( __XSHost * )xsThis )->host;
}

XSString XSHost_GetIP( XSHost xsThis )
{
    if( xsThis == NULL )
    {
        return NULL;
    }
    
    return ( ( __XSHost * )xsThis )->ip;
}

XSUInteger XSHost_GetPort( XSHost xsThis )
{
    if( xsThis == NULL )
    {
        return 0;
    }
    
    return ( ( __XSHost * )xsThis )->port;
}