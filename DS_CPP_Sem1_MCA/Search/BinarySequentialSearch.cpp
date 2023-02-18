#include <iostream>

#include <conio.h>

using namespace std;
void binary();

void sequential();
void binary()
{

    int i, n, a[10], st = 0, ed = 9, md;

    cout << "Enter 10 elements for array in sorted manner \n";

    for (i = 0; i < 10; i++)

    {

        cin >> a[i];
    }

    cout << "Enter the number you want to search \n";

    cin >> n;

    md = (st + ed) / 2;

    while (n != a[md] && st <= ed)

    {

        if (n > a[md])

            st = md + 1;

        else

            ed = md - 1;

        md = (st + ed) / 2;
    }

    if (n == a[md])

        cout
            << n << " found at position " << md;
    if (st > ed)

        cout << "not found";
}

void sequential()

{

    int i, array[10];

    cout << "enter 10 elements\n";

    for (i = 0; i < 10; i++)

    {

        cin >> array[i];
    }

    cout << "Enter the number you want to find (from 10 to 100)…";

    int key;

    cin >> key;

    int flag = 0;

    for (i = 0; i < 10; i++)

    {

        if (array[i] == key)

        {

            flag = 1;

            break;
        }
    }

    if (flag)

    {

        cout << "Your number is at subscript position " << i << ".\n";
    }

    else

    {

        cout << "The input number is not present in this array." << endl
             << endl;
    }
}

int main()

{

    int ch;

    cout << "1-sequential\n2-Binary\n";

    cout << "enter your choice\n";

    cin >> ch;

    if (ch == 1)

        sequential();

    else if (ch == 2)

        binary();

    else

        cout << "invalid choice\n";

    getch();

    return 0;
}