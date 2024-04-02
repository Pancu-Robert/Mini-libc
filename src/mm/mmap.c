// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */

	void *mapped_address = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);

	long err = (long)mapped_address;

	if (err < 0) {
		errno = -err;
		return MAP_FAILED;
	}

	return mapped_address;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */

	void *new_address = syscall(__NR_mremap, old_address, old_size, new_size, flags);

	long err = (long)new_address;

	if (err < 0) {
		errno = -err;
		return MAP_FAILED;
	}

	return new_address;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	int err = syscall(__NR_munmap, addr, length);

	if (err < 0) {
		errno = -err;
		return -1;
	}
	return 0;
}
