#include<stdio.h>
int a[1000];
int main() {

	int n;
	int tmp;

	scanf_s("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[j] > a[i]) {
				tmp = a[j];
				a[j] = a[i];
				a[i] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}
}