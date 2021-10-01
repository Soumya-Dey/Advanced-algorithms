#include <stdio.h>

void towerOfHanoi(int n, char from, char to, char mid){
	if (n == 1){
        printf("\nMove disk 1 from rod %c to rod %c", from, to);
		return;
	}

	towerOfHanoi(n - 1, from, mid, to);
    printf("\nMove disk %d from rod %c to rod %c", n, from, to);
	towerOfHanoi(n - 1, mid, to, from);
}

int main()
{
	int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("\nSteps to move the disks from Rod A to Rod C:");
	towerOfHanoi(n, 'A', 'C', 'B');
    printf("\n");

	return 0;
}
