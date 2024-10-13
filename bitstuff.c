#include<stdio.h>
#include<string.h>
int main(){
    char data[100]="01111110",ddata[50];
    int i=8,c=0,k,l;
    char ch=0;
    printf("enter data=");
    while((ch=getchar())!='\n'){
        data[i++]=ch;
        if(ch=='1')c++;
        else c=0;
        if (c==5){
            data[i++]='0';
            c=0;
        }
    }
    strcat(data,"01111110");
    printf("stuffed data:\n %s",data);

    l=strlen(data);
    c=0;k=0;
    for(i=8;i<l-8;i++){
        if(data[i]=='1')c++;
        else c=0;
        ddata[k++]=data[i];
        if(c==5){
            c=0;i++;
        }
    }
    ddata[k]='\0';
    printf("\n dstuff data =\n %s",ddata);
}