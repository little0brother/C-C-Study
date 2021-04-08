#include <stdio.h>
#include <stdlib.h>
#define M 3

struct student
{
	char number[20];
	char name[20];
	float MATH;
	float ENG;
	float cp;
	float score;
} message[M];

int main()
{
	int i, max, min;

	for (i = 0; i < M; i++) {
		printf("Enter the %d student information\n", i + 1);
		printf("Input number:");
		scanf("%s", message[i].number);
		printf("Input name:");
		scanf("%s", message[i].name);
		printf("Input math:");
		scanf("%f", &message[i].MATH);
		printf("Input english:");
		scanf("%f", &message[i].ENG);
		printf("Input c:");
		scanf("%f", &message[i].cp);
		message[i].score = 0.0;
	}

	for (i = 0; i < M; i++)
		message[i].score = message[i].MATH + message[i].ENG
		+ message[i].cp;

	max = min = 0;
	for (i = 1; i < M; i++) {
		if (message[i].score > message[max].score)
			max = i;
		else if (message[i].score < message[min].score)
			min = i;
	}

	printf("%s %s %.2f is highest total score\n", message[max].number, message[max].name, message[max].score);
	printf("%s %s %.2f is lowest total score\n", message[min].number, message[min].name, message[min].score);

	system("pause");
	return 0;
}