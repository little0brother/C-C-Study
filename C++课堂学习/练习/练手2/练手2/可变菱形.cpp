#include <iostream>
#define M 5

using namespace std;

int main()
{
	char a[M][M] = { 0 };
	int x = 2, y = 2;

	for (int i = 0; i < M - 2; i++) {
		for (int j = 0; j < M; j++) {
			if (x == j || y == j)
				a[i][j] = '*';
			else
				a[i][j] = ' ';
		}
		x--; y++;
	}

	x+=2; y-=2;
	for (int i = M - 2; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (x == j || y == j)
				a[i][j] = '*';
			else
				a[i][j] = ' ';
		}
		x++; y--;
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++)
			cout << a[i][j];
		cout << endl;
	}

	system("pause");
	return 0;
}