#include "../include/utils.h"

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void drawBox(int width, int height) {
    printf("┌");
    for (int i = 0; i < width - 2; i++) printf("─");
    printf("┐\n");

    for (int i = 0; i < height - 2; i++) {
        printf("│");
        for (int j = 0; j < width - 2; j++) printf(" ");
        printf("│\n");
    }

    printf("└");
    for (int i = 0; i < width - 2; i++) printf("─");
    printf("┘\n");
}

void drawLine(int width) {
    for (int i = 0; i < width; i++) printf("─");
    printf("\n");
}

void centerText(const char *text, int width) {
    int padding = (width - strlen(text)) / 2;
    for (int i = 0; i < padding; i++) printf(" ");
    printf("%s\n", text);
}

void printFormattedSection(const char *title, const char *content) {
    printf("│ %-15s │ %-40s │\n", title, content);
}

int getIntInput(const char *prompt, int min, int max) {
    int value;
    do {
        printf("%s", prompt);
        if (scanf("%d", &value) != 1) {
            clearInputBuffer();
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        clearInputBuffer();
        if (value < min || value > max) {
            printf("Please enter a value between %d and %d.\n", min, max);
        }
    } while (value < min || value > max);
    return value;
}

float getFloatInput(const char *prompt, float min, float max) {
    float value;
    do {
        printf("%s", prompt);
        if (scanf("%f", &value) != 1) {
            clearInputBuffer();
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        clearInputBuffer();
        if (value < min || value > max) {
            printf("Please enter a value between %.2f and %.2f.\n", min, max);
        }
    } while (value < min || value > max);
    return value;
}

void getString(char *buffer, int size, const char *prompt) {
    do {
        printf("%s", prompt);
        if (fgets(buffer, size, stdin) != NULL) {
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len-1] == '\n') {
                buffer[len-1] = '\0';
                len--;
            }
            if (len > 0) {
                return;
            }
        }
        printf("Input cannot be empty. Please try again.\n");
    } while (1);
}