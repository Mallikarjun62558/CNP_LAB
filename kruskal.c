 #include<stdio.h>
 #include<stdlib.h>

 #define MAX_NODES 100
 #define MAX_EDGES 100

 struct edge{
    int src, dest,weight;
 };
 struct subset{
    int parent,rank;
 };

 struct edge edges[MAX_EDGES];
 struct subset subsets[MAX_NODES];
 int edgecount=0;

 int find(int i){
   if(subsets[i].parent!=i)
   subsets[i].parent=find(subsets[i].parent);
   return (subsets[i].parent);
 }

 void unionsets(int x,int y){
   int rootx=find(x);
   int rooty=find(y);

   if(subsets[rootx].rank < subsets[rooty].rank)
   subsets[rootx].parent=rooty;
   else if(subsets[rootx].rank > subsets[rooty].rank)
   subsets[rooty].parent=rootx;
   else{
      subsets[rooty].parent=rootx;
      subsets[rootx].rank++;
   }
 }

 int compareedge(const void* a,const void* b){
   return ((struct edge*)a)->weight-((struct edge*)b)->weight;
 }

 void kruskal(int node){
   qsort(edges,edgecount,sizeof(edges[0]),compareedge);
   for(int i=0;i<node;i++){
      subsets[i].parent=i;
      subsets[i].rank=0;
   }
   int mstweight=0;
   printf("mst\n");
   for(int i=0;i<edgecount;i++){
      int x=find(edges[i].src);
      int y=find(edges[i].dest);
      if(x!=y){
         printf("%c->%c:%d\n",edges[i].src+'A',edges[i].dest+'A',edges[i].weight);
         unionsets(x,y);
         mstweight+=edges[i].weight;
      }
   }
   printf("Minimum spanning Tree weight : %d",mstweight);
 }

 int main(){
   int totaledge=0,nodes;
   printf("Total no of nodes: ");
   scanf("%d",&nodes);
   for(int i=0;i<nodes;i++){
      for(int j=i+1;j<nodes;j++){
         printf("weight of %c->%c: ",i+'A',j+'A');
         scanf("%d",&edges[totaledge].weight);
         edges[totaledge].src=i;
         edges[totaledge].dest=j;
         totaledge++;
      }
   }
   edgecount=totaledge;
   kruskal(nodes);
   return 0;
 }