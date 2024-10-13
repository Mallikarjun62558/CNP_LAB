#include<stdio.h>
#define INF 999
int prims(int cost[10][10], int n, int source){
    int mincost=0,vertices[10]={0};
    vertices[source]=1;
    for(int i=1;i<n;i++){
        int min=INF,u=-1,v=-1;
        for(int j=1;j<=n;j++){
            if(vertices[j]){
                for(int k=1;k<=n;k++){
                    if(!vertices[k]&&cost[j][k]<min){
                        min=cost[j][k];
                        u=j;
                        v=k;
                    }
                }
            }
        }
        if(u!=-1,v!=-1){
            printf("%d->%d =%d",u,v,min);
            printf("\n");
            mincost+=min;
            vertices[v]=1;
        }
    }
    return mincost;
}

int main(){
    int a[10][10];
    int n,source;
    printf("Number of Vertices:");
    scanf("%d",&n);
    printf("Source Vertex:");
    scanf("%d",&source);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d->%d=",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    int mincost=prims(a,n,source);
    printf("Mincost=%d",mincost);
}