#include "Bank_structure.h"
int create_acc(struct User usr){
    FILE *fp;
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