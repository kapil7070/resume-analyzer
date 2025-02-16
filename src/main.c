#include <stdio.h>
#include <stdlib.h>
#include "../header/resume.h"
#include "../header/resume_parser.h"
#include "../header/job.h"
#include "../header/scoring.h"
#ifdef _MSC_VER
    #define strcasecmp _stricmp
#endif

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <job_title> <resume_file1> [<resume_file2> ...]\n", argv[0]);
        return 1;
    }
    
    // The first argument is the job title.
    char* jobTitle = argv[1];
    Job job = getJobRequirements(jobTitle);
    
    int resumeCount = argc - 2;
    Resume** resumes = malloc(resumeCount * sizeof(Resume*));
    if (!resumes) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    // Parse each resume file and compute its score.
    for (int i = 0; i < resumeCount; i++) {
        resumes[i] = parse_resume(argv[i + 2]);
        if (!resumes[i]) {
            printf("Error parsing resume file: %s\n", argv[i + 2]);
        } else {
            resumes[i]->score = score_resume(resumes[i], &job);
        }
    }
    
    // Display scores and determine the best resume.
    int bestIndex = -1;
    int bestScore = -1;
    printf("\nResume Scores:\n");
    for (int i = 0; i < resumeCount; i++) {
        if (resumes[i]) {
            printf("File: %s, Name: %s, Score: %d\n", argv[i+2], resumes[i]->name, resumes[i]->score);
            if (resumes[i]->score > bestScore) {
                bestScore = resumes[i]->score;
                bestIndex = i;
            }
        }
    }
    
    if (bestIndex != -1) {
        printf("\n--- Best Resume ---\n");
        printf("File: %s\n", argv[bestIndex+2]);
        printf("Name: %s\n", resumes[bestIndex]->name);
        printf("Education: %s\n", resumes[bestIndex]->education);
        printf("Experience: %d years\n", resumes[bestIndex]->experience);
        printf("Skills: ");
        for (int j = 0; j < resumes[bestIndex]->skillCount; j++) {
            printf("%s", resumes[bestIndex]->skills[j]);
            if (j < resumes[bestIndex]->skillCount - 1)
                printf(", ");
        }
        printf("\nScore: %d/100\n", resumes[bestIndex]->score);
    } else {
        printf("No valid resumes were parsed.\n");
    }
    
    // Free allocated memory.
    for (int i = 0; i < resumeCount; i++) {
        if (resumes[i])
            free(resumes[i]);
    }
    free(resumes);
    
    return 0;
}
