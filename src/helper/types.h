/* SPDX-License-Identifier: GPL-2.0-or-later */

/***************************************************************************
 *   Copyright (C) 2004, 2005 by Dominic Rath                              *
 *   Dominic.Rath@gmx.de                                                   *
 *                                                                         *
 *   Copyright (C) 2007,2008 Øyvind Harboe                                 *
 *   oyvind.harboe@zylin.com                                               *
 ***************************************************************************/

#ifndef OPENOCD_HELPER_TYPES_H
#define OPENOCD_HELPER_TYPES_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stddef.h>
#include <assert.h>
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif
#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#endif

#ifdef HAVE_STDBOOL_H
#include <stdbool.h>
#else	/* HAVE_STDBOOL_H */
#define __bool_true_false_are_defined 1

#ifndef HAVE__BOOL
#ifndef __cplusplus

#define false	0
#define true	1

#endif	/* __cplusplus */
#endif	/* HAVE__BOOL */
#endif	/* HAVE_STDBOOL_H */

/// turns a macro argument into a string constant
#define stringify(s) __stringify(s)
#define __stringify(s) #s


/**
 * Compute the number of elements of a variable length array.
 * <code>
 * const char *strs[] = { "a", "b", "c" };
 * size_t num_strs = ARRAY_SIZE(strs);
 * </code>
 */
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))


/**
 * Cast a member of a structure out to the containing structure.
 * @param ptr The pointer to the member.
 * @param type The type of the container struct this is embedded in.
 * @param member The name of the member within the struct.
 *
 * This is a mechanism which is used throughout the Linux kernel.
 */
#define container_of(ptr, type, member) ({			\
	const typeof( ((type *)0)->member ) *__mptr = (ptr);	\
	(type *)( (void *) ( (char *)__mptr - offsetof(type,member) ) );})


/**
 * Rounds @c m up to the nearest multiple of @c n using division.
 * @param m The value to round up to @c n.
 * @param n Round @c m up to a multiple of this number.
 * @returns The rounded integer value.
 */
#define DIV_ROUND_UP(m, n)	(((m) + (n) - 1) / (n))


uint64_t le_to_h_u64(const uint8_t* buf);
uint32_t le_to_h_u32(const uint8_t* buf);
uint32_t le_to_h_u24(const uint8_t* buf);
uint16_t le_to_h_u16(const uint8_t* buf);
uint64_t be_to_h_u64(const uint8_t* buf);
uint32_t be_to_h_u32(const uint8_t* buf);
uint32_t be_to_h_u24(const uint8_t* buf);
uint16_t be_to_h_u16(const uint8_t* buf);
void h_u64_to_le(uint8_t* buf, uint64_t val);
void h_u64_to_be(uint8_t* buf, uint64_t val);
void h_u32_to_le(uint8_t* buf, uint32_t val);
void h_u32_to_be(uint8_t* buf, uint32_t val);
void h_u24_to_le(uint8_t* buf, unsigned int val);
void h_u24_to_be(uint8_t* buf, unsigned int val);
void h_u16_to_le(uint8_t* buf, uint16_t val);
void h_u16_to_be(uint8_t* buf, uint16_t val);
void buf_bswap16(uint8_t* dst, const uint8_t* src, size_t len);
void buf_bswap32(uint8_t* dst, const uint8_t* src, size_t len);
int parity_u32(uint32_t x);

typedef uint64_t target_addr_t;
#define TARGET_ADDR_MAX UINT64_MAX
#define TARGET_PRIdADDR PRId64
#define TARGET_PRIuADDR PRIu64
#define TARGET_PRIoADDR PRIo64
#define TARGET_PRIxADDR PRIx64
#define TARGET_PRIXADDR PRIX64
#define TARGET_ADDR_FMT "0x%8.8" TARGET_PRIxADDR

#endif /* OPENOCD_HELPER_TYPES_H */
