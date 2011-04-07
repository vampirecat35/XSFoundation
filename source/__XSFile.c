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
 * @file        __XSFile.c
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    ...
 */

#include "XS.h"
#include "__XSFile.h"

/*!
 * @var         __XSFileClass
 * @abstract    Runtime class definition
 */
static const XSClassInfos __XSFileClass =
{
    "XSFile",           /* Class name */
    sizeof( XSFile ),   /* Object size */
    NULL,               /* Constructor */
    NULL,               /* Destructor */
    NULL,               /* Object copy */
    NULL,               /* Object description */
    NULL,               /* Object comparison */
    NULL                /* Object hash */
};

/*!
 * @var         __XSFileClassID
 * @abstract    Type ID for the runtine class
 */
static XSClassID __XSFileClassID;

/*!
 * @function    __XSFile_Initialize
 * @abstract    Runtime initialization
 * @result      void
 */
void __XSFile_Initialize( void )
{
    __XSFileClassID = XSRuntime_RegisterClass( &__XSFileClass );
}

/*!
 * @function    __XSFile_Alloc
 * @abstract    Object allocator
 * @result      A pointer to the allocated object
 */
__XSFile * __XSFile_Alloc( void )
{
    return ( __XSFile * )XSRuntime_CreateInstance( __XSFileClassID );
}

/*!
 * @function    __XSFile_WriteAlign
 * @abstract    Aligns and write the bit buffer
 * @param       file    The file object
 * @result      void
 */
void __XSFile_WriteAlign( __XSFile * file )
{
    if( file->bit_count > 0 )
    {
        fputc( file->bit_buffer, file->fp );
    }
    
    file->bit_count  = 0;
    file->bit_buffer = 0;
    file->bit_offset = 0;
}

/*!
 * @function    __XSFile_UpdateStat
 * @abstract    Updates stat informations for the file
 * @param       file    The file object
 * @result      void
 */
void __XSFile_UpdateStat( __XSFile * file )
{
    stat( file->filename, &( file->stat_buf ) );
}
