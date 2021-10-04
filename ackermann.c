#include <stdio.h>

long ackermann (int x, int y){
    if(x == 0) {
        return y + 1;
    } else if(y == 0) {
        return ackermann(x - 1, 1);
    } else if(y > 0) {
        return ackermann(x - 1, ackermann(x, y - 1));
    }
}

int main(){
	int x, y;
    printf("Enter the values:\nx = ");
    scanf("%d", &x);
    printf("y = ");
    scanf("%d", &y);

    long result = ackermann(x, y);
    printf("\nackermann(%d, %d) = %ld\n", x, y, result);

	return 0;
}