/*COP 3502C Midterm Assignment Two
This Program is writen by: Anthony Moore*/
#include<stdio.h>
#include<stdlib.h>

#define INT_MAX 2147483648
#define INT_MIN -2147483648
#define MAX_INPUT 1000000
typedef struct nod{
    int data;
    struct nod *prev, *next;
} node;
node *root;

void insert_front(int item){

    node *temp;
    temp= (node *) malloc(sizeof(node));
    temp->data=item;
    temp->prev = NULL;
    temp->next=root;
    if(root!=NULL)
            root->prev=temp;
        root = temp;
}

void insert_end(int item){
    node *t;
    node *temp;

    temp=(node*) malloc( sizeof(node));
    temp->data=item;
    temp->next=NULL;
    if(root==NULL)
    {
        temp->prev = NULL;
        root=temp;
    }
    else
    {
        t=root;

        while(t->next!=NULL){
            t=t->next;
        }
        t->next=temp;
        temp->prev = t;
    }
}

int DelListDoubly(int item){

    node *t;
    node *temp;
    node *itemNode;

    if(root->next==root){
        return 0;
    }

    if(root->data == item)
    {
        temp=root;

        while(temp->next != root){
            temp = temp->next;
        }
        root=root->next;
        if (root->next != root){
            root -> prev = NULL;
            temp->next = root;
        }


        return 1;
    }

    t=root;
    temp = NULL;
    while(t->next->data != item){
        t=t->next;

    }

    if(t->next->next->data < t->next->data && t->next->data == item){
        t->next = root;

        return 1;
    }
    temp = t;
    itemNode = t;
    temp = temp->next->next;
    itemNode = itemNode->next;
    t->next = temp;
    temp->prev = t;

    return 1;
}/*End of Deleting Item*/
void killPrisoner(int n, int k){
    node *temp = root;
    for(int i = 1; i < n; i++){

        for(int j = 1; j < k; j++){

            temp = temp->next;

        }

        DelListDoubly(temp->data);
    temp = temp->next;
    }
}/*End of Killing Prisoners*/
int main(){
    int n,k, posTest = 1, negTest = -1;
    while(1){
            root = NULL;
    /*User Input*/
    printf("\nEnter the number of prisoners: ");
    if(!(scanf("%d", &n))){
        while((getchar()) != '\n');
        n = 0;
    }


    printf("Enter the prisoner to be killed: ");
    if(!(scanf("%d", &k))){
         while((getchar()) != '\n');
         k = 0;
    }

    if(n < 1 || k < 1){
        printf("Could not calculate. Invalid input was given.\n");
        continue;
    }
    int * result = (int*)malloc(sizeof(int));
    *result = n + k;
    if(*result < 0 || *result > MAX_INPUT){
        printf("Could not calculate. Invalid input was given.\n");
        continue;
    }

    /*Create Doubly and Circularly Linked List*/

    for(int i = 1; i <= n; i++){
        insert_end(i);
    }
    node *temp = root;
    while(temp->data != n){
        temp = temp->next;
    }
    temp->next = root;

        killPrisoner(n,k);

     node *t2 = root;
        printf("The winner is: %d\n",t2->data);
    }

    return 0;
} /*End of main()*/
