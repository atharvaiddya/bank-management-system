#ifndef ONBOARDING_H
#define ONBOARDING_H

struct user {
    int accno;
    char name[50];
    char email[50];
    char occupation[50];
    int pin[10];
};

void create_account();
void login();
void gen_acc();
void save_user();
int user_exists();

#endif