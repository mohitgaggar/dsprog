#include<stdio.h>
#include<stdlib.h>

typedef struct tries
{
	struct tries *a[26];
	int eow;
}tries;

typedef struct stack{
	tries *root;
	int i;
}stack;

int length=0;
char word[100];
int top=-1;
stack s[100];

int check(tries *x){
	int i,c=0;
	for(i=0;i<26;i++){
		if(x->a[i]!=NULL){
			c++;
		}
	}
	return c;
}

void push(tries *x,int k){
	++top;
	s[top].root=x;
	s[top].i=k;
}

stack pop(){
	stack t;
	t=s[top--];
	return t;
}

tries* getNode(){
	tries *temp;
	temp = (tries*)malloc(sizeof(tries));
	for(int i=0;i<26;i++){
		temp->a[i] = NULL;
	}
	temp->eow = 0;
	return 	temp;
}

void insert_key(tries *root, char *key){
	tries *temp = root;
	int j;
	for(int i=0;key[i]!='\0';i++){
		j=key[i]-'a';
		if(temp->a[j]==NULL){
			temp->a[j]=getNode();		
		}
		temp = temp->a[j];
	}
	temp->eow = 1;
}

void delete_key(tries *root,char *key){
	tries *temp=root;
	int i,j,k;
	stack x;
	for(i=0;key[i]!='\0';i++){
		j=key[i]-'a';
		if(temp->a[j]==NULL){
			printf("Not Found\n");
			return;
		}
		push(root,j);
		temp=temp->a[j];
	}
	temp->eow=0;
	push(temp,-1);
	while(1){
		x=pop();
		if(x.i!=0){
			x.root->a[x.i]=NULL;
			break;
		}
		if(x.root == root){
			break;
		}
		k=check(x.root);
		if((k>1) || (x.root->eow==1)){
			break;
		}
		free(x.root);	
	}
}



void display_tries(tries *root){
	int i,j;
	for(i=0;i<26;i++){
		if(root->a[i]!=NULL){
			word[length++]=i+97;
			if(root->a[i]->eow == 1){
				printf("\n");
				for(j=0;j<length;j++){
					printf("%c",word[j]);
				}
			}
			display_tries(root->a[i]);
			printf("\n");
		}
	}
	length--;
}

void search_key(tries *root,char *key){
	tries *temp=root;
	int i,j;
	for(i=0;key[i]!='\0';i++){
		j=key[i]-'a';
		if(temp->a[j] == NULL){
			printf("Key Not Found\n");
			return;
		}
		temp = temp->a[j];
	}
	if(temp->eow == 1){
		printf("Key Found\n");
	}
	else{
		printf("Key Not Found\n");
	}
}

int main(){
	tries *root = getNode();
	int ch,k;
	char key[100];
	while(1){
		printf("1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:printf("Enter a word:");
					scanf("%s",key);
					insert_key(root,key);
					break;
			case 2:printf("Enter a word:");
					scanf("%s",key);
					delete_key(root,key);
					break;
			case 3:printf("Enter a word:");
					scanf("%s",key);
					search_key(root,key);
					break;
			case 4:display_tries(root);
					break;
			default:exit(0);
		}
	}
}



