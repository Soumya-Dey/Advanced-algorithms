#include <stdio.h>

// Last element as Pivot
// int partition(int arr[], int first, int last){
// 	int pivot = last;
// 	int i = (first - 1);
// 	int temp;

// 	for (int j = first; j <= last - 1; j++) {
// 		if (arr[j] <= arr[pivot]) {
// 			i++;
// 			temp = arr[i];
// 			arr[i] = arr[j];
// 			arr[j] = temp;
// 		}
// 	}
	
// 	temp = arr[i + 1];
// 	arr[i + 1] = arr[last];
// 	arr[last] = temp;
	
// 	return (i + 1);
// }

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

void quickSortIterative(int arr[], int first, int last){
	int stack[last - first + 1];

	int top = -1;

	stack[++top] = first;
	stack[++top] = last;

	while (top >= 0) {
		last = stack[top--];
		first = stack[top--];

		int p = partition(arr, first, last);

		if (p - 1 > first) {
			stack[++top] = first;
			stack[++top] = p - 1;
		}

		if (p + 1 < last) {
			stack[++top] = p + 1;
			stack[++top] = last;
		}
	}
}

int main(){
	int arr[] = { 4, 3, 5, 2, 1, 3, 2, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	quickSortIterative(arr, 0, n - 1);
	
	printf("Sorted array:");
	for (int i = 0; i < n; i++)
		printf(" %d", arr[i]);
	printf("\n");
		
	return 0;
}