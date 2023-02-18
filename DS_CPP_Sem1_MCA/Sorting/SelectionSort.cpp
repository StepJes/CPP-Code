#include <iostream>

#include <conio.h>

using namespace std;

void swap(int *xp, int *yp)

{

    int temp = *xp;

    *xp = *yp;

    *yp = temp;
}

void selectionSort(int arr[], int n)

{

    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)

    {

        min_idx = i;

        for (j = i + 1; j < n; j++)

            if (arr[j] < arr[min_idx])

                min_idx = j;

        if (min_idx != i)

            swap(&arr[min_idx], &arr[i]);
    }
}

void printArray(int arr[], int size)

{

    int i;

    for (i = 0; i < size; i++)

        cout
            << arr[i] << " ";

    cout << endl;
}

int main()

{

    int numbers[5];

    cout << "Enter the numbers:";

    for (int i = 0; i < 5; ++i)
    {

        cin >> numbers[i];
    }

    int n = sizeof(numbers) / sizeof(numbers[5]);
    selectionSort(numbers, n);

    cout << "Sorted array: \n";

    printArray(numbers, n);

    return 0;
}
