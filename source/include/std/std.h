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
 * @file        std.h
 * @brief       C standardization
 * @author      Jean-David Gadina <macmade@eosgarden.com>
 */

#ifndef _XS_STD_H__
#define _XS_STD_H__
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "std-c99.h"

#ifdef _WIN32
    
    #include <Winsock2.h>
    #include <Ws2tcpip.h>
    #include <windows.h>
    #include "win32.h"
    
#else
    
    #include "std-posix.h"
    #include <sys/socket.h>
    #include <netdb.h>
    #include <arpa/inet.h>
    
#endif

#include "std-keywords.h"
#include "std-bool.h"
#include "std-math.h"
#include "std-md5.h"
#include "std-bitwise.h"
#include "std-ascii.h"
#include "std-string.h"

#endif /* _XS_STD_H__ */
