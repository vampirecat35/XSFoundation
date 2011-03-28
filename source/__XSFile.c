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
 * @file        
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    
 */

#include "XS.h"
#include "private/__XSFile.h"

static const XSRuntimeClass __XSFileClass =
{
    "XSFile"
};

static XSTypeID __XSFileTypeID;

void __XSFile_Initialize( void )
{
    __XSFileTypeID = XSRuntime_RegisterClass( &__XSFileClass );
}

XSFile * __XSFile_Alloc( void )
{
    return ( XSFile * )XSRuntime_CreateInstance( __XSFileTypeID, sizeof( XSFile ) );
}

void __XSFile_WriteAlign( XSFile * file )
{
    if( file->bit_count > 0 )
    {
        fputc( file->bit_buffer, file->fp );
    }
    
    file->bit_count  = 0;
    file->bit_buffer = 0;
    file->bit_offset = 0;
}

void __XSFile_UpdateStat( XSFile * file )
{
    stat( file->filename, &( file->stat_buf ) );
}
