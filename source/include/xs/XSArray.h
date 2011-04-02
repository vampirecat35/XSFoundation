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
 * @header      XSArray.h
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    ...
 */

#ifndef _XS_ARRAY_H_
#define _XS_ARRAY_H_
#pragma once

#include "XSMacros.h"

XS_EXTERN_C_BEGIN

/*!
 * @define      __XSARRAY_DEFAULT_CAPACITY
 * @abstract    Default capacity for the empty arrays
 */
#define XSARRAY_DEFAULT_CAPACITY    256

/*!
 * @typedef     XSArrayRef
 * @abstract    Opaque type for the XSArray objects
 */
typedef struct XSArray * XSArrayRef;

/*!
 * @function    XSArray_Create
 * @abstract    Creates an empty array
 * @result      The array object
 */
XSArrayRef XSArray_Create( void );

/*!
 * @function    XSArray_CreateWithCapacity
 * @abstract    Creates an empty array with an initial capacity
 * @param       capacity    The initial array capacity
 * @result      The array object
 */
XSArrayRef XSArray_CreateWithCapacity( XSUInteger capacity );

/*!
 * @function    XSArray_CreateWithValues
 * @abstract    Creates an array by inserting values.
 * @param       value1  The first value to insert
 * @param       ...     The values to insert. Must be terminated by a NULL fence
 * @result      The array object
 */
XSArrayRef XSArray_CreateWithValues( void * value1, ... );

/*!
 * @function    XSArray_Count
 * @abstract    Gets the number of values in the array
 * @description The inserted value will be automatically retained.
 * @param       array   The array object
 * @result      The number of values in the array
 */
XSUInteger XSArray_Count( XSArrayRef array );

/*!
 * @function    XSArray_AppendValue
 * @abstract    Appends a value at the end of the array.
 * @description The appended value will be automatically retained.
 * @param       array   The array object
 * @param       The value to append
 * @result      void
 */
void XSArray_AppendValue( XSArrayRef array, void * value );

/*!
 * @function    XSArray_InsertValueAtIndex
 * @abstract    Insert a value at a specific index
 * @description The inserted value will be automatically retained.
 * @param       array   The array object
 * @param       value   The value to insert
 * @param       i       The index in the array
 * @result      void
 */
void XSArray_InsertValueAtIndex( XSArrayRef array, void * value, XSUInteger i );

/*!
 * @function    XSArray_ReplaceValueAtIndex
 * @abstract    Replace the value at a specific index with a new value
 * @description The new value will be automatically retained, and the old value
 *              will be released.
 * @param       array   The array object
 * @param       value   The value to insert
 * @param       i       The index in the array
 * @result      The old value
 */
void * XSArray_ReplaceValueAtIndex( XSArrayRef array, void * value, XSUInteger i );

/*!
 * @function    XSArray_ValueAtIndex
 * @abstract    Gets the value at a specific index
 * @param       array   The array object
 * @param       i       The index in the array
 * @result      The array value
 */
void * XSArray_ValueAtIndex( XSArrayRef array, XSUInteger i );

/*!
 * @function    XSArray_RemoveValueAtIndex
 * @abstract    Removes a value at a specific index
 * @description The removed value will be released
 * @param       array   The array object
 * @param       i       The index in the array
 * @result      The removed value
 */
void * XSArray_RemoveValueAtIndex( XSArrayRef array, XSUInteger i );

/*!
 * @function    XSArray_ContainsValue
 * @abstract    Checks if the array contains a specific value
 * @param       array   The array object
 * @param       value   The value to search
 * @result      YES if the array contains the value, otherwise NO
 */
BOOL XSArray_ContainsValue( XSArrayRef array, void * value );

/*!
 * @function    XSArray_Index
 * @abstract    Gets the current array index
 * @param       array   The array object
 * @result      The current array index
 */
XSUInteger XSArray_Index( XSArrayRef array );

/*!
 * @function    XSArray_Current
 * @abstract    Gets the current array value
 * @param       array   The array object
 * @result      The current array value
 */
void * XSArray_Current( XSArrayRef array );

/*!
 * @function    XSArray_Next
 * @abstract    Increases the internal value pointer and returns the value
 * @param       array   The array object
 * @result      The array value
 */
void * XSArray_Next( XSArrayRef array );

/*!
 * @function    XSArray_Previous
 * @abstract    Decrease the internal value pointer and returns the value
 * @param       array   The array object
 * @result      The array value
 */
void * XSArray_Previous( XSArrayRef array );

/*!
 * @function    XSArray_Rewind
 * @abstract    Sets the internal value pointer to the first value in the array
 * @param       array   The array object
 * @result      void
 */
void XSArray_Rewind( XSArrayRef array );

XS_EXTERN_C_END

#endif /* _HEADER_H_ */
