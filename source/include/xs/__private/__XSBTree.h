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
 * @file        __XSBTree.h
 * @brief       Private BTree class definitions
 * @author      Jean-David Gadina <macmade@eosgarden.com>
 */

#ifndef ___XS_BTREE_H_
#define ___XS_BTREE_H_
#pragma once

#include "../XSMacros.h"

XS_EXTERN_C_BEGIN

#include "XS.h"

/*!
 * @struct      __XSBTree_Struct
 * @brief       XSBTree class
 */
struct __XSBTree_Struct
{
    XSRuntimeClass            __class;  /*! Runtime class */
    XSObject                  value;    /* ... */
    struct __XSBTree_Struct * left;     /* ... */
    struct __XSBTree_Struct * right;    /* ... */
    struct __XSBTree_Struct * parent;   /* ... */
};

/*!
 * @typedef     __XSBTree
 * @brief       XSBTree class type
 */
typedef struct __XSBTree_Struct __XSBTree;

/*!
 * @brief       Runtime initialization
 * @result      void
 */
void __XSBTree_Initialize( void );

/*!
 * @brief       Destructor
 * @param       object  A pointer to the object
 * @result      void
 */
void __XSBTree_Destruct( XSObject object );

/*!
 * @brief       Object copy
 * @param       source          The source object
 * @param       destination     The destination object
 * @result      void
 */
void __XSBTree_Copy( XSObject source, XSObject destination );

XS_EXTERN_C_END

#endif /* ___XS_BTREE_H_ */
