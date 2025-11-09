#include "onboarding.h"
#include<stdio.h>

void gen_acc(){
    FILE *pF = fopen("data/last_acc.txt", "r");
    int buffer;
    fscanf(pF, "%d", &buffer);
    fclose(pF);
}

void create_acc(){
    struct user u;
    int confirm;
    while(1){
        printf("Enter your first name: ");
        scanf("%s", u.name);

        printf("Enter your email ID: ");
        scanf("%s", u.email);

        printf("Enter your occupation: ");
        scanf("%s", u.occupation);

        printf("Set your PIN: ");
        scanf("%s", u.pin);

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
}

void login(){

}