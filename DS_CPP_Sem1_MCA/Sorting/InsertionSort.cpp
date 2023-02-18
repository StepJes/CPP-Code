#include <iostream>

#include <conio.h>

using namespace std;

void insertionSort(int arr[], int n)

{

    int i, key, j;

    for (i = 1; i < n; i++)

    {

        key = arr[i];

        j = i - 1;

        while (j >= 0 && arr[j] > key)

        {

            arr[j + 1] = arr[j];

            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)

{

    int i;

    for (i = 0; i < n; i++)

        cout << arr[i] << " ";

    cout << endl;
}

int main()

{

    int number[6];

    cout
        << "Enter the numbers:";

    for (int i = 0; i < 6; ++i)
    {

        cin >> number[i];
    }

    int N = sizeof(number) / sizeof(number[6]);
    insertionSort(number, N);
    printArray(number, N);
    return 0;
}
