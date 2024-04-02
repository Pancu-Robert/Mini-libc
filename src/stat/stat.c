// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <internal/syscall.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */
	int err = syscall(__NR_stat, path, buf);
	err *= (-1);

	if (err == ENOENT) {
		errno = ENOENT;
		return -1;
	}
	err *= (-1);
	return err;
}
