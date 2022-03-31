#ifndef _BANK_STRUCTURE_H_
#define _BANK_STRUCTURE_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
typedef struct User{
    char name[50];
    char pass[20];
    char address[50];
    long int ph_no;
    char Acc_no[12];
    float amount;
}User;
#endif