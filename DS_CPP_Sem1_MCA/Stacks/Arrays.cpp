#include <iostream>

#include <conio.h>

#include <stdlib.h>

#define MAX 5

using namespace std;

int top;

class stack

{

public:
    int stack[MAX];

    void push();

    void pop();

    void display();

    int full();

    int empty();
};

int stack::full()

{

    if (top == MAX - 1)

        return 1;

    else

    {

        return 0;
    }
}

int stack::empty()

{

    if (top == -1)

        return 1;

    else

        return 0;
}

void stack::push()

{

    // int item;

    int push_item;

    if (full() == 1)

        cout << "overflow \n";

    else

    {

        cout << "enter the number to push to the stack";

        cin >> push_item;

        top = top + 1;

        stack[top] = push_item;
    }
}

void stack::pop()

{

    if (empty() == 1)

        cout << "stack overflow";

    else

    {

        cout << "poped element\n"
             << stack[top];

        top = top - 1;
    }
}

void stack::display()

{

    int a;

    if (top == -1)

        cout << "stack is empty \n";

    else

    {

        cout << "stack element\n";

        for (a = top; a > 0; a--)

            cout << stack[a] << "\n";
    }
}

int main()

{

    stack s;

    int choice;

    while (choice != 4)

    {

        cout << "\n1 push";

        cout << "\n2pop";

        cout << "\n3display";

        cout << "\n4exit";

        cout << "\nenter your choice";

        cin >> choice;

        switch (choice)

        {

        case 1:
            s.push();

            break;

        case 2:
            s.pop();

            break;

        case 3:
            s.display();

            break;

        case 4:
            exit(1);

        default:
            cout << "\ninvalid choice";
        }
    }

    getch();

    return 0;
}
