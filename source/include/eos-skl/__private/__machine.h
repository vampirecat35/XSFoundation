/*******************************************************************************
 * Copyright (c) 2010, Jean-David Gadina <macmade@eosgarden.com>
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
 * @file            __machine.h
 * @brief           EOS-SKL (Source Kit Language) architecture private routines
 * @author          Jean-David Gadina <macmade@eosgarden.com>
 * @version         4.0.0
 * @since           2.5.0
 */

#ifndef _XS_EOS_SKL_PRIV_MACHINE_H_
#define _XS_EOS_SKL_PRIV_MACHINE_H_
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#if defined ( __i386__ ) || defined( __x86_64__ )
    
    #include "./arch/__i386.h"
    
#elif defined ( __arm__ )
    
    #include "./arch/__arm.h"
    
#elif defined ( __ppc__ ) || defined ( __ppc64__ )
    
    /*
        Note:   Support for the PPC architecture is not yet available.
                Maybe one day I'll also code m68K specific routines...
    */
    #if defined( error )
        
        #error PPC architecture not supported yet
        
    #endif
    
#elif defined( error )
    
    #error Architecture not supported

#endif

#ifdef __cplusplus
}
#endif

#endif /* _XS_EOS_SKL_PRIV_MACHINE_H_ */
