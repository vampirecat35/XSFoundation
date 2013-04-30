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
 * @file        std-string.h
 * @brief       Definition of the non-standard string functions
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#ifndef _STDC_STD_EXTRAS_STRING_H_
#define _STDC_STD_EXTRAS_STRING_H_
#pragma once

#include "std-keywords.h"

#ifdef __cplusplus
extern "C" {
#endif

#if !defined( _WIN32 ) && !defined( _WIN64 )

/*!
 * @brief       Converts an integer to a string
 * @details     Converts an integer value to a null-terminated string using the
 *              specified base and stores the result in the array given by str
 *              parameter.
 *              If base is 10 and value is negative, the resulting string is
 *              preceded with a minus sign (-). With any other base, value is
 *              always considered unsigned.
 *              str should be an array long enough to contain any possible
 *              value: ( sizeof( int ) * 8 + 1 ) for radix = 2, i.e. 17 bytes
 *              in 16-bits platforms and 33 in 32-bits platforms.
 * @param       n       Value to be converted to a string.
 * @param       s       Array in memory where to store the resulting null-terminated string.
 * @param       radix   Numerical base used to represent the value as a string, between 2 and 16, where 10 means decimal base, 16 hexadecimal, 8 octal, and 2 binary.
 * @result      void
 */
void itoa( int n, char s[], int radix );

#endif

/*!
 * @brief       Converts an unsigned integer to a string
 * @details     Converts an unsigned integer value to a null-terminated string
 *              using the specified base and stores the result in the array
 *              given by str parameter.
 *              If base is 10 and value is negative, the resulting string is
 *              preceded with a minus sign (-). With any other base, value is
 *              always considered unsigned.
 *              str should be an array long enough to contain any possible
 *              value: ( sizeof( unsigned int ) * 8 + 1 ) for radix = 2,
 *              i.e. 17 bytes in 16-bits platforms and 33 in 32-bits platforms.
 * @param       n       Value to be converted to a string.
 * @param       s       Array in memory where to store the resulting null-terminated string.
 * @param       radix   Numerical base used to represent the value as a string, between 2 and 16, where 10 means decimal base, 16 hexadecimal, 8 octal, and 2 binary.
 * @result      void
 */
void utoa( unsigned int n, char s[], int radix );

/*!
 * @brief       Locate substring
 * @details     Returns a pointer to the last occurrence of str2 in str1, or a
 *              null pointer if str2 is not part of str1.
 *              The matching process does not include the terminating
 *              null-characters.
 * @param       s1      C string to be scanned.
 * @param       s2      C string containing the sequence of characters to match.
 * @result      A pointer to the last occurrence in str1 of any of the entire sequence of characters specified in str2, or a null pointer if the sequence is not present in str1.
 */
char * strrstr( char *s1, char * s2 );

#ifdef __cplusplus
}
#endif

#endif /* _STDC_STD_EXTRAS_STRING_H_ */
