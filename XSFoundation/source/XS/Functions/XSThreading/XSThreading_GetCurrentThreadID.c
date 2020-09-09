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

/* $Id$ */

/*!
 * @file        XSThreading_GetCurrentThreadID.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSThreading_GetCurrentThreadID
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSThreading.h>

#ifdef __linux
#include <sys/types.h>
#endif

XSUInteger XSThreading_GetCurrentThreadID( void )
{
    #if defined( _WIN32 )
    
    return ( XSUInteger )GetCurrentThreadId();
    
    #elif defined( __APPLE__ )
    
    return ( XSUInteger )pthread_mach_thread_np( pthread_self() );
    
    #elif defined( __linux )
    
    return ( XSUInteger )gettid();
    
    #elif defined( __unix__ )
    
    return ( XSUInteger )thr_self();
    
    #elif defined( __XEOS__ )
    
    return 0;
    
    #else
    
    return 0;
    
    #endif
}
