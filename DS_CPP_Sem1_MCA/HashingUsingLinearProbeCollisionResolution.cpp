#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

const int SIZE = 10;

static int coll;

class hash1

{

    long key;
    long index;
    long arr[10];

public:
    void directHash();
    void subHash();
    void modDivision();
    void linProbe();
    void digitExHash();
    void foldShiftHash();
    void foldBoundHash();
    void display();
};

void hash1::modDivision()

{

    for (int i = 0; i < 10; i++)

        arr[i] = -1;

    for (int i = 1; i <= 7; i++)

    {

        int x;

        cout << "\nEnter a number";

        cin >> x;

        index = x % 10;

        while (arr[index] != -1)

            index = (index + 1) % 10;

        arr[index] = x;
    }
}

void hash1::display()

{

    cout << "\nHASH TABLE\n";

    for (int i = 0; i < 10; i++)

        cout << setw(8) << i;

    cout << "\n";

    for (int i = 0; i < 10; i++)

        cout << setw(8) << arr[i];
}

void hash1::directHash()

{

    for (int i = 0; i < 10; i++)

        arr[i] = -1;

    for (int i = 1; i <= 10; i++)

    {

        int x;

        cout << "Enter numbers from 1 to 10\n";

        cin >> x;

        int index = x;

        arr[index] = x;
    }
}

void hash1::subHash()

{

    for (int i = 0; i < 10; i++)

        arr[i] = -1;

    for (int i = 1; i <= 7; i++)

    {

        int x;

        cout << "Enter numbers from 1001 to 1010\n";
        cin >> x;

        int index = x - 1000;

        arr[index] = x;
    }
}

void hash1::digitExHash()

{

    for (int i = 0; i < 10; i++)

        arr[i] = -1;

    for (int i = 1; i <= 10; i++)

    {

        int x;

        cout << "Enter a number of 6 digits\n";

        cin >> x;

        int index = 0;

        long r, inc = 100000, incr = 1000;

        for (int i = 1; i <= 6; i++)

        {

            if (i == 1 || i == 3 || i == 5)

            {

                incr = incr / 10;

                r = (x / inc) % 10;

                index = index + (r * incr);
            }

            inc = inc / 10;
        }

        index = index % 10;

        while (arr[index] != -1)

            index = (index + 1) % 10;

        arr[index] = x;
    }
}

void hash1::foldShiftHash()

{

    for (int i = 0; i < 10; i++)

        arr[i] = -1;

    for (int i = 1; i <= 10; i++)

    {

        int x;

        cout << "Enter a number of 4 digits\n";

        cin >> x;

        index = 0;

        long no, no1, no2, no3;

        no1 = x / 100;

        no3 = no1 * 100;

        no2 = x % no3;

        index = no1 + no2;

        index = index % 10;

        if (index == -1)

        {

            arr[index] = x;
        }

        while (arr[index] != -1)

            index = (index + 1) % 10;

        arr[index] = x;
    }
}

void hash1::foldBoundHash()

{

    for (int i = 0; i < 10; i++)

        arr[i] = -1;

    for (int i = 1; i <= 10; i++)

    {

        int x;

        cout << "Enter a number of 4 digits\n";

        cin >> x;

        index = 0;

        long no, no1, no2, no3;

        no1 = x / 100;

        no3 = no1 * 100;

        no2 = x % no3;

        int tmp = 0;

        while (no1 > 0)
        {

            int rem = no1 % 10;

            tmp = (tmp * 10) + rem;

            no1 = no1 / 10;
        }

        int tmp1 = 0;

        while (no2 > 0)
        {

            int rem1 = no2 % 10;

            tmp1 = (tmp1 * 10) + rem1;

            no2 = no2 / 10;
        }

        index = tmp + tmp1;

        index = index % 10;

        if (index == -1)

        {

            arr[index] = x;
        }

        while (arr[index] != -1)

            index = (index + 1) % 10;

        arr[index] = x;
    }
}

int main()
{

    hash1 h;

    int op;

    cout << "Enter 1 for Direct Hashing\nEnter 2 for Subtraction Hashing\nEnter 3 for Modulo Division Hashing" << endl;

    cout << "Enter 4 for Digit Extraction Hashing\nEnter 5 for Shift Fold Hashing\nEnter 6 for Shift Boundary Hashing" << endl;

    cout << "\nEnter 7 to exit\n"
         << endl;

    cin >> op;

    for (int i = 0; i < SIZE; i++)

    {

        switch (op)

        {

        case 1:

            h.directHash();

            h.display();

            break;

        case 2:

            h.subHash();

            h.display();

            break;

        case 3:

            h.modDivision();

            h.display();

            break;

        case 4:

            h.digitExHash();

            h.display();

            break;

        case 5:

            h.foldShiftHash();

            h.display();

            break;

        case 6:

            h.foldBoundHash();

            h.display();

            break;
        }
    }

    return 0;
}
