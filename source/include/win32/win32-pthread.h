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
 * @file        win32-pthread.h
 * @brief       POSIX thread functions for Windows
 * @author      Jean-David Gadina <macmade@eosgarden.com>
 */

#ifndef _XS_WIN32_PTHREADS_H_
#define _XS_WIN32_PTHREADS_H_
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/*!
 * @typedef     pthread_t
 * @brief       ...
 */
typedef uint32_t pthread_t;

/*!
 * @typedef     pthread_mutex_t
 * @brief       ...
 */
typedef HANDLE   pthread_mutex_t;

/*!
 * @typedef     pthread_mutexattr_t
 * @brief       ...
 */
typedef uint64_t pthread_mutexattr_t;

/*!
 * @struct      pthread_attr_t_struct
 * @brief       ...
 */
struct pthread_attr_t_struct
{
    int      detachstate;   /*! ... */
    void   * stackaddr;     /*! ... */
    size_t   stacksize;     /*! ... */
};

/*!
 * @typedef     pthread_attr_t
 * @brief       ...
 */
typedef struct pthread_attr_t_struct pthread_attr_t;

/*!
 * @def         PTHREAD_MUTEX_INITIALIZER
 * @brief       ...
 */
#define PTHREAD_MUTEX_INITIALIZER   0

/*!
 * @brief       ...
 * @result      ...
 */
pthread_t pthread_self( void );

/*!
 * @brief       ...
 * @result      void
 */
void pthread_exit( void * retval );

/*!
 * @brief       ...
 * @param       mutex   ...
 * @param       attr    ...
 * @result      ...
 */
int pthread_mutex_init( pthread_mutex_t * mutex, const pthread_mutexattr_t * attr );

/*!
 * @brief       ...
 * @param       mutex   ...
 * @result      ...
 */
int pthread_mutex_destroy( pthread_mutex_t * mutex );

/*!
 * @brief       ...
 * @param       mutex   ...
 * @result      ...
 */
int pthread_mutex_lock( pthread_mutex_t * mutex );

/*!
 * @brief       ...
 * @param       mutex   ...
 * @result      ...
 */
int pthread_mutex_unlock( pthread_mutex_t * mutex );

/*!
 * @brief       ...
 * @param       mutex   ...
 * @result      ...
 */
int pthread_mutex_trylock( pthread_mutex_t * mutex );
    
#ifdef __cplusplus
}
#endif

#endif /* _XS_WIN32_PTHREADS_H_ */
