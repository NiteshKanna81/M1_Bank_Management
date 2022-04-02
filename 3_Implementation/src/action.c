#include "Bank_structure.h"
FILE *fp;
void view_detail(char Acc[]){
    User usr;
    fp=fopen(Acc,"r");
    fread(&usr,sizeof(struct User),1,fp);
    fclose(fp);
    printf("Name :\t\t\t\t%s\n",usr.name);
    printf("Account number :\t\t%s\n",usr.Acc_no);
    printf("Address :\t\t\t%s\n",usr.address);
    printf("Phone number :\t\t\t%ld\n",usr.ph_no);
    printf("Account balance :\t\t%.2f\n",usr.amount);
}
void Deposite_Amount(char Acc[]){
    float amount;
    User usr;
    fp=fopen(Acc,"r");
    fread(&usr,sizeof(struct User),1,fp);
    fclose(fp);
    printf("Enter the amount to Depostie :\t\t");
    scanf("%f",&amount);
    usr.amount+=amount;
    fp=fopen(Acc,"w");
    fwrite(&usr,sizeof(struct User),1,fp);
    fclose(fp);
    printf("Amount deposited successfully\n\n");
    printf("Your Current account balance :\t\t%f\n",usr.amount);
}
void withdraw_amount(char Acc[]){
    float amount;
    User usr;
    fp=fopen(Acc,"r");
    fread(&usr,sizeof(struct User),1,fp);
    fclose(fp);
    printf("Enter the amount to With Draw :\t\t");
    scanf("%f",&amount);
    if((usr.amount-amount)<=1000){
        printf("Insufficient balance or your are withdrawing less than minimun balance!!\n\n");
    }
    else{
        usr.amount-=amount;
        fp=fopen(Acc,"w");
        fwrite(&usr,sizeof(struct User),1,fp);
        fclose(fp);
        printf("Amount Withdrawed successfully\n\n");
        printf("Your Current account balance :\t\t%f\n",usr.amount);
    }
}
void transfer_amount(char Acc[]){
    User usr1,usr2;
    fp=fopen(Acc,"r");
    fread(&usr1,sizeof(struct User),1,fp);
    fclose(fp);
    char Acc_no[15];
    printf("Enter the account number to transer to :\t\t");
    scanf("%s",Acc_no);
    char filename[30]="Account/";
    strcat(filename,Acc_no);
    fp=fopen(strcat(filename,".dat"),"r");
    if(fp==NULL){
        printf("Account number not registered\n");
    }
    fread(&usr2,sizeof(struct User),1,fp);
    fclose(fp);
    float amount;
    printf("Enter the amount to transfer :\t\t");
    scanf("%f",&amount);
    if((usr1.amount-amount)<=1000){
        printf("Insufficient balance or your are withdrawing less than minimun balance!!\n\n");
    }
    else{
        usr1.amount-=amount;
        usr2.amount+=amount;
        fp=fopen(Acc,"w");
        fwrite(&usr1,sizeof(struct User),1,fp);
        fclose(fp);
        fp=fopen(filename,"w");
        fwrite(&usr2,sizeof(struct User),1,fp);
        fclose(fp);
        printf("Amount transfered succesfully\n");
        printf("Your account balance :%.2f\t\t\n\n",usr1.amount);
    }
}
void change_pass(char Acc[]){
    User usr;
    fp=fopen(Acc,"r");
    fread(&usr,sizeof(struct User),1,fp);
    fclose(fp);
    char pass[20];
    printf("Enter the new password :\t\t");
    scanf("%s",pass);
    strcpy(usr.pass,pass);
    fp=fopen(Acc,"w");
    fwrite(&usr,sizeof(struct User),1,fp);
    fclose(fp);
    printf("Password changed succesfully\n");
}