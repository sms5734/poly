#include<stdio.h>
int main() {
	int a[3];
	int b[2];
	int small = 9999;

	//햄버거
	for (int i = 0; i < 3; i++) {
		scanf("%d", &a[i]);
	}


	//햄버거중 가장 싼 버거 찾기
	for (int i = 0; i < 3; i++) {

		if (small > a[i])
			small = a[i];
	}


	//음료
	for (int i = 0; i < 2; i++) {
		scanf("%d", &b[i]);
	}


	//음료중 가장 싼 음료 찾기
	for (int i = 0; i < 2; i++) {
		if (b[i + 1] < b[i])
			b[i] = b[i + 1];
	}

	//가장 저렴한 세트(-50)
	printf("%d", (small + b[0]) - 50);





}