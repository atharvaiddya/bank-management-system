#include "onboarding.h"
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
    u.accno = gen_acc();
}

void login(){

}