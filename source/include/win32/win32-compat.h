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
 * @header      compat.h
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    Compatibility macros and functions for Windows
 */

#ifndef _XS_WIN32_COMPAT_H_
#define _XS_WIN32_COMPAT_H_
#pragma once

#ifdef __cplusplus
extern "C" {
#endif


#ifndef _CRT_SECURE_NO_WARNINGS

/*!
 * @define      _CRT_SECURE_NO_WARNINGS
 * @abstract    Do not warn about stupid Microsoft "security enhancements"
 * @discussion  Microsoft provides "security" enhanced version of standard
 *              C library functions, like sprintf, intended to prevent buffer
 *              overflows. Defining this macro turns off thos annoying
 *              warnings in VisualStudio. If you don't know what you are
 *              doing, then keep on coding C# or Java.
 */
#define _CRT_SECURE_NO_WARNINGS

#endif

#ifdef __cplusplus
}
#endif

#endif /* _XS_WIN32_COMPAT_H_ */
