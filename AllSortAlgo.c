/* 
Name- Debrup Chatterjee
Roll- CrS2103
*/
#include <stdio.h>
#include <time.h>
//Function for Swapping
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
//Function to print elements of an array
void printArray(int arr[], int lenght)
{
    int i;
    for (i = 0; i < lenght; i++)
    {
        printf("a[%d]= %d ,", i, arr[i]);
    }
    printf("\n");
}
//a)Bubblesort Algorithm
//Function for bubble sorting
int *bubble_sort(int arr[], int lenght)
{
    int i, j;
    for (i = 0; i < lenght - 1; i++)
    {
        for (j = 0; j < lenght - i - 1; j++) /*Here lenght-i-1 is used instead of lenght-1 
                                                  as already last i elements are sorted so no need 
                                                  to revisit them again.*/
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    return arr;
}
//b)Selection Sort Algorithm
//Function for Selection sorting
int *selection_sort(int arr[], int n)
{
    int i, j, min_id;
    for (i = 0; i < n - 1; i++)
    {
        min_id = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_id])
                min_id = j;
        swap(&arr[min_id], &arr[i]);
    }
    return arr;
}
//)c)Insertion Sort Algorithm
//Function for Insertion Sorting
int *insertion_sort(int arr[], int lenght)
{
    int i, j, temp;
    for (i = 1; i < lenght; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp; //Index is j+1 as j was decrimented by one position from the last largest value of temp
    }
    return arr;
}
// d)Quick Sort Algorithm
//i)Partition Function
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }

    } while (i < j);
    swap(&arr[low], &arr[j]);
    return j;
}
//ii)QuickSort Function
int *quick_sort(int arr[], int low, int high)
{
    int partition_id;
    if (low < high)
    {
        partition_id = partition(arr, low, high);
        quick_sort(arr, low, partition_id - 1);
        quick_sort(arr, partition_id + 1, high);
    }
    return arr;
}
//e)MergeSort Algorithm
//i)Merge Function
void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}
//ii)Mergesort Function
int *merge_sort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, mid, low, high);
    }
    return arr;
}
//Main Function 
void main()
{
    int i, n;
    int a[100];
    clock_t start, end;
    double cpu_time_used;
    printf("Enter the size of the array a: \n");
    scanf("%d", &n);
    printf("Enter the array a: \n");
    for (i = 0; i < n; i++)
    {
        printf("\n a[%d]=", i);
        scanf("%d", &a[i]);
    }
    printf("So the array is: \n");
    printArray(a, n);
    printf("\n \n");
    printf(" Modified array based on their sorting algorithms and time require for each algorithm to occur: \n");
    printf("\n \n");

    //a. Bubble sort
    printf("a. Modified array after Bubble Sort algorithm:  \n");
    start = clock();
    printArray(bubble_sort(a, n), n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Bubble Sort algorithm is(including printing of the array):%f  \n", cpu_time_used);
    printf("\n \n");

    //b. Selection sort
    printf(" b. Modified array after Selection Sort algorithm:  \n");
    start = clock();
    printArray(selection_sort(a, n), n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Selection Sort algorithm is(including printing of the array):%f  \n", cpu_time_used);
    printf("\n \n");

    //c. Inserton sort
    printf("c. Modified array after Insertion Sort algorithm:  \n");
    start = clock();
    printArray(insertion_sort(a, n), n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Insertion Sort algorithm is(including printing of the array):%f  \n", cpu_time_used);
    printf("\n \n");

    //d. Quick Sort
    printf("d. Modified array after Quick Sort algorithm:  \n");
    start = clock();
    printArray(quick_sort(a, 0, n - 1), n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Quick Sort algorithm is(including printing of the array):%f  \n", cpu_time_used);
    printf("\n \n");
    
    //e. Merge Sort
    printf("e. Modified array after Merge Sort algorithm:  \n");
    start = clock();
    printArray(merge_sort(a, 0, n - 1), n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Merge Sort algorithm is(including printing of the array):%f  \n", cpu_time_used);
    printf("\n \n");
}