#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/resume.h"
#include "../include/utils.h"

#define WINDOW_WIDTH 60

void displayMenu(void) {
    system("cls");
    drawBox(WINDOW_WIDTH, 3);
    centerText("Resume Analysis System", WINDOW_WIDTH);
    drawLine(WINDOW_WIDTH);
    printf("\n1. Add New Resume\n");
    printf("2. Add New Job Position\n");
    printf("3. View All Resumes\n");
    printf("4. View All Jobs\n");
    printf("5. Analyze Resume Match\n");
    printf("6. Exit\n");
    drawLine(WINDOW_WIDTH);
}

int main() {
    Resume resumes[MAX_RESUMES];
    Job jobs[MAX_JOBS];
    int resumeCount = 0;
    int jobCount = 0;
    char input[10];

    while (1) {
        displayMenu();
        printf("Enter your choice (1-6): ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            int choice = atoi(input);
            if (choice >= 1 && choice <= 6) {
                switch (choice) {
                    case 1: // Add New Resume
                        if (resumeCount < MAX_RESUMES) {
                            system("cls");
                            drawBox(WINDOW_WIDTH, 3);
                            centerText("Add New Resume", WINDOW_WIDTH);
                            inputResume(&resumes[resumeCount]);
                            resumeCount++;
                            printf("\nResume added successfully!\n");
                        } else {
                            printf("\nMaximum number of resumes reached!\n");
                        }
                        break;

                    case 2: // Add New Job
                        if (jobCount < MAX_JOBS) {
                            system("cls");
                            drawBox(WINDOW_WIDTH, 3);
                            centerText("Add New Job Position", WINDOW_WIDTH);
                            inputJob(&jobs[jobCount]);
                            jobCount++;
                            printf("\nJob position added successfully!\n");
                        } else {
                            printf("\nMaximum number of jobs reached!\n");
                        }
                        break;

                    case 3: // View Resumes
                        system("cls");
                        drawBox(WINDOW_WIDTH, 3);
                        centerText("All Resumes", WINDOW_WIDTH);
                        if (resumeCount > 0) {
                            for (int i = 0; i < resumeCount; i++) {
                                printf("\nResume #%d:\n", i + 1);
                                displayResume(&resumes[i]);
                            }
                        } else {
                            printf("\nNo resumes available yet.\n");
                        }
                        break;

                    case 4: // View Jobs
                        system("cls");
                        drawBox(WINDOW_WIDTH, 3);
                        centerText("All Job Positions", WINDOW_WIDTH);
                        if (jobCount > 0) {
                            for (int i = 0; i < jobCount; i++) {
                                printf("\nJob #%d:\n", i + 1);
                                displayJob(&jobs[i]);
                            }
                        } else {
                            printf("\nNo job positions available yet.\n");
                        }
                        break;

                    case 5: // Analyze Resume Match
                        if (resumeCount > 0 && jobCount > 0) {
                            system("cls");
                            drawBox(WINDOW_WIDTH, 3);
                            centerText("Analyze Resume Match", WINDOW_WIDTH);

                            printf("\nSelect a resume (1-%d): ", resumeCount);
                            int resumeIndex = getIntInput("", 1, resumeCount) - 1;

                            printf("\nSelect a job (1-%d): ", jobCount);
                            int jobIndex = getIntInput("", 1, jobCount) - 1;

                            float matchScore = calculateJobMatch(&resumes[resumeIndex], &jobs[jobIndex]);
                            displayJobMatchAnalysis(&resumes[resumeIndex], &jobs[jobIndex], matchScore);
                        } else {
                            printf("\nPlease add at least one resume and one job position first.\n");
                        }
                        break;

                    case 6: // Exit
                        printf("\nThank you for using Resume Analysis System!\n");
                        return 0;
                }
            } else {
                printf("Please enter a number between 1 and 6.\n");
            }
        }
        printf("\nPress Enter to continue...");
        getchar();
        clearInputBuffer();
    }
    return 0;
}