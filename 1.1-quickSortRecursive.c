#include <stdio.h>

// First element as Pivot
int partition(int arr[], int first, int last){
    int pivot = first;
    int i = first;
    int j = last;
    int temp;
      
    while(i < j){
        while(arr[i] <= arr[pivot])
            i++;
            
        while(arr[j] > arr[pivot])
            j--;
            
        if(i < j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
      
    temp = arr[pivot];
    arr[pivot] = arr[j];
    arr[j] = temp;

    return j;
}

// Last element as Pivot
// int partition(int arr[], int first, int last){
//     int pivot = first;
//     int i = first;
//     int j = last;
//     int temp;
      
//     while(i < j){
//         while(arr[i] <= arr[pivot])
//             i++;
            
//         while(arr[j] > arr[pivot])
//             j--;
            
//         if(i < j){
//             temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//         }
//     }
      
//     temp = arr[pivot];
//     arr[pivot] = arr[j];
//     arr[j] = temp;

//     return j;
// }

void quicksort(int arr[], int first, int last){
   if(first < last){
      int p = partition(arr, first, last);
      
      quicksort(arr, first, p-1);
      quicksort(arr, p+1, last);
   }
}

int main(){
   int arr[] = { 7, 11, 14, 6, 9, 4, 3, 12 };
   int n = sizeof(arr) / sizeof(arr[0]);
    
//    quicksort(arr, 0, n-1);
    partition(arr, 0, n-1);
   
   printf("Sorted array:");
   for(int i = 0; i < n; i++)
    printf(" %d", arr[i]);
   printf("\n");
    
   return 0;
}