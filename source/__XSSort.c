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
 * @file        __XSSort.c
 * @brief       Private implementation of the sort functions
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include "XS.h"
#include "__XSSort.h"

#define __XS_SHELL_SORT( values, size )                 \
    XSInteger i;                                        \
    XSInteger j;                                        \
    XSInteger k;                                        \
    XSInteger n;                                        \
                                                        \
    n = ( XSInteger )size;                              \
                                                        \
    for( k = n / 2; k > 0; k /= 2)                      \
    {                                                   \
        for( j = k; j < n; j++ )                        \
        {                                               \
            for( i = j - k; i >= 0; i -= k )            \
            {                                           \
                if( values[ i + k ] >= values[ i ] )    \
                {                                       \
                    break;                              \
                }                                       \
                else                                    \
                {                                       \
                    value           = values[ i ];      \
                    values[ i ]     = values[ i + k ];  \
                    values[ i + k ] = value;            \
                }                                       \
            }                                           \
        }                                               \
    }

void __XSShellSortChar( char * values, XSUInteger size )
{
    char value;
    
    __XS_SHELL_SORT( values, size )
}

void __XSShellSortUChar( unsigned char * values, XSUInteger size )
{
    unsigned char value;
    
    __XS_SHELL_SORT( values, size )
}

void __XSShellSortShort( short * values, XSUInteger size )
{
    short value;
    
    __XS_SHELL_SORT( values, size )
}

void __XSShellSortUShort( unsigned short * values, XSUInteger size )
{
    unsigned short value;
    
    __XS_SHELL_SORT( values, size )
}

void __XSShellSortInt( int * values, XSUInteger size )
{
    int value;
    
    __XS_SHELL_SORT( values, size )
}

void __XSShellSortUInt( unsigned int * values, XSUInteger size )
{
    unsigned int value;
    
    __XS_SHELL_SORT( values, size )
}

void __XSShellSortLong( long * values, XSUInteger size )
{
    long value;
    
    __XS_SHELL_SORT( values, size )
}

void __XSShellSortULong( unsigned long * values, XSUInteger size )
{
    unsigned long value;
    
    __XS_SHELL_SORT( values, size )
}

void __XSShellSortLongLong( long long * values, XSUInteger size )
{
    long long value;
    
    __XS_SHELL_SORT( values, size )
}

void __XSShellSortULongLong( unsigned long long * values, XSUInteger size )
{
    unsigned long long value;
    
    __XS_SHELL_SORT( values, size )
}

void __XSShellSortFloat( float * values, XSUInteger size )
{
    float value;
    
    __XS_SHELL_SORT( values, size )
}

void __XSShellSortDouble( double * values, XSUInteger size )
{
    double value;
    
    __XS_SHELL_SORT( values, size )
}

void __XSShellSortInteger( XSInteger * values, XSUInteger size )
{
    XSInteger value;
    
    __XS_SHELL_SORT( values, size )
}

void __XSShellSortUInteger( XSUInteger * values, XSUInteger size )
{
    XSUInteger value;
    
    __XS_SHELL_SORT( values, size )
}
