#include <process.h>
#include <conio.h>
#include <iostream>

using namespace std;
struct dnode
{
    int data;
    struct dnode *prev;

    struct dnode *next;
};
class link
{
    dnode *list;

public:
    dnode *head;
    link()
    {
        list = NULL;

        head = NULL;
    }
    void get_list();
    void display_list();
    void merge(link, link);
    friend void union_list(dnode *, dnode *);
    friend void intersact(dnode *, dnode *);
};
void link ::get_list()
{
    struct dnode *q, *tmp;
    int d, n;

    tmp = new dnode;

    cout << "Enter how many elements u want to enter ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter the elements ";
        cin >> d;
        tmp = new dnode;
        tmp->data = d;
        tmp->next = NULL;

        tmp->prev = NULL;
        if (head == NULL)
            head = tmp;
        else
        {

            q = head;
            while (q->next != NULL)

                q = q->next;

            q->next = tmp;
            tmp->prev = q;
        }
    }
}
void link ::display_list()
{
    dnode *q;
    q = head;

    if (q == NULL)
    {
        cout << " No data is in thelist..";
    }
    while (q != NULL)
    {
        cout << "" << q->data;
        q = q->next;

        cout << "\t";
    }
    cout << "\n";
}
void intersact(dnode *l1, dnode *l2)
{
    dnode *h;

    h = l2;
    while ((l1 != NULL) && (l2 != NULL))
    {
        if (l1->data == l2->data)
        {

            cout << l1->data << "\t";
            l1 = l1->next;
            l2 = l2->next;
        }
        else if (l1->data > l2->data)

            l2 = l2->next;
        else
            l1 = l1->next;
    }
}
void union_list(dnode *l1, dnode *l2)

{
    cout << endl;

    dnode *h;
    h = l1;
    while (l1 != NULL)
    {
        cout << l1->data << "\t";

        l1 = l1->next;
    }
    int flag = 0;
    while (l2 != NULL)
    {

        l1 = h;
        flag = 0;
        while (l1 != NULL)
        {
            if (l1->data == l2->data)

            {
                flag = 1;

                break;
            }
            l1 = l1->next;
        }
        if (flag == 0)
        {
            cout << l2->data << "\t";
        }
        l2 = l2->next;
    }
}

void link::merge(link l1, link l2)

{
    struct dnode *nxt_node, *pre_node, *pptr, *qptr;
    int dat;

    pptr = l1.head;
    qptr = l2.head;
    head = nxt_node = pre_node = NULL;
    while (pptr != NULL && qptr != NULL)
    {

        if (pptr->data <= qptr->data)
        {
            dat = pptr->data;
            pptr = pptr->next;
        }

        else

        {

            dat = qptr->data;
            qptr = qptr->next;
        }

        nxt_node = new dnode;
        nxt_node->data = dat;
        nxt_node->next = NULL;
        nxt_node->prev = NULL;
        if (head == NULL)

            head = nxt_node;
        else
        {
            pre_node->next = nxt_node;
            nxt_node->prev = pre_node;
        }
        pre_node = nxt_node;
    }
    if (pptr == NULL)
    {
        while (qptr != NULL)
        {

            nxt_node = new dnode;
            nxt_node->data = qptr->data;
            nxt_node->next = NULL;
            nxt_node->prev = NULL;
            if (head == NULL)

                head = nxt_node;

            else
            {
                pre_node->next = nxt_node;
                nxt_node->prev = pre_node;
            }
            pre_node = nxt_node;
            qptr = qptr->next;
        }
    }
    else if (qptr == NULL)
    {
        while (pptr != NULL)
        {
            nxt_node = new dnode;

            nxt_node->data = pptr->data;
            nxt_node->next = NULL;
            nxt_node->prev = NULL;

            if (head == NULL)
                head = nxt_node;
            else
            {
                pre_node->next = nxt_node;
                nxt_node->prev = pre_node;
            }

            pre_node = nxt_node;
            pptr = pptr->next;
        }
    }
    cout << "The lists are merged." << endl;

    return;
}
int main()
{
    link l;

    link l1, l2, l3;
    int ch;
    do
    {
        cout << " Operations onlist.." << endl;
        cout << "1.Union" << endl;
        cout << "2.Merge" << endl;

        cout << "3.Intersection" << endl;
        cout << "4.Exit" << endl;
        cout << " Enter ur choice:" << endl;
        cin >> ch;
        switch (ch)

        {
        case 1:
            cout << "Enter the First List. " << endl;
            l1.get_list(); // to create a first list
            cout << "Enter the Second List. " << endl;

            l2.get_list(); // to create a second list
            cout << "The first list is " << endl;

            l1.display_list();
            cout << endl;
            cout << "The second list is " << endl;
            l2.display_list();

            cout << endl
                 << endl
                 << "Union of First two List... " << endl;
            union_list(l1.head, l2.head);
            getch();

            break;
        case 2:

            cout << "Enter the First List in ascending order. " << endl;
            l1.get_list(); // to create a first list

            cout << "Enter the Second List in ascending order. " << endl;
            l2.get_list(); // to create a second list cout<<"The first list is "<<endl;

            l1.display_list();
            cout << "The second list is " << endl;
            l2.display_list();
            l3.merge(l1, l2);
            l3.display_list();

            getch();
            break;
        case 3:

            cout << "Enter the First List in ascending order. " << endl;
            l1.get_list(); // to create a first list

            cout << "Enter the Second List in ascending order. " << endl;
            l2.get_list(); // to create a second list cout<<"The first list is "<<endl;

            l1.display_list();
            cout << "The second list is " << endl;
            l2.display_list();
            cout << endl
                 << endl
                 << "Intersaction of First two list... " << endl;
            intersact(l1.head, l2.head);
            getch();
            break;

        case 4:
            exit(1);
        default:
            cout << " The option is invalid...";
        }
        getch();
    } while (1);
    getch();
}
