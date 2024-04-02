// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	int err = syscall(__NR_lseek, fd, offset, whence);
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
