#include "Bank_structure.h"
extern void user_action(char acc_no[]);
void login(char Acc_no[],char pass[]){
    User usr;
    FILE *fp;
    char filename[20]="Account/";
    strcat(filename,Acc_no);
    fp=fopen(strcat(filename,".dat"),"r");
    if(fp==NULL){
        printf("Account number not registered\n");
    }
    else{
        fread(&usr,sizeof(struct User),1,fp);
        fclose(fp);
        if(!strcmp(pass,usr.pass)){
            user_action(filename);
        }
        else{
            printf("Username or password in incorrect\n");
        }
    }
}