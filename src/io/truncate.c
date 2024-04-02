// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	/* TODO: Implement truncate(). */
	int err = syscall(__NR_truncate, path, length);
	err *= (-1);

	switch (err) {
	case EACCES:
		errno = EACCES;
		return -1;
	case EINVAL:
		errno = EINVAL;
		return -1;
	case EISDIR:
		errno = EISDIR;
		return -1;
	case ENOENT:
		errno = ENOENT;
		return -1;
	default:
		err *= (-1);
		return err;
	}
}
