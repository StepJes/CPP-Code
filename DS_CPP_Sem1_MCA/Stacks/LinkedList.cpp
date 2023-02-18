#include <iostream>

#include <conio.h>

#include <malloc.h>

#include <stdlib.h> using namespace std; class nodestack

{

public:
    int info;
    nodestack *link;
    int empty();
    void push();
    void pop();
    void display();
}
*top = NULL;
void nodestack::push()

{

    nodestack *tmp;
    intpushed_item;
    tmp = new nodestack;
    cout << "enter element to be pushed\n";
    cin >> pushed_item;
    tmp->info = pushed_item;
    tmp->link = top;

    top = tmp;
}

int nodestack::empty()

{

    if (top == NULL)

        return 1;

    else

        return 0;
}

void nodestack::pop()

{

    nodestack *tmp;

    if (empty())

        cout << "stack empty\n";

    else

    {

        tmp = top;

        cout << "popped item is\n";

        cout << tmp->info;

        top = top->link;

        free(tmp);
    }
}

void nodestack::display()

{

    nodestack *ptr;

    ptr = top;

    cout << "stack elements are\n";

    while (ptr != NULL)

    {

        cout << ptr->info << "\n";

        ptr = ptr->link;
    }
}

int main()

{

    nodestack n;

    int c;

    while (c != 4)

    {

        cout << "\n1=push\n2=pop\n3=display\n4=exit\n";

        cout << "enter choice\n";

        cin >> c;

        switch (c)

        {

        case 1:

            n.push();

            break;

        case 2:

            n.pop();

            break;

        case 3:

            n.display();

            break;

        case 4:

            exit(1);

        default:

            cout << "incorrect choice\n";
        }
    }

    return 0;

    getch();
}
