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
 * @header      XSClassCallbackDestructor.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSClassCallbackDestructor type definition
 */

#ifndef XS_TYPES_XS_CLASS_CALLBACK_DESTRUCTOR_H
#define XS_TYPES_XS_CLASS_CALLBACK_DESTRUCTOR_H

#include <XS/Macros.h>
#include <XS/Types/XSObjectRef.h>

XS_EXTERN_C_BEGIN

/*!
 * @typedef     XSClassCallbackDestructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
typedef void ( *XSClassCallbackDestructor )( XSMutableObjectRef object );

XS_EXTERN_C_END

#endif /* XS_TYPES_XS_CLASS_CALLBACK_DESTRUCTOR_H */
