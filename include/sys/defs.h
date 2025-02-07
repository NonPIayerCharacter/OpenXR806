/* libc/sys/linux/sys/cdefs.h - Helper macros for K&R vs. ANSI C compat. */

/* Written 2000 by Werner Almesberger */

/*-
 * Copyright (c) 1991, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Berkeley Software Design, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)cdefs.h	8.8 (Berkeley) 1/9/95
 * $FreeBSD$
 */

#ifndef _SYS_DEFS_H_
#define _SYS_DEFS_H_

#include "types.h"
#include "compiler.h"

#define XR_OFFSET_OF(type, field) \
    ((size_t)(uintptr_t)((const volatile void *)&((type *)0)->field))

#define __XR_OFFSET_OF(type, field) XR_OFFSET_OF(type, field)

#define __XR_DEQUALIFY(type, var) ((type)(uintptr_t)(const volatile void *)(var))

#define __XR_CONTAINER_OF(ptr, type, field) \
    __XR_DEQUALIFY(type *, (const volatile char *)(ptr) - XR_OFFSET_OF(type, field))

#define XR_CONTAINER_OF(ptr, type, field) __XR_CONTAINER_OF(ptr, type, field)

#ifndef __DEQUALIFY
#define __DEQUALIFY(type, var) __XR_DEQUALIFY(type, var)
#endif

#ifndef offsetof
#define offsetof(type, field) XR_OFFSET_OF(type, field)
#endif

#ifndef __offsetof
#define __offsetof(type, field) __XR_OFFSET_OF(type, field)
#endif

#ifndef __containerof
#define __containerof(ptr, type, field) __XR_CONTAINER_OF(ptr, type, field)
#endif

#ifndef container_of
#define container_of(ptr, type, field) XR_CONTAINER_OF(ptr, type, field)
#endif

/*
 * Definitions for byte order, according to byte significance from low
 * address to high.
 */
#define _LITTLE_ENDIAN  1234    /* LSB first: i386, vax */
#define _BIG_ENDIAN     4321    /* MSB first: 68000, ibm, net */

#define LITTLE_ENDIAN   _LITTLE_ENDIAN
#define BIG_ENDIAN      _BIG_ENDIAN

#define _BYTE_ORDER     _LITTLE_ENDIAN
#define BYTE_ORDER      _BYTE_ORDER

#endif /* _SYS_DEFS_H_ */
