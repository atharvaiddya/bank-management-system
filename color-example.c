#include "colors.h"

int main() {
    enableColors();
    
    //All Colors Test
    printf(YELLOW"Yellow\n" RESET);
    printf(BLUE"Blue\n" RESET);
    printf(MAGENTA"Magenta\n" RESET);
    printf(CYAN"Cyan\n" RESET);
    printf(WHITE"White\n" RESET);

    //All Functions Test
    printSuccess("Success!\n");
    printError("Error!\n");
    printInfo("Info!\n");
    printWarning("Warning!\n");
    printDisplay("Display!\n");
    printWelcomeScreen("Welcome Screen!\n");
    printTitle("Title!\n");
    return 0;
}