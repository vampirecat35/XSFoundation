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
 * @file        XSAtomicCompareAndSwap32.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSAtomicCompareAndSwap32
 */

#include <XS/XS.h>

#if defined( __XEOS__ )

#include <system.h>

/* XEOS */
bool XSAtomicCompareAndSwap32( int32_t oldValue, int32_t newValue, volatile int32_t * value )
{
    return System_Atomic_CompareAndSwap32( oldValue, newValue, value );
}

#elif defined( _WIN32 )

#include <XS/Private/Windows.h>

/* Windows */
bool XSAtomicCompareAndSwap32( int32_t oldValue, int32_t newValue, volatile int32_t * value )
{
    return InterlockedCompareExchange( ( volatile LONG * )value, newValue, oldValue ) == oldValue;
}

#elif defined( __APPLE__ )

#include <libkern/OSAtomic.h>

#pragma clang diagnostic ignored "-Wdeprecated-declarations"

/* macOS */
bool XSAtomicCompareAndSwap32( int32_t oldValue, int32_t newValue, volatile int32_t * value )
{
    return OSAtomicCompareAndSwap32Barrier( oldValue, newValue, value );
}

#elif defined( __linux )

/* Linux */
bool XSAtomicCompareAndSwap32( int32_t oldValue, int32_t newValue, volatile int32_t * value )
{
    int32_t old = oldValue;

    return __atomic_compare_exchange( value, &old, &newValue, false, __ATOMIC_ACQ_REL, __ATOMIC_RELEASE );
}

#else

#error "Platform not implemented"

#endif
