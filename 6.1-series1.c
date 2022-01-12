#include <stdio.h>

int series1(int n){
    if(n == 1) return n;
	return n + series1(n-1);
}

int main()
{
	int n, sum, i;
    printf("Enter the number: ");
    scanf("%d", &n);

    for(i=1; i<n; i++){
        printf("%d + ", i);
    }
    printf("%d = ", n);

	sum = series1(n);
    printf("%d\n", sum);

	return 0;
}