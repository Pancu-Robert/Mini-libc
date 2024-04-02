// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	char *d = destination;
	while(*source) {
		*d++ = *source++;
	}

	*d = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	char *d = destination;
	while (*source && len) {
		*d++ = *source++;
		len--;
	}

	while (len) {
		*d++ = '\0';
		len--;
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char *d = destination + strlen(destination);
	strcpy(d, source);

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char *d = destination + strlen(destination);

	while (*source && len) {
		*d++ = *source++;
		len--;
	}
	*d = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while (*str1|| *str2) {
		if (*str1 != *str2) {
			return *str1 - *str2;
		}
		str1++;
		str2++;
	}
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	while ((*str1 || *str2) && len) {
		if (*str1 != *str2) {
			return *str1 - *str2;
		}
		str1++;
		str2++;
		len--;
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	while(*str) {
		if (*str == c) {
			return (char *)str;
		}
		str++;
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char *s = (char *)str + strlen(str) - 1;

	while(*s) {
		if (*s == c) {
			return s;
		}
		s--;
	}

	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	while (*haystack) {
		if (strncmp(haystack, needle, strlen(needle)) == 0) {
			return (char *)haystack;
		}
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	char *s1 = (char *)haystack + strlen(haystack) - 1;

	while (*s1) {
		if (strncmp(s1, needle, strlen(needle)) == 0) {
			return s1;
		}
		s1--;
	}

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *src = (char *)source;
	char *dest = (char *)destination;

	while (num) {
		*dest++ = *src++;
		num--;
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *src = (char *)source;
	char *dest = (char *)destination;

	if (dest < src) {
		while (num) {
			*dest++ = *src++;
			num--;
		}
	} else if (dest > src) {
		src += num - 1;
		dest += num - 1;
		while (num) {
			*dest-- = *src--;
			num--;
		}
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	char *s1 = (char *)ptr1;
	char *s2 = (char *)ptr2;

	while (num) {
		if (*s1 != *s2) {
			return *s1 - *s2;
		}
		s1++;
		s2++;
		num--;
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *s = (char *)source;

	while(num) {
		*s++ = value;
		num--;
	}

	return source;
}
