#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/resume.h"
#include "../header/resume_parser.h"
#include "../header/job.h"
#include "../header/scoring.h"

#ifdef _MSC_VER
    #define strcasecmp _stricmp
#endif

#define MAX_STRING 256
#define MAX_SKILLS 10

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void displayMenu() {
    printf("\n====================================\n");
    printf("        Resume Analyzer        \n");
    printf("====================================\n");
    printf("1. Job Seeker - Test Your Resume\n");
    printf("2. Recruiter - Filter Best Resume\n");
    printf("3. Exit\n");
    printf("====================================\n");
    printf("Choose an option: ");
}

void test_resume() {
    char jobTitle[MAX_STRING];
    char filename[MAX_STRING];

    printf("Enter the job title you are applying for: ");
    clear_input_buffer();
    fgets(jobTitle, MAX_STRING, stdin);
    jobTitle[strcspn(jobTitle, "\n")] = '\0';

    printf("Enter your resume file name: ");
    fgets(filename, MAX_STRING, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    Job job = getJobRequirements(jobTitle);
    Resume* resume = parse_resume(filename);

    if (!resume) {
        printf("Error: Unable to read the resume.\n");
        return;
    }

    resume->score = score_resume(resume, &job);
    printf("\n========= Resume Analysis =========\n");
    printf("Name: %s\n", resume->name);
    printf("Score: %d/100\n", resume->score);
    printf("------------------------------------\n");

    printf("\nSuggestions for Improvement:\n");
    if (strcasecmp(resume->education, job.requiredEducation) != 0) {
        printf("- Consider obtaining a %s degree.\n", job.requiredEducation);
    }
    if (resume->experience < job.minExperience) {
        printf("- Gain at least %d more years of experience.\n", job.minExperience - resume->experience);
    }

    printf("- Consider adding these missing skills: ");
    int foundSkill;
    for (int i = 0; i < job.requiredSkillCount; i++) {
        foundSkill = 0;
        for (int j = 0; j < resume->skillCount; j++) {
            if (strcasecmp(job.requiredSkills[i], resume->skills[j]) == 0) {
                foundSkill = 1;
                break;
            }
        }
        if (!foundSkill) {
            printf("%s, ", job.requiredSkills[i]);
        }
    }
    printf("\n====================================\n");
    free(resume);
}

Job get_manual_job_details() {
    Job job;
    printf("Enter the job title: ");
    clear_input_buffer();
    fgets(job.title, MAX_STRING, stdin);
    job.title[strcspn(job.title, "\n")] = '\0';

    printf("Enter the required education (e.g., Bachelor's, Master's): ");
    fgets(job.requiredEducation, MAX_STRING, stdin);
    job.requiredEducation[strcspn(job.requiredEducation, "\n")] = '\0';

    printf("Enter the minimum years of experience required: ");
    scanf("%d", &job.minExperience);
    clear_input_buffer();

    printf("Enter the number of required skills (max %d): ", MAX_SKILLS);
    scanf("%d", &job.requiredSkillCount);
    clear_input_buffer();

    for (int i = 0; i < job.requiredSkillCount && i < MAX_SKILLS; i++) {
        printf("Enter skill %d: ", i + 1);
        fgets(job.requiredSkills[i], MAX_STRING, stdin);
        job.requiredSkills[i][strcspn(job.requiredSkills[i], "\n")] = '\0';
    }

    return job;
}

void filter_best_resume() {
    Job job = get_manual_job_details();
    int resumeCount;
    printf("Enter the number of resumes to evaluate: ");
    scanf("%d", &resumeCount);
    clear_input_buffer();

    Resume** resumes = malloc(resumeCount * sizeof(Resume*));
    if (!resumes) {
        printf("Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i < resumeCount; i++) {
        char filename[MAX_STRING];
        printf("Enter resume file name %d: ", i + 1);
        fgets(filename, MAX_STRING, stdin);
        filename[strcspn(filename, "\n")] = '\0';

        resumes[i] = parse_resume(filename);
        if (resumes[i]) {
            resumes[i]->score = score_resume(resumes[i], &job);
        } else {
            printf("Error parsing resume file: %s\n", filename);
        }
    }

    int bestIndex = -1, bestScore = -1;
    printf("\n========= Resume Scores =========\n");
    for (int i = 0; i < resumeCount; i++) {
        if (resumes[i]) {
            printf("Name: %s, Score: %d\n", resumes[i]->name, resumes[i]->score);
            if (resumes[i]->score > bestScore) {
                bestScore = resumes[i]->score;
                bestIndex = i;
            }
        }
    }
    
    if (bestIndex != -1) {
        printf("\n========= Best Resume =========\n");
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
    
    for (int i = 0; i < resumeCount; i++) {
        if (resumes[i]) free(resumes[i]);
    }
    free(resumes);
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1: test_resume(); break;
            case 2: filter_best_resume(); break;
            case 3: printf("Exiting program.\n"); return 0;
            default: printf("Invalid choice, please try again.\n");
        }
    }
}
