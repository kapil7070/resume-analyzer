#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include "resume.h"

// Function prototypes for utility functions
void clearInputBuffer(void);
void drawBox(int width, int height);
void drawLine(int width);
void centerText(const char *text, int width);
void printFormattedSection(const char *title, const char *content);
int getIntInput(const char *prompt, int min, int max);
float getFloatInput(const char *prompt, float min, float max);
void getString(char *buffer, int size, const char *prompt);

#endif // UTILS_H
