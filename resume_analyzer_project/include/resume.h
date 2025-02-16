#ifndef RESUME_H
#define RESUME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 256
#define MAX_SKILLS 20
#define MAX_EXPERIENCES 10
#define MAX_RESUMES 50
#define MAX_JOBS 10
#define MAX_REQUIREMENTS 10

// Structure definitions
typedef struct {
    char company[MAX_STRING];
    char position[MAX_STRING];
    int years;
} Experience;

typedef struct {
    char title[MAX_STRING];
    char company[MAX_STRING];
    char requiredSkills[MAX_REQUIREMENTS][MAX_STRING];
    int skillCount;
    int minYearsExperience;
    char requiredEducation[MAX_STRING];
} Job;

typedef struct {
    char name[MAX_STRING];
    int age;
    char education[MAX_STRING];
    float gpa;
    char skills[MAX_SKILLS][MAX_STRING];
    int skillCount;
    Experience experiences[MAX_EXPERIENCES];
    int experienceCount;
    float score;
} Resume;

// Function prototypes
void initializeResume(Resume *resume);
void inputResume(Resume *resume);
void displayResume(const Resume *resume);
float calculateJobMatch(const Resume *resume, const Job *job);
void saveResumesToFile(Resume *resumes, int count, const char *filename);
int loadResumesFromFile(Resume *resumes, const char *filename);
void analyzeResumeForJob(const Resume *resume, const Job *job);
void displayJobMatchAnalysis(const Resume *resume, const Job *job, float matchScore);
void inputJob(Job *job);
void displayJob(const Job *job);

#endif // RESUME_H