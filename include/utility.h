// utility.h - Utility functions for banking system

#ifndef UTILITY_H
#define UTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
#endif

// ============================================
// BASIC UTILITY FUNCTIONS
// ============================================

// Clear the screen
void clearScreen(void);

// Wait for user to press Enter
void pauseScreen(void);

// Sleep/delay function (milliseconds)
void sleep_ms(int milliseconds);

// Get a single character input (without pressing Enter)
char getCharInput(void);

// ============================================
// INPUT VALIDATION FUNCTIONS
// ============================================

// Get integer input with validation
int getIntInput(const char* prompt);

// Get positive integer input (for amounts, etc.)
int getPositiveIntInput(const char* prompt);

// Get float input with validation
float getFloatInput(const char* prompt);

// Get positive float input (for money amounts)
float getPositiveFloatInput(const char* prompt);

// Get string input (removes newline)
void getStringInput(char* buffer, int size, const char* prompt);

// Get confirmation (Y/N)
int confirmAction(const char* message);

// ============================================
// FORMATTING FUNCTIONS
// ============================================

// Format currency with ₹ symbol
void formatCurrency(float amount, char* buffer, int size);

// Format account number (show only last 4 digits: XX1234)
void formatAccountNumber(const char* accountNumber, char* buffer, int size);

// Format date (DD/MM/YYYY)
void formatDate(int day, int month, int year, char* buffer, int size);

// ============================================
// VALIDATION FUNCTIONS
// ============================================

// Validate account number (check if it's valid format)
int isValidAccountNumber(const char* accountNumber);

// Validate amount (positive and within limits)
int isValidAmount(float amount, float min, float max);

// Validate email format (basic)
int isValidEmail(const char* email);

// Validate phone number (10 digits)
int isValidPhone(const char* phone);

// ============================================
// ANIMATION FUNCTIONS (COOL STUFF!)
// ============================================

// Loading animation with spinner
void loadingAnimation(const char* message, int duration_ms);

// Loading animation with dots
void loadingDots(const char* message, int dot_count);

// Progress bar animation
void progressBar(const char* message, int duration_ms);

// Typewriter effect (print text character by character)
void typewriterEffect(const char* text, int delay_ms);

// Welcome screen animation
void welcomeAnimation(void);

// Success animation with checkmark
void successAnimation(const char* message);

// Transaction processing animation
void transactionProcessing(const char* message);

// Countdown animation
void countdown(int seconds);

// ============================================
// DISPLAY FUNCTIONS
// ============================================

// Print a line separator
void printSeparator(char character, int length);

// Print centered text
void printCentered(const char* text, int width);



#endif // UTILITY_H

