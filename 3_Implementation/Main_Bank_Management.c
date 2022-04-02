#include "Bank_structure.h"
#include "Bank_Function.h"
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
int user_action(char acc_no[]){
    system("clear");
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
int create_acc(struct User usr){
    char filename[20]="account/";
    strcat(filename,usr.Acc_no);
    fp=fopen(strcat(filename,".dat"),"w");
    fwrite(&usr,sizeof(struct User),1,fp);
    if(fwrite != 0){
        return 1;
    }
    else{
        return 0;
    }
}
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
void login(char Acc_no[],char pass[]){
    User usr;
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