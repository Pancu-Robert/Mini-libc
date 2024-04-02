// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <errno.h>
#include <internal/syscall.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
	int err = syscall(__NR_fstat, fd, st);
	err *= (-1);

	if (err == EBADF) {
		errno = EBADF;
		return -1;
	}
	err *= (-1);
	return err;
}
