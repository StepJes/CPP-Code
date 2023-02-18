#include <iostream>

#include <conio.h>

#include <stdlib.h>

using namespace std;

class Node

{

public:
    Node *next;

    int info;

} *front = NULL, *rear = NULL;

void fpush()

{

    int item;

    Node *temp, *q, *p;

    cout << "Enter the data :- ";

    cin >> item;

    temp = new Node;

    temp->info = item;

    temp->next = NULL;

    if (front == NULL)

    {

        front = temp;

        rear = temp;
    }

    else

    {

        q = front;

        while (q != NULL)

        {

            if (q->next == NULL)

            {

                cout << "q->data : " << q->info;

                p = q;
            }

            q = q->next;
        }

        p->next = temp;

        rear = temp;
    }
}

void rpush()

{

    int data;

    Node *temp, *q, *p;

    cout << "Enter the data :- ";

    cin >> data;

    temp = new Node;

    temp->info = data;

    temp->next = NULL;

    if (front == NULL)

    {

        front = temp;

        rear = temp;
    }

    else

    {

        q = front;

        while (q != NULL)

        {

            if (q->next == NULL)

            {

                cout << "q->data : " << q->info;

                p = q;
            }

            q = q->next;
        }

        p->next = temp;

        rear = temp;
    }
}

void fpop()

{

    Node *temp, *p;

    temp = front;

    front = temp->next;

    delete temp;

    /* while(temp!=NULL)

    {

    if(temp->next==NULL)

    {

    p=temp;

    }

    temp=temp->next;

    }*/

    // delete p;
}

void rpop()

{

    Node *temp, *p;

    temp = front;

    front = temp->next;

    delete temp;
}

void display()

{

    Node *tmp;

    tmp = front;

    cout << "Elements in queue are : " << endl;

    while (tmp != NULL)

    {

        cout << tmp->info << " | ";

        tmp = tmp->next;
    }

    cout << endl;
}

int main()

{

    int ch;

    while (1)

    {

        cout << "\n press 1 for insert from front";

        cout << "\n press 2 for insert from rear";

        cout << "\n press 3 for Delete from front";

        cout
            << "\n press 4 for Delete from rear";

        cout << "\n press 5 for Display";

        cout << "\n press 6 for exit";

        cin >> ch;

        switch (ch)

        {

        case 1:

            fpush();

            break;

        case 2:

            rpush();

            break;

        case 3:

            fpop();

            break;

        case 4:

            rpop();

            break;

        case 5:

            display();

            break;

        case 6:

            exit(0);

            break;

        default:

            cout << "Please enter correct choice :- ";
        }
    }

    getch();

    return 0;
}
