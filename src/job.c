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
    } else if (strcasecmp(jobTitle, "Data Scientist") == 0) {
        strcpy(job.requiredEducation, "Master");
        job.minExperience = 3;
        job.requiredSkillCount = 5;
        strcpy(job.requiredSkills[0], "Python");
        strcpy(job.requiredSkills[1], "R");
        strcpy(job.requiredSkills[2], "Machine Learning");
        strcpy(job.requiredSkills[3], "Data Visualization");
        strcpy(job.requiredSkills[4], "SQL");
    } else if (strcasecmp(jobTitle, "Cyber Security Analyst") == 0) {
        strcpy(job.requiredEducation, "Bachelor");
        job.minExperience = 2;
        job.requiredSkillCount = 4;
        strcpy(job.requiredSkills[0], "Network Security");
        strcpy(job.requiredSkills[1], "Penetration Testing");
        strcpy(job.requiredSkills[2], "Ethical Hacking");
        strcpy(job.requiredSkills[3], "SIEM Tools");
    } else if (strcasecmp(jobTitle, "Cloud Engineer") == 0) {
        strcpy(job.requiredEducation, "Bachelor");
        job.minExperience = 2;
        job.requiredSkillCount = 5;
        strcpy(job.requiredSkills[0], "AWS");
        strcpy(job.requiredSkills[1], "Azure");
        strcpy(job.requiredSkills[2], "Docker");
        strcpy(job.requiredSkills[3], "Kubernetes");
        strcpy(job.requiredSkills[4], "Terraform");
    } else if (strcasecmp(jobTitle, "DevOps Engineer") == 0) {
        strcpy(job.requiredEducation, "Bachelor");
        job.minExperience = 3;
        job.requiredSkillCount = 5;
        strcpy(job.requiredSkills[0], "CI/CD");
        strcpy(job.requiredSkills[1], "Jenkins");
        strcpy(job.requiredSkills[2], "Ansible");
        strcpy(job.requiredSkills[3], "Kubernetes");
        strcpy(job.requiredSkills[4], "Linux Administration");
    } else if (strcasecmp(jobTitle, "AI Engineer") == 0) {
        strcpy(job.requiredEducation, "Master");
        job.minExperience = 3;
        job.requiredSkillCount = 5;
        strcpy(job.requiredSkills[0], "Deep Learning");
        strcpy(job.requiredSkills[1], "TensorFlow");
        strcpy(job.requiredSkills[2], "NLP");
        strcpy(job.requiredSkills[3], "Python");
        strcpy(job.requiredSkills[4], "Big Data");
    } else if (strcasecmp(jobTitle, "Frontend Developer") == 0) {
        strcpy(job.requiredEducation, "Bachelor");
        job.minExperience = 2;
        job.requiredSkillCount = 5;
        strcpy(job.requiredSkills[0], "HTML");
        strcpy(job.requiredSkills[1], "CSS");
        strcpy(job.requiredSkills[2], "JavaScript");
        strcpy(job.requiredSkills[3], "React");
        strcpy(job.requiredSkills[4], "TypeScript");
    } else if (strcasecmp(jobTitle, "Backend Developer") == 0) {
        strcpy(job.requiredEducation, "Bachelor");
        job.minExperience = 3;
        job.requiredSkillCount = 5;
        strcpy(job.requiredSkills[0], "Node.js");
        strcpy(job.requiredSkills[1], "Express.js");
        strcpy(job.requiredSkills[2], "MongoDB");
        strcpy(job.requiredSkills[3], "SQL");
        strcpy(job.requiredSkills[4], "Microservices");
    } else if (strcasecmp(jobTitle, "Full Stack Developer") == 0) {
        strcpy(job.requiredEducation, "Bachelor");
        job.minExperience = 3;
        job.requiredSkillCount = 6;
        strcpy(job.requiredSkills[0], "React");
        strcpy(job.requiredSkills[1], "Node.js");
        strcpy(job.requiredSkills[2], "Express.js");
        strcpy(job.requiredSkills[3], "MongoDB");
        strcpy(job.requiredSkills[4], "REST APIs");
        strcpy(job.requiredSkills[5], "TypeScript");
    } else if (strcasecmp(jobTitle, "Product Manager") == 0) {
        strcpy(job.requiredEducation, "MBA");
        job.minExperience = 5;
        job.requiredSkillCount = 5;
        strcpy(job.requiredSkills[0], "Agile Methodologies");
        strcpy(job.requiredSkills[1], "Scrum");
        strcpy(job.requiredSkills[2], "Market Research");
        strcpy(job.requiredSkills[3], "Customer Insights");
        strcpy(job.requiredSkills[4], "Strategic Planning");
    } else if (strcasecmp(jobTitle, "Network Engineer") == 0) {
        strcpy(job.requiredEducation, "Bachelor");
        job.minExperience = 3;
        job.requiredSkillCount = 4;
        strcpy(job.requiredSkills[0], "Routing");
        strcpy(job.requiredSkills[1], "Switching");
        strcpy(job.requiredSkills[2], "Firewall Management");
        strcpy(job.requiredSkills[3], "Cloud Networking");
    } else if (strcasecmp(jobTitle, "QA Engineer") == 0) {
        strcpy(job.requiredEducation, "Bachelor");
        job.minExperience = 2;
        job.requiredSkillCount = 5;
        strcpy(job.requiredSkills[0], "Automated Testing");
        strcpy(job.requiredSkills[1], "Selenium");
        strcpy(job.requiredSkills[2], "Manual Testing");
        strcpy(job.requiredSkills[3], "JIRA");
        strcpy(job.requiredSkills[4], "API Testing");
    } else if (strcasecmp(jobTitle, "Game Developer") == 0) {
        strcpy(job.requiredEducation, "Bachelor");
        job.minExperience = 3;
        job.requiredSkillCount = 4;
        strcpy(job.requiredSkills[0], "Unity");
        strcpy(job.requiredSkills[1], "Unreal Engine");
        strcpy(job.requiredSkills[2], "C#");
        strcpy(job.requiredSkills[3], "C++");
    } else if (strcasecmp(jobTitle, "Database Administrator") == 0) {
        strcpy(job.requiredEducation, "Bachelor");
        job.minExperience = 3;
        job.requiredSkillCount = 4;
        strcpy(job.requiredSkills[0], "SQL");
        strcpy(job.requiredSkills[1], "PostgreSQL");
        strcpy(job.requiredSkills[2], "Database Optimization");
        strcpy(job.requiredSkills[3], "NoSQL");
    } else if (strcasecmp(jobTitle, "IT Support Specialist") == 0) {
        strcpy(job.requiredEducation, "Associate");
        job.minExperience = 1;
        job.requiredSkillCount = 3;
        strcpy(job.requiredSkills[0], "Technical Troubleshooting");
        strcpy(job.requiredSkills[1], "Customer Support");
        strcpy(job.requiredSkills[2], "Windows Administration");
    } else {
        // Default requirements for unspecified jobs
        strcpy(job.requiredEducation, "Bachelor");
        job.minExperience = 1;
        job.requiredSkillCount = 2;
        strcpy(job.requiredSkills[0], "Communication");
        strcpy(job.requiredSkills[1], "Teamwork");
    }
    
    return job;
}
