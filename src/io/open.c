// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	int err = syscall(__NR_open, filename, flags);
	err *= (-1);

	switch (err) {
	case ENOENT:
		errno = ENOENT;
		return -1;
	case EACCES:
		errno = EACCES;
		return -1;
	case ENOTDIR:
		errno = ENOTDIR;
		return -1;
	case EISDIR:
		errno = EISDIR;
		return -1;
	case EEXIST:
		errno = EEXIST;
		return -1;
	default:
		err *= (-1);
		return err;
	}
}
