#ifndef RESUME_PARSER_H
#define RESUME_PARSER_H

#include "resume.h"

// Parses a resume file and returns a pointer to a Resume structure.
Resume* parse_resume(const char* filename);

#endif // RESUME_PARSER_H
