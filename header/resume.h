#ifndef RESUME_H
#define RESUME_H

#define MAX_STRING 256
#define MAX_SKILLS 10

typedef struct {
    char name[MAX_STRING];
    char education[MAX_STRING];
    int experience;               // Years of experience
    char skills[MAX_SKILLS][MAX_STRING];
    int skillCount;
    int score;                    // Calculated score
} Resume;

typedef struct {
    char title[MAX_STRING];
    char requiredEducation[MAX_STRING];
    int minExperience;
    char requiredSkills[MAX_SKILLS][MAX_STRING];
    int requiredSkillCount;
} Job;

#endif // RESUME_H
