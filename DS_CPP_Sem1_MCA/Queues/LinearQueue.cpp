#include <stdio.h> #include<iostream> #include<malloc.h> using namespace std; class node

{

public:
    int info;
    node *link;
    void insert();
    void del();
    void display();
};

node *front = NULL, *rear = NULL;
int main()

{

    int choice;
    node n;
    while (1)
    {

        cout << "1.Insert\n";

        cout << "2.Delete\n";

        cout << "3.Display\n";

        cout << "4.Quit\n";
        cout << "Enter your choice";

        cin >>
            choice;

        switch (choice)

        {

        case 1:

            n.insert();

            break;

        case 2:

            n.del();

            break;

        case 3:

            n.display();

            break;

        case 4:

            exit(1);

        default:

            cout << "wrong choice\n";
        }
    }

    return 0;
}

void node::insert()

{

    node *tmp;

    int added_item;

    tmp = new node;

    cout << "input the element for adding queue";

    cin >> added_item;

    tmp->info = added_item;

    tmp->link = NULL;

    if (front == NULL)

        front = tmp;

    else

        rear->link = tmp;

    rear = tmp;
}

void node::del()

{

    node *tmp;

    if (front == NULL)

        cout << "Queue UnderFlow\n";

    else

    {

        tmp = front;

        cout << "deleted element";

        cin >> tmp->info;

        front = front->link;

        delete (tmp);
    }
}

void node::display()

{

    node *ptr;

    ptr = front;

    if (front == NULL)

        cout << "Queue is empty\n";

    else

    {

        cout << "Queue elements\n";

        while (ptr != NULL)

        {

            cout << ptr->info;

            ptr = ptr->link;
        }

        cout << "\n";
    }
}
