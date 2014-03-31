/*******************************************************************************
 * XSFoundation - XEOS C Foundation Library
 * 
 * Copyright (c) 2010-2014, Jean-David Gadina - www.xs-labs.com
 * All rights reserved.
 * 
 * XEOS Software License - Version 1.0 - December 21, 2012
 * 
 * Permission is hereby granted, free of charge, to any person or organisation
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to deal in the Software, with or without
 * modification, without restriction, including without limitation the rights
 * to use, execute, display, copy, reproduce, transmit, publish, distribute,
 * modify, merge, prepare derivative works of the Software, and to permit
 * third-parties to whom the Software is furnished to do so, all subject to the
 * following conditions:
 * 
 *      1.  Redistributions of source code, in whole or in part, must retain the
 *          above copyright notice and this entire statement, including the
 *          above license grant, this restriction and the following disclaimer.
 * 
 *      2.  Redistributions in binary form must reproduce the above copyright
 *          notice and this entire statement, including the above license grant,
 *          this restriction and the following disclaimer in the documentation
 *          and/or other materials provided with the distribution, unless the
 *          Software is distributed by the copyright owner as a library.
 *          A "library" means a collection of software functions and/or data
 *          prepared so as to be conveniently linked with application programs
 *          (which use some of those functions and data) to form executables.
 * 
 *      3.  The Software, or any substancial portion of the Software shall not
 *          be combined, included, derived, or linked (statically or
 *          dynamically) with software or libraries licensed under the terms
 *          of any GNU software license, including, but not limited to, the GNU
 *          General Public License (GNU/GPL) or the GNU Lesser General Public
 *          License (GNU/LGPL).
 * 
 *      4.  All advertising materials mentioning features or use of this
 *          software must display an acknowledgement stating that the product
 *          includes software developed by the copyright owner.
 * 
 *      5.  Neither the name of the copyright owner nor the names of its
 *          contributors may be used to endorse or promote products derived from
 *          this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT OWNER AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE, TITLE AND NON-INFRINGEMENT ARE DISCLAIMED.
 * 
 * IN NO EVENT SHALL THE COPYRIGHT OWNER, CONTRIBUTORS OR ANYONE DISTRIBUTING
 * THE SOFTWARE BE LIABLE FOR ANY CLAIM, DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN ACTION OF CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF OR IN CONNECTION WITH
 * THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

/* $Id$ */

#include <XS/XS.h>

int main( int argc, const char * argv[] )
{
    ( void )argc;
    ( void )argv;
    
    XSRuntime_Initialize();
    
    {
        void * x1;
        void * x2;
        
        x1 = XSAlloc( 10 );
        x2 = XSAlloc( 100 );
        
        XSRelease( x1 );
        XSRetain( x2 );
        XSRetain( x2 );
        XSRelease( x2 );
        XSRelease( x2 );
        XSRelease( x2 );
    }
    
    {
        XSBooleanRef bool1;
        XSBooleanRef bool2;
        XSBooleanRef bool3;
        
        bool1 = XSBoolean_Create( true );
        bool2 = XSCopy( bool1 );
        bool3 = XSBoolean_Create( false );
        
        XSLog( "bool1: %p", bool1 );
        XSLog( "bool2: %p", bool2 );
        XSLog( "bool3: %p", bool3 );
        
        XSLog( "bool1: %s", XSRuntime_GetDescription( bool1 ) );
        XSLog( "bool2: %s", XSRuntime_GetDescription( bool2 ) );
        XSLog( "bool3: %s", XSRuntime_GetDescription( bool3 ) );
        
        if( XSEquals( bool1, bool2 ) )
        {
            XSLog( "bool1 == bool2" );
        }
        else
        {
            XSLog( "bool1 != bool2" );
        }
        
        if( XSEquals( bool1, bool3 ) )
        {
            XSLog( "bool1 == bool3" );
        }
        else
        {
            XSLog( "bool1 != bool3" );
        }
        
        XSRelease( bool1 );
        XSRelease( bool2 );
        XSRelease( bool3 );
    }
    
    XSInteger x;
    
    x = 42;
    
    XSAtomic_IncrementInteger( &x );
    
    XSLog( "%li", ( long )x );
    
    XSAtomic_AddInteger( 42, &x );
    
    XSLog( "%li", ( long )x );
    XSLog( "%li", ( long )XSAtomic_ReadInteger( &x ) );
    
    XSLog( "%lu", ( unsigned long )XSProcess_GetProcessID() );
    XSLog( "%s", XSProcess_GetProcessName() );
    
    {
        XSBooleanRef b;
        XSTLSKey     k;
        
        b = XSBoolean_Create( true );
        
        XSLog( "%p", b );
        XSThreading_TLSKeyCreate( &k );
        XSThreading_TLSSetObject( &k, b, XSTLSObjectAssociationRetain );
        XSRelease( b );
        XSLog( "%p", XSThreading_TLSGetObject( &k ) );
        XSLog( "%s", XSRuntime_GetDescription( XSThreading_TLSGetObject( &k ) ) );
        XSThreading_TLSSetObject( &k, NULL, XSTLSObjectAssociationRetain );
        XSLog( "%p", XSThreading_TLSGetObject( &k ) );
    }
    
    return 0;
}

