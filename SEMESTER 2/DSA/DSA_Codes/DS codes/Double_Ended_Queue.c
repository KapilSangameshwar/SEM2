// Write a C program to implement Doubly ended queue using array and perform the following operations

// Insert front
// Insert rear
// delete front
// delete rear
// display
// Exit

#include <stdio.h>

#include <stdlib.h>

#define size 5

int main()

{

    int arr[size], R = -1, F = 0, te = 0, ch, n, i, x;

    for (;;)

    {

        scanf(" %d", &ch);

        switch (ch)

        {

            while (1)
                ;

        case 1:

            if (te == size)

            {

                printf(" full");
            }

            else

            {

                scanf(" %d", &n);

                if (F == 0)

                {

                    F = size - 1;
                }

                else

                {

                    F = F - 1;
                }

                arr[F] = n;

                te = te + 1;
            }

            break;

        case 2:

            if (te == size)

            {

                printf(" full");
            }

            else

            {

                scanf(" %d", &n);

                R = (R + 1) % size;

                arr[R] = n;

                te = te + 1;
            }

            break;

        case 3:

            if (te == 0)

            {

                printf(" empty");
            }

            else

            {

                printf(" %d", arr[F]);

                F = (F + 1) % size;

                te = te - 1;
            }

            break;

        case 4:

            if (te == 0)

            {

                printf(" empty");
            }

            else

            {

                if (R == -1)

                {

                    R = size - 1;
                }

                printf(" %d", arr[R]);

                R = R - 1;

                te = te - 1;
            }

            break;

        case 5:

            if (te == 0)

            {

                printf(" empty");
            }

            else

            {

                x = F;

                for (i = 1; i <= te; i++)

                {

                    printf(" %d", arr[x]);

                    x = (x + 1) % size;
                }
            }

            break;

        case 6:

            exit(0);

            break;

        default:

            printf("Wrong Choice");
        }
    }

    return 0;
}