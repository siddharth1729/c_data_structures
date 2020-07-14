/*if any error mail me siddharth.sabron@gmail.com*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



#include<string.h>

// Function to swap two numbers 
void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

// Function to print a array 
void printArray(int arr[], int size)
{
  int i;
  for (i=0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}


// Function for Binary search 
int BinarySearching(int arr[], int max, int element)
{
      int low = 0, high = max - 1, middle;
      while(low <= high)
      {
            middle = (low + high) / 2;
            if(element > arr[middle])
                  low = middle + 1; 
            else if(element < arr[middle])
                  high = middle - 1; 
            else
                  return middle;
      }
      return -1;
}



// Implement bubble sort
void bubbleSort(int arr[], int n)
{
  int i, j;
  for (i = 0; i < n-1; i++)
  // last i elements are already in place
    for (j = 0; j < n-i-1; j++)
      if (arr[j] > arr[j+1])
        swap(&arr[j], &arr[j+1]);
}


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array */


  
/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
  
/* Function to print an array */
 
  
  int getMax(int array[], int n)
{
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}
void countingSort(int array[], int size, int place)
{
  int output[size + 1];
  int max = (array[0] / place) % 10;
  for (int i = 1; i < size; i++)
  {
    if (((array[i] / place) % 10) > max)
      max = array[i];
  }
  int count[max + 1];
  for (int i = 0; i < max; ++i)
    count[i] = 0;
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];
  for (int i = size - 1; i >= 0; i--)
  {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }
  for (int i = 0; i < size; i++)
    array[i] = output[i];
}
void radixsort(int array[], int size)
{
  int max = getMax(array, size);
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}

void SelectionSort(int A[], int size)
{
    int i,j;
  for(i=0; i<size-1; i++)
  {
    int Imin = i;
    for(j=i+1; j<size; j++)
    {
      if( A[j] < A[Imin] )
      {
        Imin = j;
      }
    }
    int temp = A[Imin];
    A[Imin] = A[i];
    A[i] = temp;
  }
}
void shellsort(int arr[], int num)
{
    int i, j, k, tmp;
    for (i = num / 2; i > 0; i = i / 2)
    {
        for (j = i; j < num; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (arr[k+i] >= arr[k])
                    break;
                else
                {
                    tmp = arr[k];
                    arr[k] = arr[k+i];
                    arr[k+i] = tmp;
                }
            }
        }
    }
}


// Function to print elements


void countingSort1(int array[], int size)
{
  int output[10];
  int max = array[0];
  for (int i = 1; i < size; i++)
  {
    if (array[i] > max)
      max = array[i];
  }
  int count[10];
  for (int i = 0; i <= max; ++i)
  {
    count[i] = 0;
  }
  for (int i = 0; i < size; i++)
  {
    count[array[i]]++;
  }
  for (int i = 1; i <= max; i++)
  {
    count[i] += count[i - 1];
  }
  for (int i = size - 1; i >= 0; i--)
  {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }
  for (int i = 0; i < size; i++)
  {
    array[i] = output[i];
  }
}

void fact_orial(int n)
{
    if(n <= 0)
    {
        printf("\n Does not have factorial");
    }
    else
    {
        int f=1;
        while(n)
        {
            f+=f*n;
            n--;
        }
        printf("\n Factorial of the number:%d",f);
    }
}

long factorial(int number)
{
    if (number >= 1)
        return (number * factorial(number - 1));
    else
        return 1;
}

#define MAX 2
int m =2;
int n =2;
int p =2;
void MatrixMutiply(int m,int n,int p,int matrix1[MAX][MAX],
int matrix2[MAX][MAX],int matrixResult[MAX][MAX])
{
int  sum;
for(int i=0;i<m;i++)
  for(int j=0;j<p;j++)
  {
   sum=0;
   for(int k=0;k<n;k++)
    sum+=matrix1[i][k]*matrix2[k][j];
   matrixResult[i][j]=sum;
  }
}

int fibonacci(int n) 
{ 
if (n==1||n==0) //in any case return same number bcoz of fibonacci numbers->0 1 1 .....-<
  return n; 
return fibonacci(n-1) + fibonacci(n-2); 
} 

void generateSquare(int n) 
{ 
    int magicSquare[n][n]; 
  
    // set all slots as 0 
    memset(magicSquare, 0, sizeof(magicSquare)); 
  
    // Initialize position for 1 
    int i = n/2; 
    int j = n-1; 
  
    // One by one put all values in magic square 
    for (int num=1; num <= n*n; ) 
    { 
        if (i==-1 && j==n) //3rd condition 
        { 
            j = n-2; 
            i = 0; 
        } 
        else
        { 
            // 1st condition helper if next number  
            // goes to out of square's right side 
            if (j == n) 
                j = 0;
   
            // 1st condition helper if next number  
            // is goes to out of square's upper side 
            if (i < 0) 
                i=n-1; 
        } 
        if (magicSquare[i][j]) //2nd condition 
        { 
            j -= 2; 
            i++; 
            continue; 
        } 
        else
            magicSquare[i][j] = num++; //set number 
  
        j++; i--; //1st condition 
    } 
  
    // Print magic square 
    printf("The Magic Square for n=%d:\nSum of "
       "each row or column %d:\n\n",  n, n*(n*n+1)/2); 
    for (i=0; i<n; i++) 
    { 
        for (j=0; j<n; j++) 
            printf("%3d ", magicSquare[i][j]); 
        printf("\n"); 
    } 
} 


struct node
{
    int index;
    char* keys;
    int* values;
};

struct map
{
    int index;
    char** list_keys;
    struct node keys[100];
};


void map_append(struct map* map, char* key, int value)
{
    bool found = false;
    int found_in = 0;

    for(unsigned int i = 0; i<map->index; i++) { if(strcmp(map->list_keys[i], key) == 0) { found=true; found_in=i;} }

    if(!found)
    {
        map->keys[map->index].keys = (char*)malloc(100 * sizeof(char));

        strcpy(map->keys[map->index].keys, key);
        map->keys[map->index].keys[strlen(key)] = '\0';

        strcpy(map->list_keys[map->index], key);

        map->keys[map->index].values = (int*)malloc(100 * sizeof(int));

        map->keys[map->index].values[0] = value;
        map->keys[map->index].index = 1;

        map->index++;
    }
    else
    {
        map->keys[found_in].values[map->keys[found_in].index] = value;
        map->keys[found_in].index++;
    }
    
}
void map_pop()
{

}


char** get_keys(struct map* map)
{
    return map->list_keys;
}

int* get_values(struct map* map, char* key)
{

    for (unsigned int i=0; i<map->index; i++)
    {
        if (!strcmp(map->keys[i].keys, key))
        {
            return map->keys[i].values;
        }
    }
    return NULL;
}

struct map map_initialize()
{
    struct map map = {0};

    map.list_keys = (char**)malloc(100 * sizeof(char*));
    for (int i=0; i<100; i++)
    {
        map.list_keys[i] = (char*)malloc(100 * sizeof(char));
    }
    return map;
}


int main()
{
    struct map map = map_initialize();
    map_append(&map, "test", 1);
    map_append(&map, "test", 2000);
    map_append(&map, "another", 200);
    map_append(&map, "and_another", 100000);

    char** keys = get_keys(&map);
    int* values = get_values(&map, "test");

    
    for (int i=0; i<map.index; i++)
    {
        printf("%s\n", keys[i]);
    }
    
    for (int i=0; i<sizeof(values)/sizeof(values[0])+1; i++)
    {
        printf("%d\n", values[i]);
    }

    return EXIT_SUCCESS;
}
