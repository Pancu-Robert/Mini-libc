// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
	int err = syscall(__NR_ftruncate, fd, length);
	err *= (-1);

	switch (err) {
	case EBADF:
		errno = EBADF;
		return -1;
	case EINVAL:
		errno = EINVAL;
		return -1;
	default:
		err *= (-1);
		return err;
	}
}
