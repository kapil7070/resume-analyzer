#ifndef SCORING_H
#define SCORING_H

#include "resume.h"
#include "job.h"

// Computes and returns a score for a given resume and job.
int score_resume(const Resume* resume, const Job* job);

#endif // SCORING_H
