#include <iostream>

#include <stdio.h>
#include <malloc.h>
using namespace std;
class node
{

public:
    int info;
    node *link;
    void create_list(int data);
    void addatbeg(int data);
    void addafter(int data, int pos);
    void display();
    void del(int data);
    void search(int data);
    void count();
    void reverse();
    void sort();
};
node *start;
void node::create_list(int data)
{
    node *q, *tmp;
    tmp = new node;
    tmp->info = data;
    tmp->link = NULL;
    if (start == NULL)
        start = tmp;
    else
    {
        q = start;
        while (q->link != NULL)
            q = q->link;

        q->link = tmp;
    }
}
void node::addatbeg(int data)
{
    node *tmp;
    tmp = new node;
    tmp->info = data;
    tmp->link = start;
    start = tmp;
}
void node::addafter(int data, int pos)
{
    node *tmp, *q;
    int i;
    q = start;
    for (i = 0; i < pos - 1; i++)
    {
        q = q->link;
        if (q == NULL)
        {

            cout << "There are less than" << pos << "elements";
            return;
        }
    }
    tmp = new node;
    tmp->link = q->link;
    tmp->info = data;
    q->link = tmp;
}
void node::del(int data)
{
    node *tmp, *q;
    if (start->info == data)
    {
        tmp = start;
        start = start->link;
        delete tmp;
        return;
    }
    q = start;
    while (q->link->link != NULL)
    {
        if (q->link->info == data)
        {
            tmp = q->link;
            q->link = tmp->link;
            delete tmp;
            return;
        }
        q = q->link;
    }
    if (q->link->info = data)
    {
        tmp = q->link;
        delete tmp;
        q->link = NULL;
        return;
    }
    cout << "Element" << data << "Not found\n";
}

void node::search(int data)
{
    node *ptr = start;
    int pos = 1;
    while (ptr != NULL)
    {
        if (ptr->info == data)
        {
            cout << "Element " << data << " found at position\n"
                 << pos;
            return;
        }

        ptr = ptr->link;
        pos++;
    }
    if (ptr == NULL)
        cout << "Element " << data << " not found in list\n";
}
void node::count()
{
    node *q = start;
    int cnt = 0;
    while (q != NULL)
    {
        q = q->link;
        cnt++;
    }
    cout << "Number of elements are:" << cnt;
}
void node::reverse()
{
    node *p1, *p2, *p3;
    if (start->link == NULL)
        return;
    p1 = start;
    p2 = p1->link;
    p3 = p2->link;
    p1->link = NULL;

    p2->link = p1;
    while (p3 != NULL)

    {
        p1 = p2;
        p2 = p3;
        p3 = p3->link;
        p2->link = p1;
    }
    start = p2;
}

void node::sort()
{
    int t;
    node *q, *tmp;
    if (start == NULL)
        cout << "\n There are no elements in the list";
    else
    {
        q = start;
        while (q != NULL)
        {
            tmp = q->link;
            while (tmp != NULL)

            {
                if (q->info > tmp->info)
                {
                    t = q->info;
                    q->info = tmp->info;
                    tmp->info = t;
                }
                tmp = tmp->link;
            }
            q = q->link;
        }
        cout << "\n\n\t List sorted successfully\n";
    }
}
void node::display()
{
    node *q;
    if (start == NULL)
    {
        cout << "List is empty\n";
        return;
    }
    q = start;
    cout << "List is :\n";

    while (q != NULL)

    {
        cout << "" << q->info << "\t";
        q = q->link;
    }
    cout << "\n";
}
int main()
{
    node n1;
    int ch, n2, m, pos, i;
    start = NULL;

    while (1)
    {
        cout << "1.Create list\n";
        cout << "2.Add at beginning\n";
        cout << "3.Add after\n";
        cout << "4.Delete\n";
        cout << "5.Search\n";
        cout << "6.Count\n";
        cout << "7.Revese\n";
        cout << "8.Sort\n";
        cout << "9.Display\n";
        cout << "10.Quit\n";
        cout << "Enter your choice: ";

        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "How many nodes you want:";
            cin >> n2;
            for (i = 0; i < n2; i++)
            {
                cout << "Enter the element:";
                cin >> m;
                n1.create_list(m);
            }
            break;
        case 2:
            cout << "Enter the element:";
            cin >> m;
            n1.addatbeg(m);
            break;
        case 3:
            cout << "Enter the element: ";
            cin >> m;

            cout << "Enter the position after which this element is inserted: ";
            cin >> pos;

            n1.addafter(m, pos);
            break;

        case 4:
            if (start == NULL)
            {
                cout << "List is empty";
                continue;
            }
            cout << "Enter the element for deletion: ";
            cin >> m;
            n1.del(m);
            break;
        case 5:

            cout
                << "Enter the element to be searched\n";
            cin >> m;

            n1.search(m);
            break;
        case 6:
            n1.count();
            break;
        case 7:
            n1.reverse();
            break;
        case 8:
            n1.sort();
            break;

        case 9:
            n1.display();
            break;
        case 10:
            exit(1);
        default:
            cout << "Wrong choice";
        }
    }
    return 0;
}
