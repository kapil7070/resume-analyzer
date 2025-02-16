#ifndef JOB_H
#define JOB_H

#include "resume.h"
#ifdef _MSC_VER
    #define strcasecmp _stricmp
#endif

// Returns the job requirements based on the given job title.
Job getJobRequirements(const char* jobTitle);

#endif // JOB_H
