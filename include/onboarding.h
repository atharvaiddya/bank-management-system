#ifndef ONBOARDING_H
#define ONBOARDING_H

struct user {
    int accno;
    char name[50];
    char email[50];
    char occupation[50];
    int pin;
};

void create_acc();
void login();
int gen_acc();
void save_user();
int user_exists();

#endif