/*
 * utility_test.c
 * Comprehensive interactive test suite for all utility & color functions.
 * Each function is numbered for clear tracing and debugging.
 */

 #include "utility.h"
 #include "colors.h"
 #include <stdio.h>
 
 /* === Helper Functions === */
 void printSection(int num, const char *title) {
     printSeparator('=', 60);
     printf("[%02d] %s\n", num, title);
     printSeparator('=', 60);
     printf("\n");
 }
 
 void waitForEnter() {
     printf("\nPress ENTER to continue...");
     getchar();
 }
 
 /* === MAIN === */
 int main() {
     enableColors();
     clearScreen();
 
     printSection(0, "UTILITY FUNCTION TEST SUITE");
 
     /* =========================================================
      * 1–3: Basic Utility Functions
      * ========================================================= */
     printSection(1, "BASIC UTILITY FUNCTIONS");
 
     printf("1. sleep_ms(2000) - Waiting 2 seconds...\n");
     sleep_ms(2000);
     printSuccess("✓ Sleep complete.\n\n");
 
     printf("2. clearScreen() - Clearing screen in 2 seconds...\n");
     sleep_ms(2000);
     clearScreen();
     printSuccess("✓ Screen cleared.\n\n");
 
     /* =========================================================
      * 4–8: Input Functions
      * ========================================================= */
     printSection(4, "INPUT VALIDATION FUNCTIONS");
 
     int age = getIntInput("4. Enter your age: ");
     printf("You entered: %d\n\n", age);
 
     int qty = getPositiveIntInput("5. Enter positive quantity: ");
     printf("Quantity: %d\n\n", qty);
 
     float rate = getFloatInput("6. Enter rate (float): ");
     printf("Rate: %.2f\n\n", rate);
 
     float deposit = getPositiveFloatInput("7. Enter positive deposit amount: ");
     printf("Deposit: %.2f\n\n", deposit);
 
     char name[50];
     getStringInput(name, sizeof(name), "8. Enter your name: ");
     printf("Name entered: %s\n\n", name);
 
     /* =========================================================
      * 9: Date Formatting
      * ========================================================= */
     printSection(9, "DATE FORMATTING");
 
     int day = getIntInput("Enter day (1–31): ");
     int month = getIntInput("Enter month (1–12): ");
     int year = getIntInput("Enter year (e.g., 2025): ");
     char formattedDate[20];
     formatDate(day, month, year, formattedDate, sizeof(formattedDate));
     printf("9. Formatted date: %s\n\n", formattedDate);
 
     /* =========================================================
      * 10–11: Account Validation & Formatting
      * ========================================================= */
     printSection(10, "ACCOUNT NUMBER VALIDATION AND FORMATTING");
 
     char acc[50];
     getStringInput(acc, sizeof(acc), "10. Enter account number (6–12 digits): ");
     if (isValidAccountNumber(acc)) {
         printSuccess("✓ Valid account number.\n");
         char masked[20];
         formatAccountNumber(acc, masked, sizeof(masked));
         printf("11. Masked (formatted) account: %s\n\n", masked);
     } else {
         printError("✗ Invalid account number! Must be 6–12 digits only.\n\n");
     }
 
     /* =========================================================
      * 12–13: Email and Phone Validation
      * ========================================================= */
     printSection(12, "EMAIL AND PHONE VALIDATION");
 
     char email[50];
     getStringInput(email, sizeof(email), "12. Enter your email: ");
     if (isValidEmail(email))
         printSuccess("✓ Valid email format.\n");
     else
         printError("✗ Invalid email format.\n");
 
     char phone[20];
     getStringInput(phone, sizeof(phone), "13. Enter phone number (10 digits): ");
     if (isValidPhone(phone))
         printSuccess("✓ Valid phone number.\n\n");
     else
         printError("✗ Invalid phone number.\n\n");
 
     /* =========================================================
      * 14: Amount Validation
      * ========================================================= */
     printSection(14, "AMOUNT VALIDATION");
 
     float amount = getPositiveFloatInput("14. Enter amount to test (₹): ");
     if (isValidAmount(amount, 100.0, 10000.0))
         printSuccess("✓ Amount within valid range (₹100–₹10,000).\n\n");
     else
         printError("✗ Amount out of range (₹100–₹10,000).\n\n");
 
     /* =========================================================
      * 15: Confirmation Prompt
      * ========================================================= */
     printSection(15, "CONFIRMATION PROMPT");
 
     if (confirmAction("15. Do you want to continue?"))
         printSuccess("✓ User confirmed.\n\n");
     else
         printError("✗ User cancelled.\n\n");
 
     /* =========================================================
      * 16–18: Formatting Functions
      * ========================================================= */
     printSection(16, "FORMATTING FUNCTIONS");
 
     char currency[50];
     formatCurrency(123456.78, currency, sizeof(currency));
     printf("16. Formatted currency: %s\n", currency);
 
     char accountNum[20];
     formatAccountNumber("9876543210", accountNum, sizeof(accountNum));
     printf("17. Formatted account number: %s\n", accountNum);
 
     char dateStr[20];
     formatDate(9, 11, 2025, dateStr, sizeof(dateStr));
     printf("18. Formatted date: %s\n\n", dateStr);
 
     /* =========================================================
      * 19–25: Animation Functions
      * ========================================================= */
     printSection(19, "ANIMATION FUNCTIONS");
 
     printf("19. Spinner animation (4s)...\n");
     loadingAnimation("Loading", 4000);
     printf("\n");
 
     printf("20. Loading dots (10 dots)...\n");
     loadingDots("Processing", 10);
     printf("\n");
 
     printf("21. Progress bar (5s)...\n");
     progressBar("Operation Progress", 5000);
     printf("\n");
 
     printf("22. Typewriter effect...\n");
     typewriterEffect("Typewriter effect example!\n", 100);
     printf("\n");
 
     printf("23. Success animation...\n");
     successAnimation("Operation successful!");
     printf("\n");
 
     printf("24. Transaction processing animation...\n");
     transactionProcessing("Processing transaction");
     printf("\n");
 
     printf("25. Countdown (5 seconds)...\n");
     countdown(5);
     printf("\n");
 
     /* =========================================================
      * 26: Welcome Animation
      * ========================================================= */
     printSection(26, "WELCOME ANIMATION");
 
     welcomeAnimation();
 
     /* =========================================================
      * 27–28: Display Utilities
      * ========================================================= */
     printSection(27, "DISPLAY UTILITIES");
 
     printf("27. Printing separator and centered text...\n\n");
     printSeparator('-', 50);
     printCentered("28. APNA BANK SYSTEM TEST", 50);
     printSeparator('-', 50);
     printf("\n");
 
     /* =========================================================
      * 29–33: Simulated Transaction Example
      * ========================================================= */
     printSection(29, "SIMULATED BANK TRANSACTION");
 
     char recipient[20];
     getStringInput(recipient, sizeof(recipient), "29. Enter recipient account: ");
     if (!isValidAccountNumber(recipient)) {
         printError("✗ Invalid recipient account number.\n");
         return 1;
     }
 
     float sendAmt = getPositiveFloatInput("30. Enter amount to send: ₹");
     if (!isValidAmount(sendAmt, 100.0, 50000.0)) {
         printError("✗ Amount out of range (₹100–₹50,000).\n");
         return 1;
     }
 
     if (!confirmAction("31. Confirm transaction?")) {
         printError("✗ Transaction cancelled by user.\n");
         return 1;
     }
 
     printf("32. Processing transaction...\n");
     transactionProcessing("Processing your transaction");
 
     char formattedAcc[20], formattedAmt[50];
     formatAccountNumber(recipient, formattedAcc, sizeof(formattedAcc));
     formatCurrency(sendAmt, formattedAmt, sizeof(formattedAmt));
 
     successAnimation("33. Transaction Successful!");
     printf("\nRecipient: %s\nAmount: %s\n\n", formattedAcc, formattedAmt);
 
     pauseScreen();
     printSuccess("All function tests completed successfully!\n");
     return 0;
 }
 