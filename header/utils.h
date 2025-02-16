#ifndef UTILS_H
#define UTILS_H

#include "resume.h"

#ifdef _MSC_VER
    #define strcasecmp _stricmp
#endif

// Function prototypes
char *strcasestr_custom(const char *haystack, const char *needle);
char* trim_whitespace(char* str);

#endif // UTILS_H
