#include <iostream> #include<conio.h> #include<stdlib.h> #include<conio.h> #include<string.h>

#define MAX 5

using namespace std;
class stack

{

public:
    int count, top;
    char arr[MAX];
    stack()
    {

        count = 0;
        top = -1;
    }

    void push(char);
    void pop();
};

void stack::push(char d)

{

    int flag;
    if (count == MAX)
    {

        cout << "\nStack is full";
    }

    else

    {

        count++;

        top++;

        arr[top] = d;
    }
}

void stack::pop()

{

    if (top == -1)

    {

        cout << "\nStack is empty";
    }

    else

    {

        char d = arr[top];

        cout << d << endl;

        top--;

        count--;
    }
}

int main()

{

    stack s1;

    char exp[20];

    char ch;

    int num, n, i;

    cout << "\nEnter the expression\n";

    cin >> exp;

    num = strlen(exp);

    for (i = 0; i < num; i++)

    {

        if (exp[i] == '(')

        {

            s1.push(exp[i]);
        }

        else if (exp[i] == ')')

        {

            s1.pop();
        }
    }

    if (s1.top != -1)

    {

        cout << "\nNo matching parenthesis,Wrong expression\n";
    }

    else

    {

        cout << "\nMatchingparenthis found expressions is correct\n";
    }

    getch();

    return 0;
}
