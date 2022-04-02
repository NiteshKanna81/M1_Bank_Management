#ifndef _BANK_FUNCTION_H_
#define _BANK_FUNCTION_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int check_Name(char name[]){
    for(int i=0;i<strlen(name);i++){
        if(name[i]==' '){}
        else if(isalpha(name[i])==0){
            return 0;
        }
    }
    return 1;
}
int check_Acc_no(char Acc_no[]){
    int Acc_len=strlen(Acc_no);
    if(Acc_len==12){
        for(int i=0;i<Acc_len;i++){
            if(isdigit(Acc_no[i])==0){
                return 0;
            }
        }
    }
    else{
        return 0;
    }
    return 1;
}
int check_Ph_no(long int phno){
    int count=0;
    long int dup_no=phno;
    do {
        dup_no/=10;
        ++count;
    } while(dup_no!=0);
    if(count==10){
        return 1;
    }
    else{
        return 0;
    }
}
int check_amount(float amount){
    if(amount>=1000.0){
        return 1;
    }
    else{
        return 0;
    }
}
#endif