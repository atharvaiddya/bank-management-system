#include "../include/onboarding.h"
#include<stdio.h>

int gen_acc(){
    FILE *fp = fopen("data/last_acc.txt", "r");
    int buffer;
    fscanf(fp, "%d", &buffer);
    printf("Your account number is: %d", buffer);
    fclose(fp);
    fp = fopen("data/last_acc.txt", "w");
    fprintf(fp, "%d", buffer+1);
    fclose(fp);
    return buffer;
}

void create_acc(){
    struct user u;
    int confirm, confpin;
    while(1){
        printf("Enter your first name: ");
        scanf("%s", u.name);

        printf("Enter your email ID: ");
        scanf("%s", u.email);

        printf("Enter your occupation: ");
        scanf("%s", u.occupation);
        
        printf("Set your 4 digit PIN: ");
        scanf("%d", &u.pin);
        
        while(u.pin < 1000 || u.pin > 9999){
            if(u.pin >= 1000 && u.pin <= 9999){
                break;
            }
            else{
                printf("Invalid PIN. Try again: ");
                scanf("%d", &u.pin);
            }
        }
        
        printf("Confirm PIN: ");
        scanf("%d", &confpin);

        while(1){
            if(confpin == u.pin){
                printf("PIN set successfully.");
                break;
            }
            else{
                printf("PIN does not match. Confirm PIN: ");
                scanf("%d", &confpin);
            }
        }
        
        printf("Please carefully check that the credentials you've entered are correct:\n"
               "Name      : %s\n"
               "Email ID  : %s\n"
               "Occupation: %s\n",
               u.name, u.email, u.occupation);

        printf("Press 1 to confirm, 0 to re-enter: ");
        scanf("%d", &confirm);
        if(confirm==1){
            break;
        }
    }
    u.accno = gen_acc();

    char filename[100];
    sprintf(filename, "data/users/%d.txt", u.accno);
    
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "Name: %s\nEmail: %s\nOccupation: %s\nPIN: %d", 
        u.name, u.email, u.occupation, u.pin);
    fclose(fp);

}

void login(){
    struct user u;

    printf("Enter your account number: ");
    scanf("%d", &u.accno);
    char filename[100];
    sprintf(filename, "data/users/%d.txt", u.accno);
    FILE *fp = fopen(filename, "r");
     if (fp == NULL) {
        printf("Account not found.\n");
        return;
    }
    char buffer[255];
    fclose(fp);

}