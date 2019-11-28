#include<stdio.h>
#include<stdlib.h>

int * bottom_up(int * a,int n)
{
    int i,j,key,k;
    for(k=(n-1)/2;k>=0;k--)
    {
        j=k;
        i=2*j+1;
        key=a[j];
        while(i<=n){
            
            if((i+1)<n && a[i+1]>a[i])
                i++;

            if(a[i]>key)
            {
                a[j]=a[i];
                j=i;
                i=2*j+1;
            }
            else
            {
                break;
            }
            
        }
        a[j]=key;
    }
}

void top_heap(int *h, int n)
  {
    int i,j,k,key;

    for(k=1;k<n;k++)
    {
      i=k;
      key=h[i];
      j=(i-1)/2;

       while((i>0)&&(key>h[j]))
       {
           h[i]=h[j];//move the parent down
           i=j;
           j=(i-1)/2;//find position of new parent
       }
       h[i]=key;
     }
   }

void heapsort(int * a,int n)
{
    int i,temp;
    bottom_up(a,n);
    for(i=0;i<n;i++)
    {
        temp=a[i];
        a[i]=a[n-1];
        a[n-1]=temp;
        bottom_up(a,n-1);
    }
    printf("Sorted\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

void heapsort1(int * a,int n)
{
    int i,temp;
    top_heap(a,n);
    for(i=1;i<n;i++)
    {
        temp=a[0];
        a[0]=a[n-i];
        a[n-i]=temp;
        top_heap(a,n-i);
    }
    printf("\nSorted\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

void main()
{
    int n,i;
    printf("Enter the number:");
    scanf("%d",&n);
    int *a=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    // a=bottom_up(a,n);
    // heapsort(a,n);
    heapsort1(a,n);
}