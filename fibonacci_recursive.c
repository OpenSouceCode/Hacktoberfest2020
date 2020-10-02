#include <stdio.h>

int fib(int x) {
	if (x <= 1) return x;
	return fib(x - 1) + fib(x - 2);
}

int main() {
	int num;
	printf("Which number of fibonacci sequence to calculate: ");
	scanf("%d", &num);

	printf("%d\n", fib(num));

	return 0;
}
