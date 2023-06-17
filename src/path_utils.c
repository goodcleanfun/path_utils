#include "path_utils.h"
#include "char_array/char_array.h"

bool is_relative_path(struct dirent *ent) {
    return strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0;
}

char *path_vjoin(int n, va_list args) {
    char_array *path = char_array_new();
    if (path == NULL) return NULL;
    char_array_add_vjoined(path, PATH_SEPARATOR, true, n, args);
    return char_array_to_string(path);
}

char *path_join(int n, ...) {
    va_list args;
    va_start(args, n);
    char *path = path_vjoin(n, args);
    va_end(args);
    return path;
}
