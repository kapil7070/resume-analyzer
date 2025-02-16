#include "../header/scoring.h"
#include "../header/utils.h"
#include <string.h>

int score_resume(const Resume* resume, const Job* job) {
    int score = 0;
    
    // Education match (30 points).
    if (strcasestr_custom(resume->education, job->requiredEducation) != NULL) {
        score += 30;
    }
    
    // Experience match (40 points).
    if (resume->experience >= job->minExperience) {
        score += 40;
    } else if (job->minExperience > 0) {
        score += (resume->experience * 40) / job->minExperience;
    }
    
    // Skills match (30 points, distributed equally).
    int pointsPerSkill = (job->requiredSkillCount > 0) ? (30 / job->requiredSkillCount) : 0;
    for (int i = 0; i < job->requiredSkillCount; i++) {
        for (int j = 0; j < resume->skillCount; j++) {
            if (strcasecmp(job->requiredSkills[i], resume->skills[j]) == 0) {
                score += pointsPerSkill;
                break;
            }
        }
    }
    
    return score;
}
