#include "../header/resume_parser.h"
#include "../header/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Resume* parse_resume(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Could not open resume file: %s\n", filename);
        return NULL;
    }
    Resume* resume = malloc(sizeof(Resume));
    if (!resume) {
        printf("Memory allocation failed for resume.\n");
        fclose(file);
        return NULL;
    }
    memset(resume, 0, sizeof(Resume));
    
    char line[512];
    while (fgets(line, sizeof(line), file)) {
        char* colon = strchr(line, ':');
        if (!colon) continue;
        *colon = '\0';
        char* key = trim_whitespace(line);
        char* value = trim_whitespace(colon + 1);
        
        if (strcasecmp(key, "Name") == 0) {
            strncpy(resume->name, value, MAX_STRING);
        } else if (strcasecmp(key, "Education") == 0) {
            strncpy(resume->education, value, MAX_STRING);
        } else if (strcasecmp(key, "Experience") == 0) {
            resume->experience = atoi(value);
        } else if (strcasecmp(key, "Skills") == 0) {
            resume->skillCount = 0;
            char* token = strtok(value, ",");
            while (token && resume->skillCount < MAX_SKILLS) {
                token = trim_whitespace(token);
                strncpy(resume->skills[resume->skillCount], token, MAX_STRING);
                resume->skillCount++;
                token = strtok(NULL, ",");
            }
        }
    }
    fclose(file);
    return resume;
}
