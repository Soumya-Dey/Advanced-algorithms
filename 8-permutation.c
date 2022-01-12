#include <stdio.h>
#include <string.h>

void swap(char* x, char* y){
	char t;
	t = *x;
	*x = *y;
	*y = t;
}

void permutation(char* str, int start){
	int i;
    int end = strlen(str);

	if (start == end)
		printf("%s\n\n", str);
	else {
		for (i = start; i <= end; i++) {
			swap((str + start), (str + i));
			permutation(str, start + 1);
			swap((str + start), (str + i));
		}
	}
}

int main(){
    int n;
    printf("How many characters = ");
    scanf("%d", &n);

	char str[n], i;
    for (i = 0; i < n; i++) {
        printf("str[%d] = ", i);
        scanf("%s", &str[i]);
    }

    printf("\nPermutations of the string: \n");
	permutation(str, 0);
	return 0;
}
