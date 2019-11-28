//Josephus problem 
#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int data;
    struct node * link;
}node;

typedef struct cl
{
    node * tail;
    int number_of_nodes;
    node * head;
}cl;

cl* insert(cl*);
void display(cl*);
cl * init()
{
    cl * list=(cl*)malloc(sizeof(cl));
    list->head=(node *)malloc(sizeof(node));
    list->tail=(node *)malloc(sizeof(node));
    list->head=list->tail=NULL;
    list->number_of_nodes=0;
    return list;
}
void josephus(cl *);

void main()
{
    cl * list=init();
    int option=1;
    while(1)
    {
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            list=insert(list);
            break;
        case 0:
            exit(0);
            break;
        case 2:
            josephus(list);
            break;
        case 3:
            display(list);
            break;
        default:
            break;
        }
    }
}

cl * insert(cl * list)
{
    node * temp=(node*)malloc(sizeof(node));
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(list->head == NULL)
    {
        list->head=list->tail=temp;
        list->number_of_nodes++;
        return list;
    }
    else{
        list->tail->link=temp;
        temp->link=list->head;
        list->head=temp;
        list->number_of_nodes++;
        return list;
    }
}

void display(cl * list)
{
    node * temp=list->head;
    while(temp!=list->tail)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("%d\n",list->tail->data);
}

void josephus(cl * list)
{
    node * temp=list->head;
    node * t;
    while(list->number_of_nodes!=1)
    {
        t=temp->link;
        temp->link=temp->link->link;
        temp=temp->link;
        free(t);
        list->number_of_nodes--;
    }
    printf("Remaining=%d",temp->data);
    list->head=list->tail=temp;
}