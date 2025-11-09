// utility.c - Utility function implementations

#include "utility.h"
#include "colors.h"

// ============================================
// BASIC UTILITY FUNCTIONS
// ============================================

// 1. Clear the screen
//Purpose: Clear the screen

void clearScreen(void) {
    #ifdef _WIN32
    system("cls");  // Windows
    #else
    system("clear");  // Linux/Mac
    #endif
}

// 2. Wait for user to press Enter
//Purpose: Wait for user to press Enter

void pauseScreen(void) {
    printf("\nPress Enter to continue...");
    // Clear input buffer first
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    // Wait for Enter
    getchar();
}

// 3. Sleep/delay function (milliseconds)
//Purpose: Sleep/delay function (milliseconds)

void sleep_ms(int milliseconds) {
    Sleep(milliseconds);  // Windows
}

// 4. Get a single character input (without pressing Enter)
//Purpose: For Y/N answers

char getCharInput(void) {
    return _getch();  // Windows
}

// ============================================
// INPUT VALIDATION FUNCTIONS
// ============================================

// 5. Get integer input with validation
//Purpose: For integer 1, 2, 3, etc. in switch statements

int getIntInput(const char* prompt) {
    int value;
    char buffer[100];
    
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &value) == 1) {
                return value;
            }
        }
        printError("Invalid input! Please enter a valid number.\n");
    }
}

// 6. Get positive integer input
//Purpose: For entering money amounts

int getPositiveIntInput(const char* prompt) {
    int value;
    while (1) {
        value = getIntInput(prompt);
        if (value > 0) {
            return value;
        }
        printError("Please enter a positive number!\n");
    }
}

// Get float input with validation
float getFloatInput(const char* prompt) {
    float value;
    char buffer[100];
    
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%f", &value) == 1) {
                return value;
            }
        }
        printError("Invalid input! Please enter a valid number.\n");
    }
}

// Get positive float input
float getPositiveFloatInput(const char* prompt) {
    float value;
    while (1) {
        value = getFloatInput(prompt);
        if (value > 0) {
            return value;
        }
        printError("Please enter a positive amount!\n");
    }
}

// 7. Get string input (removes newline)
//Purpose: For entering names, addresses, etc.

void getStringInput(char* buffer, int size, const char* prompt) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) != NULL) {
        // Remove newline character if present
        int len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

// 8. Get confirmation (Y/N) answers
//Purpose: For confirming actions

int confirmAction(const char* message) {
    char choice;
    printf("%s (Y/N): ", message);
    choice = getCharInput();
    printf("%c\n", choice);
    return (choice == 'Y' || choice == 'y');
}

// ============================================
// FORMATTING FUNCTIONS
// ============================================

// 9. Format currency with Rs. symbol (₹ symbol gives error in some compilers)
//Purpose: For formatting money amounts 

void formatCurrency(float amount, char* buffer, int size) {
    snprintf(buffer, size, "Rs.%.2f", amount);
}

// 10. Format account number (show only last 4 digits: XX1234)
//Purpose: For formatting account numbers

void formatAccountNumber(const char* accountNumber, char* buffer, int size) {
    int len = strlen(accountNumber);
    if (len <= 4) {
        strncpy(buffer, accountNumber, size - 1);
        buffer[size - 1] = '\0';
    } else {
        snprintf(buffer, size, "XX%s", accountNumber + len - 4);
    }
}

// 11. Format date (DD/MM/YYYY)
//Purpose: For formatting dates

void formatDate(int day, int month, int year, char* buffer, int size) {
    snprintf(buffer, size, "%02d/%02d/%04d", day, month, year);
}

// ============================================
// VALIDATION FUNCTIONS
// ============================================

// Validate account number (check if it's valid format - numbers only, 6-12 digits)

int isValidAccountNumber(const char* accountNumber) {
    int len = strlen(accountNumber);
    if (len < 6 || len > 12) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isdigit(accountNumber[i])) {
            return 0;
        }
    }
    return 1;
}

// Validate amount (positive and within limits)
int isValidAmount(float amount, float min, float max) {
    return (amount >= min && amount <= max);
}

