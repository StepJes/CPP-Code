#include <iostream>

#include <stdio.h>

using namespace std;

class node

{

    int priority;

    int info;

    node *link;

public:
    void insert();

    void del();

    void display();

} *front = NULL;

void node::insert()

{

    node *tmp, *q;

    int added_item, item_priority;

    tmp = new node;

    cout << "input the item value to be added in the queue:";

    cin >> added_item;

    cout << "enter its priority:";

    cin >> item_priority;

    tmp->info = added_item;

    tmp->priority = item_priority;

    if (front == NULL || item_priority < front->priority)

    {

        tmp->link = front;

        front = tmp;
    }

    else

    {

        q = front;

        while (q->link != NULL && q->link->priority <= item_priority)

            q = q->link;

        tmp->link = q->link;

        q->link = tmp;
    }
}

void node::del()

{

    node *tmp;

    if (front == NULL)

    {

        cout << "queue underflow";
    }

    else

    {

        tmp = front;

        cout << "deleted item is" << tmp->info;

        front = front->link;

        delete tmp;
    }
}

void node ::display()

{

    node *ptr;

    ptr = front;

    if (front == NULL)

        cout << "queue is empty\n";

    else

    {

        cout << "queue is:";

        cout << "priority item\n";

        while (ptr != NULL)

        {

            cout << "\t" << ptr->priority << "\t" << ptr->info;

            ptr = ptr->link;
        }
    }
}

int main()

{

    node n1;

    int choice;

    while (1)

    {

        cout << "\n1.insert\n";

        cout << "2.delete\n";

        cout << "3.display\n";

        cout << "enter your choice";

        cin >> choice;

        switch (choice)

        {

        case 1:

            n1.insert();

            break;

        case 2:

            n1.del();

            break;

        case 3:

            n1.display();

            break;

        default:

            cout << "wrong choice:\n";
        }
    }

    return 0;
}
