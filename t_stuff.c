#include<stdio.h>
#include<string.h>

void decrypt(int kl, char*skey, char* key ){
    printf("\n Decryption\n Enter the data\n");
    char data[100], plain[100]={0};
    scanf("%s",&data);
    int row=strlen(data)/kl;

    for(int i=0;i<kl;i++){
        for(int j=0;j<kl;j++){
            if(skey[i]==key[j]){
                int k=i*row;
                for(int r=0;r<row;r++){
                    plain[j+r*kl]=data[r+k];
                }
            }
        }
    }
    printf("plain txt:\n%s",plain);
}

void encrypt(int kl,int j,char* data){
    int c=j;
    while(c<strlen(data)){
        printf("%c",data[c]);
        c+=kl;
    }
}

int main(){
    char data[100];
    char skey[50],key[50]="KING";
    strcpy(skey,key);
    printf("Encryption\nEnter the data:\n");
    scanf("%s",&data);
    int kl=strlen(key);

    for(int i=0;i<kl-1;i++){
        for(int j=0;j<kl-1;j++){
            if(skey[j]>skey[j+1]){
                char t=skey[j];
                skey[j]=skey[j+1];
                skey[j+1]=t;
            }
        }
    }

    for(int i=0;i<kl;i++){
        for(int j=0;j<kl;j++){
            if(skey[i]==key[j]){
                encrypt(kl,j,data);
            }
        }
    }

    decrypt(kl,skey,key);
}