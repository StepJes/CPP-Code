#include <iostream> #include<stdio.h> using namespace std; class cirqueue

{

    int info;
    cirqueue *link;

public:
    void insert();
    void del();
    void display();
};

cirqueue *rear = NULL;
void cirqueue::insert()
{

    int num;
    cirqueue *tmp;

    cout << "enter the element for insertion:";
    cin >> num;

    tmp = new cirqueue;
    tmp->info = num;
    if (rear == NULL)
    {

        rear = tmp;
        tmp->link = rear;
    }

    else

    {

        tmp->link = rear->link;

        rear->link = tmp;

        rear = tmp;
    }
}

void cirqueue::del()

{

    cirqueue *tmp, *q;

    if (rear == NULL)

    {

        cout << "Queue underflow\n";

        return;
    }

    if (rear->link == rear)

    {

        tmp = rear;

        rear = NULL;

        delete (tmp);

        return;
    }

    q = rear->link;

    tmp = q;

    rear->link = q->link;

    cout << "deleted elements is" << tmp->info;

    delete (tmp);
}

void cirqueue::display()

{

    cirqueue *q;

    if (rear == NULL)

    {

        cout << "Queue is empty\n";

        return;
    }

    q = rear->link;

    cout << "Queue is:\n";

    while (q != rear)

    {

        cout << q->info;

        q = q->link;
    }

    cout << rear->info;
}

int main()

{

    //	clrscr(); cirqueue s; int choice; char ch;

    do

    {

        cout << "1:insert\n2:delete\n3:display Queue";

        cout << "\nEnter your choice(1-3): ";

        cin >> choice;

        switch (choice)

        {

        case 1:

            s.insert();

            break;

        case 2:

            s.del();

            break;

        case 3:

            s.display();

            break;

        default:

            cout << "Please enter correct choice(1-3)!!";
        }

        cout << "\n press (y) to continued:";

        cin >> ch;

    }

    while (ch == 'y' || ch == 'y');

    return 0;
}
