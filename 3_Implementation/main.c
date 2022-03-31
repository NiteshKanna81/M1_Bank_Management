#include "Bank_structure.h"
extern void Register_Acc();
extern void Login_Acc();
extern void test_code();
int main(){
    system("clear");
    int choice;
    char cond='y';
    while(cond=='y'){
        system("clear");
        printf("\n\n\n\t\t\t WELCOME TO THE ABC BANK\n\n");
        printf("Press 1 to Register Account\n");
        printf("Press 2 to Login\n");
        printf("Press 3 to exit\n\n");
        printf("Enter your choice :\t\t");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                Register_Acc();
                break;
            case 2:
                Login_Acc();
                break;
            case 3:
                system("clear");
                cond='n';
                break;
            default:
                printf("Invalid input...\n");
        }
    }
}