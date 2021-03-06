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
 * @header      XSMutableString.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSString class
 */

#ifndef XS_CLASSES_XS_MUTABLE_STRING_H
#define XS_CLASSES_XS_MUTABLE_STRING_H

#include <XS/Macros.h>
#include <XS/Types.h>
#include <XS/Classes/XSString.h>

XS_EXTERN_C_BEGIN

/*!
 * @typedef     XSMutableStringRef
 * @abstract    Opaque type for XSString (mutable)
 */
typedef struct XSString * XSMutableStringRef;

/*!
 * @function    XSStringCreateMutable
 * @abstract    Creates an empty mutable string
 * @return      An empty mutable string
 */
XS_EXPORT XSMutableStringRef XSStringCreateMutable( void );

/*!
 * @function    XSStringCreateMutableCopy
 * @abstract    Creates a mutable copy of a string
 * @param       str     The string to copy
 * @return      A mutable copy of the string
 */
XS_EXPORT XSMutableStringRef XSStringCreateMutableCopy( XSStringRef str );

/*!
 * @function    XSStringAppend
 * @abstract    Appends a string to a mutable string
 * @param       str     The mutable string
 * @param       append  The string to append
 */
XS_EXPORT void XSStringAppend( XSMutableStringRef str, XSStringRef append );

/*!
 * @function    XSStringAppendBytes
 * @abstract    Appends bytes to a mutable string
 * @param       str     The mutable string
 * @param       bytes   The bytes to append
 * @param       length  The number of bytes to append
 */
XS_EXPORT void XSStringAppendBytes( XSMutableStringRef str, const uint8_t * bytes, size_t length );

/*!
 * @function    XSStringAppendCString
 * @abstract    Appends a C string to a mutable string
 * @param       str     The mutable string
 * @param       cstr    The C string to append
 */
XS_EXPORT void XSStringAppendCString( XSMutableStringRef str, const char * cstr );

/*!
 * @function    XSStringAppendFormat
 * @abstract    Appends a format string to a mutable string
 * @param       str     The mutable string
 * @param       fmt     The format string
 * @param       ...     Arguments for the format string
 */
XS_EXPORT void XSStringAppendFormat( XSMutableStringRef str, const char * fmt, ... ) XS_FORMAT_ATTRIBUTE( printf, 2, 3 );

/*!
 * @function    XSStringAppendFormatAndArguments
 * @abstract    Appends a format string to a mutable string
 * @param       str     The mutable string
 * @param       fmt     The format string
 * @param       ap      Arguments for the format string
 */
XS_EXPORT void XSStringAppendFormatAndArguments( XSMutableStringRef str, const char * fmt, va_list ap ) XS_FORMAT_ATTRIBUTE( printf, 2, 0 );

XS_EXTERN_C_END

#endif /* XS_CLASSES_XS_MUTABLE_STRING_H */
