#include "Bank_structure.h"
#include "Bank_Function.h"
int check_data(char name[],char Acc_no[],long int* ph_no,float* amount){
    char def;
    while(1){
        if(check_Name(name)==1){
            break;
        }
        else{
            printf("Your name is invalid!!\n\n");
            printf("Enter your name :\t\t\t");
            scanf("%c",&def);
            scanf("%[^\n]%*c",name);
            continue;
        }
    }
    while(1){
        if(check_Acc_no(Acc_no)==1){
            break;
        }
        else{
            printf("Invalid Account number!!\n\n");
            printf("Enter your Account number :\t\t\t");
            scanf("%s",Acc_no);
            continue;
        }
    }
    while(1){
        long int dup_no=*ph_no;
        if(check_Ph_no(dup_no)==1){
            break;
        }
        else{
            printf("Invalid phone number!!\n\n");
            printf("Enter your phone number :\t\t\t");
            scanf("%ld",&*ph_no);
            continue;
        }
    }
    while(1){
        float amo=*amount;
        if(check_amount(amo)!=1){
            printf("Minimum Account balance is 1000\n\n");
            printf("Enter your intital amount :\t\t\t");
            scanf("%f",&*amount);
            continue;
        }
        else{
            break;
        }
    }
    return 1;
}