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

/* $Id$ */

/*!
 * @file        XSEquals.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSEquals
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSMemory.h>
#include <XS/__private/Functions/XSDebugger.h>
#include <XS/__private/Functions/XSRuntime.h>

XS_EXPORT bool XSEquals( const void * memory1, const void * memory2 )
{
    __XSMemoryObject        * object1;
    __XSMemoryObject        * object2;
    XSClassCallbackEquals equals;
    
    if( memory1 == NULL || memory2 == NULL )
    {
        return false;
    }
    
    object1 = __XSMemory_GetMemoryObject( memory1 );
    object2 = __XSMemory_GetMemoryObject( memory2 );
    
    __XSDebugger_CheckObjectIntegrity( object1 );
    __XSDebugger_CheckObjectIntegrity( object2 );
    
    if( XSRuntime_IsRegisteredClass( object1->classID ) == false || XSRuntime_IsRegisteredClass( object2->classID ) == false )
    {
        return ( object1 == object2 ) ? true : false;
    }
    
    if( object1->classID != object2->classID )
    {
        return false;
    }
    
    equals = __XSRuntime_GetEqualsCallback( object1->classID );
    
    if( equals == NULL )
    {
        return ( object1 == object2 ) ? true : false;
    }
    
    return equals( memory1, memory2 );
}
