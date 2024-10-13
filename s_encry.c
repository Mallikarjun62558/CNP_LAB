#include <stdio.h>
#include <ctype.h>
int main(){
    char ctxt[]="qwertyuiopasdfghjklzxcvbnm9876543210";
    char data[100],ddata[100];
    int i=0,c=0;
    char ch;
    printf("Enter the data:\n");
    while((ch=getchar())!='\n')
    {
        if(ch<58)i=ch-22;
        else{
            if(isupper(ch))i=ch-65;
            else if (islower(ch))i=ch-97;
        }
        data[c++]=ctxt[i];
    }
    printf("Encrypted data:\n");
    for(i=0;i<c;i++)printf("%c",data[i]);

    printf("\n Encryption \n");
    printf("Enter the data:\n");
    c=0;
    while((ch=getchar())!='\n'){
        if(isupper(ch))ch=tolower(ch);
        i=0;
        while(i<35){
            if(ch==ctxt[i])break;
            else i++;
        }
        if(i>35)printf("Invalied data");
        if(i>25)ddata[c++]=(char)i+22;
        else ddata[c++]=(char)i+97;
    }
    printf("\n original data \n");
    for(i=0;i<c;i++)printf("%c",ddata[i]);
}