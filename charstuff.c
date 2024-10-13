#include<stdio.h>
#include<string.h>

#define DLE 16
#define STX 2
#define ETX 4

int main(){
    int i=2;
    char ch;
    char data[100]={DLE,STX};
    printf("Enter data \n");
    while((ch=getchar())!='\n'){
        if(ch==DLE)data[i++]=DLE;
        data[i++]=ch;    
    }
    data[i++]=DLE;
    data[i++]=STX;

    printf("stuffing\n");
    for(int j=0;j<i;j++){
        if(data[j]==DLE)printf("DLE");
        else if(data[j]==STX)printf("STX");
        else if(data[j]==ETX)printf("ETX");
        else printf("%c",data[j]);
    }
    printf("\n destuffing \n");
    for(int j=2;j<i-2;j++){
        if(data[j]==DLE){printf("DLE");j++;}
        else if(data[j]==STX)printf("STX");
        else if(data[j]==ETX)printf("ETX");
        else printf("%c",data[j]);
    }
}