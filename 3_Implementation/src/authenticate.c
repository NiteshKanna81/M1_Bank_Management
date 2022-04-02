#include "Bank_structure.h"
extern int check_data(char name[],char Acc_no[12],long int* ph_no,float* amount);
extern int create_acc(struct User usr);
extern void login(char Acc_no[],char pass[]);
void Register_Acc(){
    system("clear");
    char def;
    User usr;
    printf("Enter your Account number :\t\t");
    scanf("%s",usr.Acc_no);
    printf("Enter your name :\t\t\t");
    scanf("%c",&def);
    scanf("%[^\n]%*c",usr.name);
    printf("Enter your password :\t\t\t");
    scanf("%s",usr.pass);
    printf("Enter your phone number :\t\t");
    scanf("%ld",&usr.ph_no);
    printf("Enter your address :\t\t\t");
    scanf("%c",&def);
    scanf("%[^\n]%*c",usr.address);
    printf("Enter Account Balance :\t\t\t");
    scanf("%f",&usr.amount);
    if(check_data(usr.name,usr.Acc_no,&usr.ph_no,&usr.amount)==1){
        printf("Account already Exist\n\n");
        printf("Do you want to continue? [y/n] :\t");
        scanf("%c",&def);
        if(def=='y'){
            Register_Acc();
        }
    }
    else{
        if(create_acc(usr)==1){
            printf("Account created succesfully\n\n");
        }
    }
}
void Login_Acc(){
    system("clear");
    char Acc_no[20],pass[20];
    printf("Enter your Account number :\t");
    scanf("%s",Acc_no);
    printf("Enter the Password :\t\t");
    scanf("%s",pass);
    login(Acc_no,pass);
}