// Validate email format (basic - checks for @ and .)
int isValidEmail(const char* email) {
    int hasAt = 0;
    int hasDot = 0;
    int len = strlen(email);
    
    if (len < 5) return 0;  // Minimum: a@b.c
    
    for (int i = 0; i < len; i++) {
        if (email[i] == '@') hasAt = 1;
        if (hasAt && email[i] == '.') hasDot = 1;
    }
    
    return (hasAt && hasDot);
}

// Validate phone number (10 digits)
int isValidPhone(const char* phone) {
    int len = strlen(phone);
    if (len != 10) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isdigit(phone[i])) {
            return 0;
        }
    }
    return 1;
}

// ============================================
// ANIMATION FUNCTIONS (COOL STUFF!)
// ============================================

// 1.Loading animation with spinner
void loadingAnimation(const char* message, int duration_ms) {
    char spinner[] = {'|', '/', '-', '\\'};
    int spinner_index = 0;
    int iterations = duration_ms / 100;  // Update every 100ms
    
    printf("%s", message);
    fflush(stdout);
    
    for (int i = 0; i < iterations; i++) {
        printf("\b%c", spinner[spinner_index]);
        fflush(stdout);
        spinner_index = (spinner_index + 1) % 4;
        sleep_ms(100);
    }
    printf("\b \n");  // Clear spinner and move to new line
}

// 2. Loading animation with dots
void loadingDots(const char* message, int dot_count) {
    printf("%s", message);
    fflush(stdout);
    
    for (int i = 0; i < dot_count; i++) {
        printf(".");
        fflush(stdout);
        sleep_ms(300);
    }
    printf("\n");
}

// 3. Progress bar animation
void progressBar(const char* message, int duration_ms) {
    int bar_width = 50;
    int steps = 50;
    int step_delay = duration_ms / steps;
    
    printf("%s\n", message);
    printf("[");
    fflush(stdout);
    
    for (int i = 0; i < steps; i++) {
        printf("=");
        fflush(stdout);
        sleep_ms(step_delay);
    }
    printf("] 100%%\n");
}

// 4. Typewriter effect (print text character by character)
void typewriterEffect(const char* text, int delay_ms) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        printf("%c", text[i]);
        fflush(stdout);
        sleep_ms(delay_ms);
    }
}

// 5. Welcome screen animation
void welcomeAnimation(void) {
    clearScreen();
    printf("\n");
    
    // 6.  Animated welcome text
    typewriterEffect("=== WELCOME TO ===\n\n", 50);
    sleep_ms(500);
    
    // 7. Display welcome message with colors
    printf(BOLD MAGENTA);
    typewriterEffect("    BANK MANAGEMENT SYSTEM\n", 30);
    printf(RESET);
    sleep_ms(500);
    
    printf("\n");
    loadingDots("Loading", 3);
    printf("\n");
}

// 8. Success animation with checkmark
void successAnimation(const char* message) {
    printf("\n");
    printSuccess("✓ ");
    typewriterEffect(message, 30);
    printf("\n");
    sleep_ms(500);
}

// 9. Transaction processing animation
void transactionProcessing(const char* message) {
    printf("\n");
    printInfo(message);
    loadingAnimation(" Processing", 2000);
    printf("\n");
}

// 10. Countdown animation
void countdown(int seconds) {
    char buffer[100];
    for (int i = seconds; i > 0; i--) {
        printf("\r");
        snprintf(buffer, sizeof(buffer), "Returning to menu in %d seconds...", i);
        printWarning(buffer);
        fflush(stdout);
        sleep_ms(1000);
    }
    printf("\r");
    printf("                                    ");  // Clear line
    printf("\r");
}

// ============================================
// DISPLAY FUNCTIONS
// ============================================

// Print a line separator
void printSeparator(char character, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", character);
    }
    printf("\n");
}

// Print centered text
void printCentered(const char* text, int width) {
    int len = strlen(text);
    int padding = (width - len) / 2;
    
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }
    printf("%s\n", text);
}

