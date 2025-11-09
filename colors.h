#ifndef COLORS_H
#define COLORS_H

#include <stdio.h>

// Enable colors on Windows (call once at program start)
#ifdef _WIN32
#include <windows.h>
// Define ENABLE_VIRTUAL_TERMINAL_PROCESSING if not already defined (for older MinGW)
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
#endif
void enableColors(void);  // Call this once at program start


// Colors 
#define RESET   "\033[0m"   // Reset to default color
#define RED     "\033[91m"  //Error
#define GREEN   "\033[92m"  //Success
#define YELLOW  "\033[93m"  //Warning  
#define BLUE    "\033[94m"  //Display
#define MAGENTA "\033[95m"  //Welcome Screen
#define CYAN    "\033[96m"  //Info
#define WHITE   "\033[97m"

// Text Style
#define BOLD    "\033[1m"    // Bold text

// ============================================
// CONVENIENCE FUNCTIONS
// ============================================
void printSuccess(const char* text);          // 1. Green success message
void printError(const char* text);            // 2: Red error message
void printInfo(const char* text);             // 3: Cyan info message
void printWarning(const char* text);          // 4: Yellow warning message
void printDisplay(const char* text);          // 5: Blue display message
void printWelcomeScreen(const char* text);    // 6: Magenta welcome screen 
void printTitle(const char* text);            // 7: Title in Bold and Cyan
#endif
