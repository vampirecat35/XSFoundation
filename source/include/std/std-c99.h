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
 * @file        std-c99.h
 * @brief       Inclusion of the full C99 header files
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#ifndef _XS_STD_C99_H_
#define _XS_STD_C99_H_
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <assert.h>     /* Diagnostics. */
#include <ctype.h>      /* Character class tests. */
#include <errno.h>      /* Error codes reported by (some) library functions. */
#include <float.h>      /* Implementation-defined floating-point limits. */
#include <iso646.h>     /* Programming in ISO 646 variant character sets. */
#include <limits.h>     /* Implementation-defined limits. */
#include <locale.h>     /* Locale-specific information. */
#include <math.h>       /* Mathematical functions. */
#include <setjmp.h>     /* Non-local jumps. */
#include <signal.h>     /* Signals. */
#include <stdarg.h>     /* Variable argument lists. */
#include <stddef.h>     /* Definitions of general use. */
#include <stdint.h>     /* Definition of various integer types. */
#include <stdio.h>      /* Input and output. */
#include <stdlib.h>     /* Utility functions. */
#include <string.h>     /* String functions. */
#include <time.h>       /* Time and date functions. */
#include <wchar.h>      /* Manipulation of wide streams and several kinds of strings using wide characters. */
#include <wctype.h>     /* Wide characters classification. */

#ifndef _WIN32

#include <complex.h>    /* Complex numbers manupilations. */
#include <fenv.h>       /* Control of floating-point environment. */
#include <inttypes.h>   /* Precise conversion between integer types. */
#include <stdbool.h>    /* Boolean data type. */
#include <tgmath.h>     /* Type-generic mathematical functions. */

#endif

#ifdef __cplusplus
}
#endif

#endif /* _XS_STD_C99_H_ */
