#include<stdio.h>
int main() {
	int a[3];
	int b[2];
	int small = 9999;

	//�ܹ���
	for (int i = 0; i < 3; i++) {
		scanf("%d", &a[i]);
	}


	//�ܹ����� ���� �� ���� ã��
	for (int i = 0; i < 3; i++) {

		if (small > a[i])
			small = a[i];
	}


	//����
	for (int i = 0; i < 2; i++) {
		scanf("%d", &b[i]);
	}


	//������ ���� �� ���� ã��
	for (int i = 0; i < 2; i++) {
		if (b[i + 1] < b[i])
			b[i] = b[i + 1];
	}

	//���� ������ ��Ʈ(-50)
	printf("%d", (small + b[0]) - 50);





}