#include "../header/job.h"
#include <string.h>
#include <stdio.h>

Job getJobRequirements(const char* jobTitle) {
    Job job;
    strncpy(job.title, jobTitle, MAX_STRING);
    
    if (strcasecmp(jobTitle, "Software Engineer") == 0) {
         strcpy(job.requiredEducation, "Bachelor");
         job.minExperience = 2;
         job.requiredSkillCount = 4;
         strcpy(job.requiredSkills[0], "C");
         strcpy(job.requiredSkills[1], "C++");
         strcpy(job.requiredSkills[2], "Java");
         strcpy(job.requiredSkills[3], "Python");
    } else {
         // Default requirements.
         strcpy(job.requiredEducation, "Bachelor");
         job.minExperience = 1;
         job.requiredSkillCount = 2;
         strcpy(job.requiredSkills[0], "Communication");
         strcpy(job.requiredSkills[1], "Teamwork");
    }
    return job;
}
