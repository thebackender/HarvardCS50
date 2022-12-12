// Made only by myself)
#include <stdio.h>

void sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_pos = i;
        for (int j = i; j < n; j++)
        {         
            if (arr[j] < arr[min_pos])
            {
                min_pos = j;
            }
        }
        int tmp = arr[min_pos];
        arr[min_pos] = arr[i];
        arr[i] = tmp;
    }
}

int main(void)
{
    int arr[] = {2, 3, 1, 5, 9, 0, 10, 1, 2, 3, 5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}