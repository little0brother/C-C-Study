#include <stdio.h>

int main()
{
    int arr[] = { 4, 5, 4, 4, 2, 3, 0, 5, 1, 1 };

    int min = 0;
    int max = 0;
    int minindex = 0;
    int maxindex = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[j] <= min)
            {
                min = arr[j];
                minindex = j;
            }
            if (max < arr[j])
            {
                max = arr[j];
                maxindex = j;
            }     
        }
    }

    printf("minindex:%d\n", minindex);

	return 0;
}