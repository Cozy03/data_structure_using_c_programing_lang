//Separate Chaining
#include<stdio.h>
#include<stdlib.h>

#define TABLE_SIZE 10
typedef struct node node;
struct node
{
    int data;
    node *next;
} ;
node *a[TABLE_SIZE];

void arrayMaker()
{
    int i;
    for(i=0 ; i<TABLE_SIZE; i++)
    {
        a[i] = NULL; 

    }
}
//Modular Hash Function 
int modHashFunc(int value)
{
    int key;
    key = value % TABLE_SIZE;
    return key;
}
//Function to insert elements
void Insert(int x)
{

    node *new_node = malloc(sizeof(node));
    new_node->data = x;
    new_node->next = NULL;
    int key = modHashFunc(x);
    if(a[key] == NULL)
    {
        a[key] = new_node; //inserting the value x here
    }
    else
    {
        //printf("collision happens\n");
        node *temp = a[key];
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}
//Function for finding
int Find(int x)
{
    int key = modHashFunc(x);
    node *temp = a[key];
    while(temp)
    {
        if(temp->data == x)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
//Function to delete
int Delete(int x)
{
    int key = modHashFunc(x);
    if(Find(x) == 0)
    {
        printf("There is no such element to delete\n");
        return 0;
    }
    else if(Find(x) == 1)
    {
        node *temp = a[key],*prev = 0;
        while(temp)
        {
            if(temp->data == x)
            {
                if(!prev)
                {
                    a[key] = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                free(temp);
                return 1;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    return 0;
    
}
//Function to print the hash table
void printTable()
{
    int i;
    for(i=0;i<TABLE_SIZE;i++)
    {
        node *temp = a[i];
        printf("a[%d]-->",i);
        while(temp)
        {
            printf("%d-->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");

    }
}
//Main Function
int main()
{
    arrayMaker();
    int arr[] = {25, 37, 28, 45, 49, 70, 89, 81, 31, 22, 43, 56, 73, 68},i;
    for(i=0; i<14; i++)
    {
        Insert(arr[i]);

    }
    printf("Hash table corrosponding to the given key is:\n");
    printTable();
    printf("fter inserting the values 35,32,42,52,66,76,59,69\n");
    Insert(35);
    Insert(32);
    Insert(42);
    Insert(52);
    Insert(66);
    Insert(76);
    Insert(59);
    Insert(69);
    printf("The Resulting Hash table is\n");
    printTable();
    int a[] = {37, 45, 81, 56, 66};
    for(i=0 ; i<5 ; i++)
    {
        Delete(a[i]);
        printf("After deletion of %d the Hash table is\n",a[i]);
        printTable();
    }

    int b[] = {32,42,76,68,66};

    for(i=0 ; i<5 ; i++)
    {
        if(Find(b[i]) == 1)
        {

            printf("The element %d is present in the list\n",b[i]);
        }
        else if(Find(b[i]) == 0)
        {
            printf("the element %d is not present in the list\n",b[i]);
        }
    }

    return 0;


}
