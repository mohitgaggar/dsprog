#include<stdio.h>
#include<ctype.h>

void insert(int * tree)
{
    int data;
    printf("ENter the data to insert:");
    scanf("%d",&data);
    int i=0;
    if(tree[i]==-1)
        {
            tree[i]=data;
            return;
        }
    while(i<1000)
    {
        while(tree[(2*i)+1]!=-1 && tree[i] > data && i<100)
        {
            i=(2*i)+1;
        }
        if(tree[(2*i)+1]==-1 && tree[i] > data && i<100) 
        {
            i=((2*i)+1);
            tree[i]=data;
            return;
        }
        while(tree[(2*i)+2]!=-1 && tree[i] < data && i<100)
        {
            i=(2*i)+2;
        }
        if(tree[(2*i)+2]==-1 && tree[i] < data && i<100)
        {
            i=((2*i)+2);
            tree[i]=data;
            return;
        }
    }
}

void inorder(int * tree,int i)
{
    if(tree[i]==-1)
        return;
    else{
        inorder(tree,2*i+1);
        printf("%d ",tree[i]);
        inorder(tree,2*i+2);
    }
}

void preorder(int * tree,int i)
{
    if(tree[i]==-1)
        return;
    else{
        printf("%d ",tree[i]);
        preorder(tree,2*i+1);
        preorder(tree,2*i+2);
    }
}

void postorder(int * tree,int i)
{
    if(tree[i]==-1)
        return;
    else{
        postorder(tree,2*i+1);
        postorder(tree,2*i+2);
        printf("%d ",tree[i]);
    }
}

void main()
{
    int tree[1000];
    for(int i=0;i<1000;i++)
    {
        tree[i]=-1;
    }
    int size=0;
    int op=1;
    while(op!=0)
    {
        printf("choose an option ");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            insert(tree);
            /* code */
            break;
        case 2:
            inorder(tree,0);
            break;
        case 3:
            preorder(tree,0);
            break;
        case 4:
            postorder(tree,0);
            break;    
        default:
            break;
        }
    }
}