//BFS
#include<stdio.h>

int visit[100];
int q[100];
int a[100][100];
void createGraph();
void bfs(int);
void qinsert(int);
int qdelete();
int qisempty();
int f=-1;
int r=-1;
int n;

void main()
{
		int i,v,k;
		printf("%s\t","Enter number of vertices:" );
		scanf("%d",&n);

		createGraph();
		printf("%s\t","Enter the source vertex:" );
		scanf("%d",&v);

		printf("The vertices reachabe from %d are ",v);
		bfs(v);

}

void createGraph()
{
	int i,j;
	printf("%s\t","Enter the source and destination vertices" );
	while(1){

	scanf("%d%d",&i,&j);
	if((i==0)||(j==0))
		break;
	a[i][j]=1;
	}
}

void qinsert(int v)
{
	r++;
	q[r]=v;
	if(f==-1) 
		f=0;
}

int qisempty()
{
	if(f==r==-1)
		return 1;

}

void bfs(int v)
{
	qinsert(v);
	visit[v]=1;
	int x,w;
	printf("%d",v );
	while(!qisempty)
	{
		x=qdelete();
		for(w=1;w<=n;w++)
		{
			if(a[x][w]==1 && visit[w]==0)
			{
					qinsert(w);
					visit[w]=1;
					printf("%d",w);
					
			}
		}
	}
}


int qdelete()
{
	if(!qisempty())
	{
		
			int x;
		x=q[f];
		if(f==r)
				f=r=-1;
		f++;
		return x;
	}
}



