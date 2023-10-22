#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int num;                        //Data of the node
    struct node *nextptr;           //Address of the next node
}*start;

void createNodeList(int n); // function to create the list
void NodeInsertatBegin(int num);
void displayList();         // function to display the list

void main()
{
    int n, data;		
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    createNodeList(n);
 printf("\n Input data to insert at the beginning of the list : ");
    scanf("%d", &data);
NodeInsertatBegin(data);
    printf("\n Data entered in the list : \n");
    displayList();
}   
void createNodeList(int n)
{
    struct node *fnNode, *tmp;
    int data, i;
    start = (struct node *)malloc(sizeof(struct node)); 
        printf(" Input data for node 1 : ");
        scanf("%d", &data);
        start->num = data;      
        start->nextptr = NULL; // links the address field to NULL
        tmp = start;
// Creating n nodes and adding to linked list
        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));        
                                      
                printf(" Input data for node %d : ", i);
                scanf(" %d", &data); 
                fnNode->num = data;      // links the num field of fnNode with num
                fnNode->nextptr = NULL; // links the address field of fnNode with NULL
 
                tmp->nextptr = fnNode; // links previous node i.e. tmp to the fnNode
                tmp = tmp->nextptr;  //now it starts pointing to tht second node
             }
}

void NodeInsertatBegin(int data)
{
    struct node *fnNode;
    fnNode = (struct node*)malloc(sizeof(struct node));
    
        fnNode->num = data; //Links the data part
        fnNode->nextptr = start; //Links the address part
        start = fnNode; //Makes stnode as first node
    
}

void displayList()
{
    struct node *tmp;
    if(start == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        tmp = start;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->num);       // prints the data of current node
            tmp = tmp->nextptr;                     // advances the position of current node
        }
    }
} 