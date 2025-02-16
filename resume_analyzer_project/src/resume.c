#include "../include/resume.h"
#include "../include/utils.h"

void initializeResume(Resume *resume) {
    memset(resume, 0, sizeof(Resume));
}

void inputResume(Resume *resume) {
    initializeResume(resume);

    printf("\nEnter Basic Information:\n");
    getString(resume->name, MAX_STRING, "Name: ");
    resume->age = getIntInput("Age: ", 18, 100);
    getString(resume->education, MAX_STRING, "Education: ");

    // Simplified skills input
    printf("\nEnter Skills (up to 5):\n");
    resume->skillCount = getIntInput("How many skills? (1-5): ", 1, 5);
    printf("Enter each skill:\n");
    for (int i = 0; i < resume->skillCount; i++) {
        getString(resume->skills[i], MAX_STRING, "");
    }

    // Simplified experience input
    printf("\nWork Experience:\n");
    resume->experienceCount = getIntInput("Number of work experiences (0-3): ", 0, 3);
    for (int i = 0; i < resume->experienceCount; i++) {
        printf("\nExperience %d:\n", i + 1);
        getString(resume->experiences[i].company, MAX_STRING, "Company: ");
        getString(resume->experiences[i].position, MAX_STRING, "Position: ");
        resume->experiences[i].years = getIntInput("Years of experience: ", 0, 50);
    }
}

void displayResume(const Resume *resume) {
    drawLine(60);
    printf("Name: %s\n", resume->name);
    printf("Age: %d\n", resume->age);
    printf("Education: %s\n", resume->education);

    printf("\nSkills:\n");
    for (int i = 0; i < resume->skillCount; i++) {
        printf("- %s\n", resume->skills[i]);
    }

    if (resume->experienceCount > 0) {
        printf("\nWork Experience:\n");
        for (int i = 0; i < resume->experienceCount; i++) {
            printf("- %s at %s (%d years)\n",
                   resume->experiences[i].position,
                   resume->experiences[i].company,
                   resume->experiences[i].years);
        }
    }
    drawLine(60);
}

void analyzeResume(Resume *resume) {
    float score = 0.0;
    score += resume->skillCount * 10;  // 10 points per skill
    score += resume->experienceCount * 20;  // 20 points per experience
    resume->score = score;
}


void inputJob(Job *job) {
    printf("\nEnter Job Details:\n");
    getString(job->title, MAX_STRING, "Job Title: ");
    getString(job->company, MAX_STRING, "Company: ");
    getString(job->requiredEducation, MAX_STRING, "Required Education: ");
    job->minYearsExperience = getIntInput("Minimum Years of Experience: ", 0, 20);

    printf("\nEnter Required Skills (up to %d):\n", MAX_REQUIREMENTS);
    job->skillCount = getIntInput("How many required skills? (1-10): ", 1, 10);
    printf("Enter each required skill:\n");
    for (int i = 0; i < job->skillCount; i++) {
        getString(job->requiredSkills[i], MAX_STRING, "");
    }
}

void displayJob(const Job *job) {
    drawLine(60);
    printf("Job Title: %s\n", job->title);
    printf("Company: %s\n", job->company);
    printf("Required Education: %s\n", job->requiredEducation);
    printf("Minimum Experience: %d years\n", job->minYearsExperience);

    printf("\nRequired Skills:\n");
    for (int i = 0; i < job->skillCount; i++) {
        printf("- %s\n", job->requiredSkills[i]);
    }
    drawLine(60);
}

float calculateJobMatch(const Resume *resume, const Job *job) {
    float score = 0.0;
    float maxScore = 100.0;

    // Education match (30 points)
    if (strstr(resume->education, job->requiredEducation) != NULL) {
        score += 30.0;
    }

    // Experience match (30 points)
    int totalYears = 0;
    for (int i = 0; i < resume->experienceCount; i++) {
        totalYears += resume->experiences[i].years;
    }
    if (totalYears >= job->minYearsExperience) {
        score += 30.0;
    } else if (job->minYearsExperience > 0) {
        score += (totalYears * 30.0) / job->minYearsExperience;
    }

    // Skills match (40 points)
    float skillPoints = 40.0 / job->skillCount;
    for (int i = 0; i < job->skillCount; i++) {
        for (int j = 0; j < resume->skillCount; j++) {
            if (strstr(resume->skills[j], job->requiredSkills[i]) != NULL) {
                score += skillPoints;
                break;
            }
        }
    }

    return score;
}

