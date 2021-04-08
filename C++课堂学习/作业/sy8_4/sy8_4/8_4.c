#include <stdio.h>
#define N 5

struct student {
	int score;
	char name[10];
} s[N];

int main()
{
	int i, score90, score80, score70, score60, score_failed;

	for (i = 0; i < N; i++) {
		scanf_s("%d", &s[i].score);
		gets(s[i].name);
	}
	score90 = 0; score80 = 0; score60 = 0;  score70 = 0; score_failed = 0;

	for (i = 0; i < N; i++) {
		switch (s[i].score / 10) {
		case 10:
		case 9: score90++; break;
		case 8: score80++; break;
		case 7: score70++; break;
		case 6: score60++; break;
		default: score_failed++;
		}
	}
	printf("优:%d 良:%d 中:%d 及格:%d 不及格:%d\n", score90, score80, score70, score60, score_failed);

	system("pause");
	return 0;
}