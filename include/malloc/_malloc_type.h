/*
 * This file is part of Darling.
 *
 * Copyright (C) 2026 Lubos Dolezel
 *
 * Darling is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Darling is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Darling.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MALLOC_UNDERSCORE_MALLOC_TYPE_H_
#define _MALLOC_UNDERSCORE_MALLOC_TYPE_H_

/*
 * Typed allocation entry points (macOS 14). A compiler that supports typed
 * memory operations may call these instead of the untyped functions, passing
 * a type identifier as the last argument. They are not meant to be called
 * directly. Included from <malloc/_malloc.h>.
 */

#include <Availability.h>
#include <sys/cdefs.h>
#include <sys/_types/_size_t.h>

typedef unsigned long long malloc_type_id_t;

#if defined(__LP64__)

__BEGIN_DECLS

__API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0), watchos(10.0))
void *malloc_type_malloc(size_t size, malloc_type_id_t type_id) __result_use_check __alloc_size(1);
__API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0), watchos(10.0))
void *malloc_type_calloc(size_t count, size_t size, malloc_type_id_t type_id) __result_use_check __alloc_size(1,2);
__API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0), watchos(10.0))
void malloc_type_free(void *ptr, malloc_type_id_t type_id);
__API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0), watchos(10.0))
void *malloc_type_realloc(void *ptr, size_t size, malloc_type_id_t type_id) __result_use_check __alloc_size(2);
__API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0), watchos(10.0))
void *malloc_type_valloc(size_t size, malloc_type_id_t type_id) __result_use_check __alloc_size(1);
__API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0), watchos(10.0))
void *malloc_type_aligned_alloc(size_t alignment, size_t size, malloc_type_id_t type_id) __result_use_check __alloc_size(2);
__API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0), watchos(10.0))
int malloc_type_posix_memalign(void **memptr, size_t alignment, size_t size, malloc_type_id_t type_id);

#if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
typedef struct _malloc_zone_t malloc_zone_t;

__API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0), watchos(10.0))
void *malloc_type_zone_malloc(malloc_zone_t *zone, size_t size, malloc_type_id_t type_id) __result_use_check __alloc_size(2);
__API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0), watchos(10.0))
void *malloc_type_zone_calloc(malloc_zone_t *zone, size_t count, size_t size, malloc_type_id_t type_id) __result_use_check __alloc_size(2,3);
__API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0), watchos(10.0))
void malloc_type_zone_free(malloc_zone_t *zone, void *ptr, malloc_type_id_t type_id);
__API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0), watchos(10.0))
void *malloc_type_zone_realloc(malloc_zone_t *zone, void *ptr, size_t size, malloc_type_id_t type_id) __result_use_check __alloc_size(3);
__API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0), watchos(10.0))
void *malloc_type_zone_valloc(malloc_zone_t *zone, size_t size, malloc_type_id_t type_id) __result_use_check __alloc_size(2);
__API_AVAILABLE(macos(14.0), ios(17.0), tvos(17.0), watchos(10.0))
void *malloc_type_zone_memalign(malloc_zone_t *zone, size_t alignment, size_t size, malloc_type_id_t type_id) __result_use_check __alloc_size(3);
#endif /* __DARWIN_C_LEVEL >= __DARWIN_C_FULL */

__END_DECLS

#endif /* __LP64__ */

#endif /* _MALLOC_UNDERSCORE_MALLOC_TYPE_H_ */
