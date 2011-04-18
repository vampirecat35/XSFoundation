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
 * @header      XSBtree.h
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    XSBtree class functions
 */

#ifndef _XS_BTREE_H_
#define _XS_BTREE_H_
#pragma once

#include "XSMacros.h"

XS_EXTERN_C_BEGIN

/*!
 * @typedef     XSBTree
 * @abstract    Opaque type for the XSBTree objects
 */
typedef struct __XSBTree * XSBTree;

/*!
 * @function    XSBTree_Alloc
 * @abstract    Object allocator
 * @result      The allocated object
 */
XSStatic XSObject XSBTree_Alloc( void );

XSObject XSBTree_Init( XSObject xsThis );

XSAutoreleased XSBTree XSBTree_GetLeft( XSBTree xsThis );

XSAutoreleased XSBTree XSBTree_GetRight( XSBTree xsThis );

XSAutoreleased XSBTree XSBTree_GetParent( XSBTree xsThis );

XSAutoreleased XSBTree XSBTree_CreateLeft( XSBTree xsThis, void * value );

XSAutoreleased XSBTree XSBTree_CreateRight( XSBTree xsThis, void * value );

void XSBTree_SetLeft( XSBTree xsThis, XSBTree left );

void XSBTree_SetRight( XSBTree xsThis, XSBTree right );

void XSBTree_SetParent( XSBTree xsThis, XSBTree parent );

XSAutoreleased void * XSBTree_GetValue( XSBTree xsThis );

XSAutoreleased XSBTree XSBTree_GetRoot( XSBTree xsThis );

XSUInteger XSBTree_GetDepth( XSBTree xsThis );

XSAutoreleased XSBTree * XSBTree_GetLeafs( XSBTree xsThis );

BOOL XSBtree_IsLeaf( XSBTree xsThis );

BOOL XSBtree_IsNode( XSBTree xsThis );

BOOL XSBtree_IsRoot( XSBTree xsThis );

XS_EXTERN_C_END

#endif /* _XS_BTREE_H_ */
