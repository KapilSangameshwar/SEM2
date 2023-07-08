// C program to implement Binary search
#include <stdio.h>

int binarySearch(int a[], int l, int h, int key)
{
    while (l <= h)
    {
        int m = l + (h - l) / 2;

        if (a[m] == key)
        {
            return m;
        }

        if (a[m] < key)
        {
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }

    return -1;
}

int main()
{

    int n, i, key;

    scanf("%d", &n);

    int a[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    scanf("%d", &key);

    int index = binarySearch(a, 0, n - 1, key);

    if (index == -1)
    {
        printf("absent\n");
    }
    else
    {
        printf("present at %d index \n", index);
    }

    return 0;
}