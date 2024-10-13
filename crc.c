#include<stdio.h>
# define deg 4
int r[100],r1[100];
int npos(int *a,int pos){
    int i=pos;
    while(a[i]==0)i++;
    return i;
}
void crc(int l){
    int poly[]={1,1,0,0,1};
    int pos=0,i=0,newpos;
    while(pos<l-deg){
        for(i=pos;i<pos+deg+1;i++){
            r[i]=r[i]^poly[i-pos];
        }
        newpos=npos(r,pos);
        if(newpos>pos+1)
        pos=newpos-1;
        pos++;
    }
}

int main(){
    int i=0;
    int a[100],a1[100];
    char ch;
    printf("enter the data:\n");
    while((ch=getchar())!='\n'){
        a[i++]=ch-'0';
    }
    int len=i;
    for(i=0;i<deg;i++)a[i+len]=0;
    len+=deg;
    for(i=0;i<len;i++)r[i]=a[i];
    crc(len);

    printf("Transmitted data:\n");
    for(i=0;i<len-deg;i++)printf("%d",a[i]);
    for(i=len-deg;i<len;i++)printf("%d",r[i]);

    i=0;
    printf("\n check crc:\n");
    printf("Enter the received data:\n");
    while((ch=getchar())!='\n'){
        a1[i++]=ch-'0';
    }
    len=i;
    for(i=0;i<len;i++)r[i]=a1[i];
    crc(len);
    printf("\n Reminder \n");
    for(i=len-deg;i<len;i++)printf("%d",r[i]);

}