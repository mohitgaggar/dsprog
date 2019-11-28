#include<stdio.h>
#include<stdlib.h>



void creategraph(int ** graph,int n)
{ int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
}

void dfs(int v,int cid,int ** graph,int * visit,int n)
{
    visit[v]=cid;
    for(int i=0;i<n;i++)
    {
        if(visit[i]==0 && graph[v][i]==1)
        {
            dfs(i,cid,graph,visit,n);
            printf("%d ",i);
        }
    }
}
void number_components(int ** graph,int * visit,int n)
{
    int count=1;
    for(int i=0;i<n;i++)
    {
        if(visit[i]==0)
        { 
            dfs(i,count,graph,visit,n);
            count++;
        }
    }
    printf("Number of components=%d",count-1);
}

void main()
{
    int n,i,j;
    printf("Enter n ");
    scanf("%d",&n);
    int ** graph=(int **)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)
        *(graph+i)=(int*)malloc(sizeof(int)*n);
    int * visit=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        visit[i]=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
    // creategraph(graph,n);
    // dfs(0,1,graph,visit);
    number_components(graph,visit,n);
}