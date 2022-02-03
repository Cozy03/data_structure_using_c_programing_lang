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
//Function for copping one arrays element to anoter array
void copy(int a[], int b[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
}
//a)Bubblesort Algorithm
//Function for bubble sorting
void bubble_sort(int arr[], int lenght)
{
    int i, j, count = 0;
    for (i = 0; i < lenght - 1; i++)
    {
        for (j = 0; j < lenght - i - 1; j++) /*Here lenght-i-1 is used instead of lenght-1 
                                                  as already last i elements are sorted so no need 
                                                  to revisit them again.*/
        {
            count++;
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    printf("Number of times the elements were compared in this process is: %d \n", count);
}
//b)Selection Sort Algorithm
//Function for Selection sorting
void selection_sort(int arr[], int n){
    int indexOfMin, temp;
    int count=0;
    for (int i = 0; i < n-1; i++)
    {
        indexOfMin = i;
        for (int j = i+1; j < n; j++)
        {
            count++;
            if(arr[j] < arr[indexOfMin]){
                indexOfMin = j;
            }
        }
        // Swap arr[i] and arr[indexOfMin]
     swap(&arr[i],&arr[indexOfMin]);
    }
    printf("Number of times the elements were compared in this process is: %d \n", count);
}
//)c)Insertion Sort Algorithm
//Function for Insertion Sorting
void insertion_sort(int arr[], int lenght)
{
    int i, j, temp, count = 0;
    for (i = 1; i < lenght; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            count++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp; //Index is j+1 as j was decrimented by one position 
                            // from the last largest value of temp
        if(temp>arr[j]){
            count++;
        }
    }
    printf("Number of times the elements were compared in this process is: %d \n", count);
}
// d)Quick Sort Algorithm
//i)Partition Function
int qs_count=0;
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
            qs_count++;
        }
        while (arr[j] > pivot)
        {
            j--;
            qs_count++;
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
void quick_sort(int arr[], int low, int high)
{
    int partition_id;
    if (low < high)
    {
        partition_id = partition(arr, low, high);
        quick_sort(arr, low, partition_id - 1);
        quick_sort(arr, partition_id + 1, high);
    }
}
//e)MergeSort Algorithm
//i)Merge Function
int ms_count=0;
void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        ms_count++;
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
void merge_sort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, mid, low, high);
    }
}
//For better viewing just coloring the outpus
void red () {
  printf("\033[1;31m");
}
void purple(){
    printf("\033[0;35m");
}
void green(){
    printf("\033[0;32m");
}

void blue() {
  printf("\033[0;34m");
}
void underline(){
    printf("\e[4;30m");
}

void reset () {
  printf("\033[0m");
} 
//Main Function
void main()
{
    int i, n;
    int a[100], fresh[100];
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
    underline();
    printf("a. Modified array after Bubble Sort algorithm:  \n");
    copy(a, fresh, n);
    blue();
    start = clock();
    bubble_sort(fresh, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    red();
    printf("Time taken for Bubble Sort algorithm is:%f  \n", cpu_time_used);
    purple();
    printf("Modified Array:  \n");
    green();
    printArray(fresh, n);
    reset();
    printf("\n \n");

    //b. Selection sort
    underline();
    printf(" b. Modified array after Selection Sort algorithm:  \n");
    copy(a, fresh, n);
    blue();
    start = clock();
    selection_sort(fresh, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    red();
    printf("Time taken for Selection Sort algorithm is:%f  \n", cpu_time_used);
    purple();
    printf("Modified Array:  \n");
    green();
    printArray(fresh, n);
    reset();
    printf("\n \n");

    //c. Inserton sort
    underline();
    printf("c. Insertion Sort algorithm:  \n");
    copy(a, fresh, n);
    blue();
    start = clock();
    insertion_sort(fresh, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    red();
    printf("Time taken for Insertion Sort algorithm is:%f  \n", cpu_time_used);
    purple();
    printf("Modified Array:  \n");
    green();
    printArray(fresh, n);
    reset();
    printf("\n \n");

    //d. Quick Sort
    underline();
    printf("d. Quick Sort algorithm:  \n");
    copy(a, fresh, n);
    start = clock();
    quick_sort(fresh, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    blue();
    printf("Number of times the elements were compared in this process is: %d \n", qs_count);
    red();
    printf("Time taken for Quick Sort algorithm is:%f  \n", cpu_time_used);
    purple();
    printf("Modified Array:  \n");
    green();
    printArray(fresh, n);
    reset();
    printf("\n \n");

    //e. Merge Sort
    underline();
    printf("e. Modified array after Merge Sort algorithm:  \n");
    copy(a, fresh, n);
    start = clock();
    merge_sort(fresh, 0, n - 1);
    end = clock();
    blue();
    printf("Number of times the elements were compared in this process is: %d \n", ms_count);
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    red();
    printf("Time taken for Merge Sort algorithm is:%f  \n", cpu_time_used);
    purple();
    printf("Modified Array:  \n");
    green();
    printArray(fresh, n);
    reset();
    printf("\n \n");
}