void displayJobMatchAnalysis(const Resume *resume, const Job *job, float matchScore) {
    drawBox(80, 3);
    centerText("Job Match Analysis", 80);
    drawLine(80);

    printf("\nCandidate: %s\n", resume->name);
    printf("Position: %s at %s\n\n", job->title, job->company);

    printf("Match Score: %.1f%%\n\n", matchScore);

    printf("Analysis:\n");
    if (matchScore >= 90) {
        printf("- Excellent match! Strong candidate for the position.\n");
    } else if (matchScore >= 70) {
        printf("- Good match. Candidate meets most requirements.\n");
    } else if (matchScore >= 50) {
        printf("- Fair match. Some requirements met, but areas for improvement exist.\n");
    } else {
        printf("- Limited match. Significant gaps between requirements and qualifications.\n");
    }

    printf("\nStrengths:\n");
    int totalYears = 0;
    for (int i = 0; i < resume->experienceCount; i++) {
        totalYears += resume->experiences[i].years;
    }
    if (totalYears >= job->minYearsExperience) {
        printf("- Meets or exceeds experience requirements\n");
    }

    printf("\nSkill Matches:\n");
    for (int i = 0; i < job->skillCount; i++) {
        int found = 0;
        for (int j = 0; j < resume->skillCount; j++) {
            if (strstr(resume->skills[j], job->requiredSkills[i]) != NULL) {
                found = 1;
                printf("- %s (✓)\n", job->requiredSkills[i]);
                break;
            }
        }
        if (!found) {
            printf("- %s (✗)\n", job->requiredSkills[i]);
        }
    }

    printf("\nRecommendations:\n");
    if (matchScore < 70) {
        printf("- Consider acquiring additional skills in: ");
        int printed = 0;
        for (int i = 0; i < job->skillCount; i++) {
            int found = 0;
            for (int j = 0; j < resume->skillCount; j++) {
                if (strstr(resume->skills[j], job->requiredSkills[i]) != NULL) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                if (printed > 0) printf(", ");
                printf("%s", job->requiredSkills[i]);
                printed++;
            }
        }
        printf("\n");
    }
    if (totalYears < job->minYearsExperience) {
        printf("- Gain additional experience: %d more years recommended\n", 
               job->minYearsExperience - totalYears);
    }

    drawLine(80);
}

float calculateScore(const Resume *resume) {
    float score = 0.0;

    // Education score (30%)
    score += (resume->gpa / 4.0) * 30;

    // Experience score (40%)
    int totalYears = 0;
    for (int i = 0; i < resume->experienceCount; i++) {
        totalYears += resume->experiences[i].years;
    }
    score += (totalYears > 10 ? 40 : totalYears * 4);

    // Skills score (30%)
    score += (resume->skillCount > 10 ? 30 : resume->skillCount * 3);

    return score;
}

void displayAnalysis(const Resume *resume) {
    drawBox(80, 3);
    centerText("Resume Analysis", 80);
    drawLine(80);

    printf("\nCandidate: %s\n\n", resume->name);

    printf("Strengths:\n");
    if (resume->gpa >= 3.5) printf("- Excellent academic performance\n");
    if (resume->experienceCount >= 3) printf("- Strong work experience\n");
    if (resume->skillCount >= 8) printf("- Diverse skill set\n");

    printf("\nAreas for Improvement:\n");
    if (resume->gpa < 3.0) printf("- Academic performance\n");
    if (resume->experienceCount < 2) printf("- Work experience\n");
    if (resume->skillCount < 5) printf("- Skill diversity\n");

    printf("\nOverall Score: %.2f/100\n", resume->score);

    printf("\nRecommendations:\n");
    if (resume->score >= 80) {
        printf("- Excellent candidate, recommended for senior positions\n");
    } else if (resume->score >= 60) {
        printf("- Good candidate, suitable for mid-level positions\n");
    } else {
        printf("- Consider gaining more experience or skills\n");
    }

    drawLine(80);
}

void saveResumesToFile(Resume *resumes, int count, const char *filename) {
    if (!resumes || !filename) {
        printf("Invalid parameters for file saving!\n");
        return;
    }

    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Could not open file '%s' for writing!\n", filename);
        return;
    }

    size_t written_count = fwrite(&count, sizeof(int), 1, file);
    size_t written_resumes = fwrite(resumes, sizeof(Resume), count, file);

    if (written_count != 1 || written_resumes != count) {
        printf("Error: Failed to write all data to file!\n");
    } else {
        printf("Successfully saved %d resumes to file.\n", count);
    }

    fclose(file);
}

int loadResumesFromFile(Resume *resumes, const char *filename) {
    if (!resumes || !filename) {
        printf("Invalid parameters for file loading!\n");
        return 0;
    }

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file '%s' for reading!\n", filename);
        return 0;
    }

    int count;
    size_t read_count = fread(&count, sizeof(int), 1, file);
    if (read_count != 1) {
        printf("Error: Failed to read resume count from file!\n");
        fclose(file);
        return 0;
    }

    if (count > MAX_RESUMES) {
        printf("Error: File contains too many resumes!\n");
        fclose(file);
        return 0;
    }

    size_t read_resumes = fread(resumes, sizeof(Resume), count, file);
    if (read_resumes != count) {
        printf("Error: Failed to read all resumes from file!\n");
        fclose(file);
        return 0;
    }

    printf("Successfully loaded %d resumes from file.\n", count);
    fclose(file);
    return count;
}

void sortResumes(Resume *resumes, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (resumes[j].score < resumes[j + 1].score) {
                Resume temp = resumes[j];
                resumes[j] = resumes[j + 1];
                resumes[j + 1] = temp;
            }
        }
    }
}

// Add search functionality
Resume* searchResumeByName(Resume *resumes, int count, const char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(resumes[i].name, name) == 0) {
            return &resumes[i];
        }
    }
    return NULL;
}