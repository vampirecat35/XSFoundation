/*******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2020 Jean-David Gadina - www.xs-labs.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

/*!
 * @file        XSTLSSetValue.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSTLSSetValue
 */

#include <XS/XS.h>
#include <XS/Private/Types/XSTLSValue.h>

#ifdef _WIN32
#include <XS/Private/Windows.h>
#else
#include <pthread.h>
#endif

void XSTLSSetValue( XSTLSKey * key, void * data, XSObjectAssociation association )
{
    struct XSTLSValue * tls;

    if( key == NULL )
    {
        return;
    }

#ifdef _WIN32
    tls = TlsGetValue( *( key ) );
#else
    tls = pthread_getspecific( *( key ) );
#endif

    if( tls != NULL )
    {
        if( tls->association == XSObjectAssociationRetain || tls->association == XSObjectAssociationCopy )
        {
            XSRelease( tls->value );
        }

        tls->value       = NULL;
        tls->association = XSObjectAssociationAssign;
    }
    else if( data != NULL )
    {
        tls = XSAlloc( sizeof( struct XSTLSValue ) );

        if( tls == NULL )
        {
            XSBadAlloc();
        }
    }

    if( data == NULL )
    {
        XSRelease( tls );

        tls = NULL;
    }
    else
    {
        if( association == XSObjectAssociationRetain )
        {
            data = XSRetain( data );
        }
        else if( association == XSObjectAssociationCopy )
        {
            data = XSCopy( data );
        }

        tls->association = association;
        tls->value       = data;
    }

#ifdef _WIN32
    TlsSetValue( *( key ), tls );
#else
    pthread_setspecific( *( key ), tls );
#endif
}
