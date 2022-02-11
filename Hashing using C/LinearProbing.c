//Linear probing Meathod
#include<stdio.h>
#define TABLE_SIZE 10

int a[TABLE_SIZE];
//Function for making array
void arrayMaker()
{
    int i;
    for(i=0 ; i<TABLE_SIZE ; i++)
    {
        a[i] = 0;  
    }
}
//Modular Hash Function 
int modHashFunc(int value)
{
    int key = value % TABLE_SIZE;
    return key;
}
//Function to insert elements
void Insert(int x)
{
    int i;
    for( i=0 ; i<TABLE_SIZE; i++ )
    {
        if(a[modHashFunc(x+i)] == 0)
        {
            a[modHashFunc(x+i)] = x;
            break;
        }
        
    }
    if(i == TABLE_SIZE)
    {
        printf("%d cannot be inserted using linear probing\n",x);
    }
    

}
//Function for finding
int Find(int x)
{
    int key = modHashFunc(x),i;
    for( i=0 ; i<TABLE_SIZE ; i++ )
    {
        if(a[modHashFunc(x+i)] == x)
        {
            return 1;
        }
    }
    return 0;
}
//Function to delete
int Delete(int x)
{
    int key = modHashFunc(x),i;
    if( Find(x) == 0 )
    {
        printf("The element entered to delete from the hash table do not exists\n");
        return 0;
    }
    else if(Find(x) == 1)
    {
        for(i=0 ; i<TABLE_SIZE ; i++)
        {
            if(a[modHashFunc(x+i)] == x)
            {
                a[modHashFunc(x+i)] = 0;
                printf("%d is deleted from index %d of the hash table\n",x,modHashFunc(x+i));
                return 1;
            }
        }
    }

}
//Function to print the array
void printArray()
{
    int i;
    for(i=0 ; i<TABLE_SIZE ;i++)
    {
        printf("a[%d] = %d\n",i,a[i]);
    }
}
//Main function
int main()
{
    arrayMaker();
    int arr[] = {25, 37, 28, 45, 49, 70, 89, 81, 31, 22, 43, 56, 73, 68},i;
    for(i=0; i<14; i++)
    {
        Insert(arr[i]);

    }
    printf("Hash table corrosponding to the given key is:\n");
    printArray();
    printf("After inserting the values 35,32,42,52,66,76,59,69 the table is:\n");
    Insert(35);
    Insert(32);
    Insert(42);
    Insert(52);
    Insert(66);
    Insert(76);
    Insert(59);
    Insert(69);
    printf("The Resulting Hash table is\n");
    printArray();
    int a[] = {37, 45, 81, 56, 66};
    for(i=0 ; i<5 ; i++)
    {
        Delete(a[i]);
        printf("After deletion of %d the Hash table is\n",a[i]);
        printArray();
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

