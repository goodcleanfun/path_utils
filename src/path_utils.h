#ifndef PATH_UTILS_H
#define PATH_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>
#include <sys/types.h>

#ifdef HAVE_DIRENT_H
#include <dirent.h>
#define NAMLEN(dirent) strlen((dirent)->d_name)

#else

#define dirent direct
#define NAMLEN(dirent) ((dirent)->d_namlen)

#ifdef HAVE_SYS_NDIR_H
#include <sys/ndir.h>
#endif

#ifdef HAVE_SYS_DIR_H
#include <sys/dir.h>
#endif

#ifdef HAVE_NDIR_H
#include <ndir.h>
#endif

#endif

#ifdef _WIN32
#define PATH_SEPARATOR   "\\"
#else
#define PATH_SEPARATOR   "/"
#endif

#define PATH_SEPARATOR_LEN strlen(PATH_SEPARATOR)

bool is_relative_path(struct dirent *ent);

char *path_join(int n, ...);
char *path_vjoin(int n, va_list args);

#endif

