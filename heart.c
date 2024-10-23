#include <stdio.h>
#include <math.h>

int f(int x, int n) {
	return (int)round(-sqrt(n * n - pow(round(2 * x) - n, 2)) + n);
}
int g(int x, int n) {
	return (int)-abs(2 * x - n / 2) + n / 2;
}

void F(int n, char c) {
	for (int i = 0; i <= n / 5; ++i) {
		int arr[3] = { 0 };
		arr[0] = f(i, n / 4);
		arr[1] = (n / 4 - arr[0]) * 2;
		arr[2] = n / 2 + arr[0];
		/*printf("i: %d\t[%d %d %d]\t|", i, arr[0], arr[1], arr[2]);*/
		for (int j = 0; j <= n; ++j) {
			if ((j > arr[0]) && (j < arr[0] + arr[1] + 1)
				|| (j > arr[2]) && (j < arr[2] + arr[1] + 1)
				|| (j >= arr[0] + arr[1] + 1 && j <= arr[2]) && (i > n / 8)) {
				printf("%c", c);
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	for (int i = n / 24; i <= n / 4; ++i) {
		int arr[2] = { 0 };
		arr[0] = g(i, n);
		arr[1] = n - arr[0];
		/*printf("i: %d\t[%d %d]\t|", i, arr[0], arr[1]);*/
		for (int j = 0; j <= n; ++j) {
			if (j < arr[1] + 1 && j > arr[0]) {
				printf("%c", c);
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main() {
	int n = 100;
	char c = '=';
	/*printf("Enter heart size and heart character: ");*/
	F(n, c);
}
