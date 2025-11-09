// colors.c - Color function implementations

#include "colors.h"

// Enable colors on Windows (does nothing on Linux/Mac)
void enableColors(void) {
    #ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE) {
        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode)) {
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
        }
    }
    #endif
} //idk what this means but it's here

// ============================================
// CONVENIENCE FUNCTIONS Definitions
// ============================================

// 1. Print success message in GREEN
void printSuccess(const char* text) {
    printf("%s%s%s", GREEN, text, RESET);
}

// 2. Print error message in RED   
void printError(const char* text) {
    printf("%s%s%s", RED, text, RESET);
}

    // 3. Print info message in CYAN
void printInfo(const char* text) {
    printf("%s%s%s", CYAN, text, RESET);
}

// 4. Print warning message in YELLOW
void printWarning(const char* text) {
    printf("%s%s%s", YELLOW, text, RESET);
}

// 5. Print display message in BLUE
void printDisplay(const char* text) {
    printf("%s%s%s", BLUE, text, RESET);
}

// 6. Print welcome screen in MAGENTA
void printWelcomeScreen(const char* text) {
    printf("%s%s%s", MAGENTA, text, RESET);
}

// 7. Print title in bold and CYAN
void printTitle(const char* text) {
    printf("%s%s%s", CYAN, BOLD, text, RESET);
}