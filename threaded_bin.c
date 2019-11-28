#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * left;
    struct node * right;
    int lthread;
    int rthread;
}node;

typedef struct btree
{
    node * root;
}btree;

btree * insert(btree * tree,int data)
{
    node * temp=(node*)malloc(sizeof(node));
    node * prev;
    node * t=tree->root;
    temp->data=data;
    temp->left=temp->right=NULL;
    temp->lthread=temp->rthread=1;
    if(tree->root==NULL)
    {
        tree->root=temp;
        return tree;
    }
    else{
        while(t!=NULL)
        {
            if(t->data==data)
                return tree;
            prev=t;
            if(t->data > data)
            {
                if(t->lthread == 0)
                {
                    t=t->left;
                }
                else 
                    break;
            }
            else
            {
                 if(t->rthread == 0)
                {
                    t=t->right;
                }
                
                else 
                    break;
            }
        }
        if(prev==NULL)
        {
            tree->root=temp;
            return tree;
        }
        else 
        {
            if(prev->data < data)
            {
                temp->right=prev->right;
                temp->left=prev;
                prev->right=temp;
                prev->rthread=0;
                return tree;
            }
            else if(prev->data > data)
            {
                temp->left=prev->left;
                temp->right=prev;
                prev->left=temp;
                prev->lthread=0;
                return tree;
            }
            
        }
    }
}


void pre(node * t)
{
    if(t!=NULL)
    {
        printf("%d ",t->data);
        if(t->lthread==0)
            pre(t->left);
        if(t->rthread==0)
            pre(t->right);
    }
}
void preorder(btree * tree)
{
    pre(tree->root);
}

void main()
{
    int option=1;
    btree * tree;
    int data;
    tree->root=(node*)malloc(sizeof(node));
    tree->root=NULL;
    while(1)
    {
        printf("Enter the option:");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            printf("Enter the data:");
            scanf("%d",&data);
            tree=insert(tree,data);
            break;
        case 0:
            exit(0);
            break;
        case 2:
            preorder(tree);
            break;
        default:
            break;
        }
    }
}