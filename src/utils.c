#include "../header/utils.h"
#include <ctype.h>
#include <string.h>

// Case-insensitive substring search.
char *strcasestr_custom(const char *haystack, const char *needle) {
    if (!*needle)
        return (char *) haystack;
    for (; *haystack; haystack++) {
        if (toupper((unsigned char)*haystack) == toupper((unsigned char)*needle)) {
            const char *h = haystack, *n = needle;
            while (*h && *n && (toupper((unsigned char)*h) == toupper((unsigned char)*n))) {
                h++;
                n++;
            }
            if (!*n)
                return (char *) haystack;
        }
    }
    return NULL;
}

// Trims leading and trailing whitespace.
char* trim_whitespace(char* str) {
    // Trim leading spaces.
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0)
        return str;
    // Trim trailing spaces.
    char* end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end+1) = '\0';
    return str;
}
