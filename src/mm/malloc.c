// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

#define MAP_ANONYMOUS	0x20
#define MREMAP_MAYMOVE	1

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	if (size == 0) {
		return NULL;
	}

	size_t alloc_size = size + sizeof(size_t);

	void *addr = mmap(NULL, alloc_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (addr == MAP_FAILED) {
		return NULL;
	}

	*(size_t *)addr = size;
	void *p = (void *)((char *)addr + sizeof(size_t));

	return p;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	if (nmemb == 0 || size == 0) {
		return NULL;
	}

	size_t alloc_size = nmemb * size + sizeof(size_t);

	void *p = malloc(alloc_size);
	memset(p, 0, alloc_size - sizeof(size_t));

	return p;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	void *addr = (void *)((char *)ptr - sizeof(size_t));
	size_t size = *(size_t *)addr;

	munmap(addr, size + sizeof(size_t));
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (ptr == NULL) {
		return malloc(size);
	}
	if (size == 0) {
		free(ptr);
		return NULL;
	}

	void *addr = (void *)((char *)ptr - sizeof(size_t));

	size_t old_size = *(size_t *)addr + sizeof(size_t);
	size_t new_size = size + sizeof(size_t);

	void *new_addr = mremap(addr, old_size, new_size, MREMAP_MAYMOVE);
	if (new_addr == MAP_FAILED) {
		return NULL;
	}

	*(size_t *)new_addr = size;
	void *p = (void *)((char *)new_addr + sizeof(size_t));

	return p;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	size_t total_size = nmemb * size;

	return realloc(ptr, total_size);
}
