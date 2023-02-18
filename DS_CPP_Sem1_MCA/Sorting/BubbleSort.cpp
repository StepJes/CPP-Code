#include <iostream>

#include <conio.h>

using namespace std;

void bubbleSort(int arr[], int n)

{

    int i, j;

    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)

            if (arr[j] > arr[j + 1])

                swap(arr[j], arr[j + 1]);
}

void printArray(int arr[], int size)

{

    int i;

    for (i = 0; i < size; i++)

        cout << arr[i] << " ";

    cout << endl;
}

int main()

{

    int bubble[5];

    cout << "Enter the value:";

    for (int i = 0; i < 5; ++i)
    {

        cin >> bubble[i];
    }

    int N = sizeof(bubble) / sizeof(bubble[5]);

    bubbleSort(bubble, N);

    cout << "Sorted array: \n";

    printArray(bubble, N);

    return 0;
}
