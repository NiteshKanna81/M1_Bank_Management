#include "Bank_structure.h"
extern void view_detail(char Acc[]);
extern void Deposite_Amount(char Acc[]);
extern void withdraw_amount(char Acc[]);
extern void transfer_amount(char Acc[]);
extern void change_pass(char Acc[]);
int user_action(char acc_no[]){
    system("clear");
    FILE *fp;
    User usr;
    fp=fopen(acc_no,"r");
    fread(&usr,sizeof(struct User),1,fp);
    fclose(fp);
    printf("\n\n\n\t\t\tWelcome %s\n\n",usr.name);
    char cond='y';
    while(cond=='y'){
        int choice;
        printf("Press 1 to View account details\n");
        printf("Press 2 to Deposite amount\n");
        printf("Press 3 to withdraw amount\n");
        printf("Press 4 to transfer amount\n");
        printf("Press 5 to change password\n");
        printf("Press 6 to Logout\n\n");
        printf("Enter your choice :\t\t");
        scanf("%d",&choice);
        system("clear");
        switch(choice){
            case 1:
                view_detail(acc_no);
                break;
            case 2:
                Deposite_Amount(acc_no);
                break;
            case 3:
                withdraw_amount(acc_no);
                break;
            case 4:
                transfer_amount(acc_no);
                break;
            case 5:
                change_pass(acc_no);
                break;
            case 6:
                system("clear");
                cond='n';
                break;
            default:
                printf("Invalid input\n");
                break;
        }
        if(cond=='y'){
            printf("Do you want to continue? [y/n] :\t");
            scanf("%c%c",&cond,&cond);
            system("clear");
        }
    }
}