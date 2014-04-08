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

/*!
 * @header      XSError.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSError class
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_CLASSES_XS_ERROR_H__
#define __XS_CLASSES_XS_ERROR_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>
#include <XS/Classes/XSString.h>
#include <XS/Classes/XSDictionary.h>

/*!
 * @typedef     XSErrorRef
 * @abstract    Opaque type for XSError
 */
typedef struct __XSError * XSErrorRef;

/*!
 * @function    XSError_GetClassID
 * @abstract    Gets the class ID for XSError
 * @return      The class ID for XSError
 */
XS_EXPORT XSStatic XSClassID XSError_GetClassID( void );

/*!
 * @function    XSError_Error
 * @abstract    Gets an error object
 * @param       domain      The error domain
 * @param       code        The error code
 * @param       reason      The error reason
 * @param       userInfo    The error user infos
 * @return      The error object
 */
XS_EXPORT XSStatic XSAutoreleased XSErrorRef XSError_Error( XSStringRef domain, XSInteger code, XSStringRef reason, XSDictionaryRef userInfo );

/*!
 * @function    XSError_Create
 * @abstract    Creates an error object
 * @param       domain      The error domain
 * @param       code        The error code
 * @param       reason      The error reason
 * @param       userInfo    The error user infos
 * @return      The error object
 */
XS_EXPORT XSStatic XSErrorRef XSError_Create( XSStringRef domain, XSInteger code, XSStringRef reason, XSDictionaryRef userInfo );

/*!
 * @function    XSError_GetDomain
 * @abstract    Gets the error domain
 * @param       error       The error object
 * @return      The error domain
 */
XS_EXPORT XSStringRef XSError_GetDomain( XSErrorRef error );

/*!
 * @function    XSError_GetCode
 * @abstract    Gets the error code
 * @param       error       The error object
 * @return      The error code
 */
XS_EXPORT XSInteger XSError_GetCode( XSErrorRef error );

/*!
 * @function    XSError_GetReason
 * @abstract    Gets the error reason
 * @param       error       The error object
 * @return      The error reason
 */
XS_EXPORT XSStringRef XSError_GetReason( XSErrorRef error );

/*!
 * @function    XSError_GetUserInfo
 * @abstract    Gets the error user infos
 * @param       error       The error object
 * @return      The error user infos
 */
XS_EXPORT XSDictionaryRef XSError_GetUserInfo( XSErrorRef error );

#endif /* __XS_CLASSES_XS_ERROR_H__ */
