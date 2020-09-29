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
 * @file        XSStringCreateWithCStringNoCopy.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( XSString, XSStringCreateWithCStringNoCopy )
{
    const char * cp1  = "";
    const char * cp2  = "hello, world";
    XSStringRef  str1 = XSStringCreateWithCStringNoCopy( cp1 );
    XSStringRef  str2 = XSStringCreateWithCStringNoCopy( cp2 );
    XSStringRef  str3 = XSStringCreateWithCStringNoCopy( NULL );

    AssertTrue( str1 != NULL );
    AssertTrue( str2 != NULL );
    AssertTrue( str3 != NULL );

    AssertEqual( XSStringGetLength( str1 ), 0u );
    AssertEqual( XSStringGetLength( str2 ), 12u );
    AssertEqual( XSStringGetLength( str3 ), 0u );

    AssertStringEqual( XSStringGetCString( str2 ), "hello, world" );

    AssertTrue( XSStringGetCString( str1 ) == cp1 );
    AssertTrue( XSStringGetCString( str2 ) == cp2 );
    AssertTrue( XSStringGetCString( str3 ) != NULL );

    XSRelease( str1 );
    XSRelease( str2 );
    XSRelease( str3 );
}

Test( XSString, XSStringCreateWithCStringNoCopy_LongString )
{
    const char * cp1  = "";
    const char * cp2  = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat.";
    XSStringRef  str1 = XSStringCreateWithCStringNoCopy( cp1 );
    XSStringRef  str2 = XSStringCreateWithCStringNoCopy( cp2 );
    XSStringRef  str3 = XSStringCreateWithCStringNoCopy( NULL );

    AssertTrue( str1 != NULL );
    AssertTrue( str2 != NULL );
    AssertTrue( str3 != NULL );

    AssertEqual( XSStringGetLength( str1 ), 0u );
    AssertEqual( XSStringGetLength( str2 ), 144u );
    AssertEqual( XSStringGetLength( str3 ), 0u );

    AssertStringEqual( XSStringGetCString( str2 ), "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat." );

    AssertTrue( XSStringGetCString( str1 ) == cp1 );
    AssertTrue( XSStringGetCString( str2 ) == cp2 );
    AssertTrue( XSStringGetCString( str3 ) != NULL );

    XSRelease( str1 );
    XSRelease( str2 );
    XSRelease( str3 );
}
