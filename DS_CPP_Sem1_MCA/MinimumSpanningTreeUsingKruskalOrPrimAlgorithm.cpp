#include <iostream>

#include <stdlib.h>

#define max 30

using namespace std;

struct edge

{

    int weight;

    int u;

    int v;

    struct edge *link;
};

struct edge *frnt = NULL;

struct edge *tmp;

int i, j, wt;

int father[max];

struct edge tree[max];

int wt_tree;

int cnt = 0;

void make_tree();

void insert_tree(int i, int j, int wt);
void insert_pque(int i, int j, int wt);
struct edge *del_pque();

void create_graph()

{

    int i, n, max_edges, origin, destin;

    cout << "Enter the no. of nodes : ";

    cin >> n;

    max_edges = n * (n - 1) / 2;

    for (i = 1; i < max_edges; i++)

    {

        cout << "Enter edges (0 0 to quit) weight : ";

        cin >> origin;

        cin >> destin;

        if ((origin == 0) && (destin == 0))

            break;

        cout << "Enter weight for this edge : ";
        cin >> wt;

        if (origin > n || destin > n || origin <= 0 || destin <= 0)

        {

            cout << "Invalid edge \n";

            i--;
        }
        else

            insert_pque(origin, destin, wt);
    }

    if (i < n - 1)

    {

        cout << "Spanning tree is not possible \n";
        exit(1);
    }
}

void insert_pque(int i, int j, int wt)

{

    struct edge *tmp, *q;

    tmp = (struct edge *)malloc(sizeof(struct edge));

    tmp->u = i;

    tmp->v = j;

    tmp->weight = wt;

    if (frnt == NULL || tmp->weight < frnt->weight)

    {

        tmp->link = frnt;

        frnt = tmp;
    }
    else

    {

        q = frnt;

        while (q->link != NULL && q->link->weight <= tmp->weight)

            q = q->link;

        tmp->link = q->link;

        q->link = tmp;

        if (q->link == NULL)

            tmp->link = NULL;
    }
}

void make_tree()

{

    edge *tmp;

    int node1, node2, root_n1, root_n2, wt_root = 0, n, cnt = 0;
    while (cnt < n - 1)

    {

        tmp = del_pque();

        node1 = tmp->u;

        node2 = tmp->v;

        cout << "N1 =" << node1;

        cout << "N2 =" << node2;

        while (node1 > 0)

        {

            root_n1 = node1;

            node1 = father[node1];
        }

        while (node2 > 0)

        {

            root_n2 = node2;

            node2 = father[node2];
        }

        cout << "root N1= " << root_n1;

        cout << "root N2= " << root_n2;

        if (root_n1 != root_n2)

        {

            insert_tree(tmp->u, tmp->v, tmp->weight);
            wt_tree = wt_tree + tmp->weight;
            father[root_n2] = root_n1;
        }
    }
}

void insert_tree(int i, int j, int wt)

{

    cout << "This edge inserted in the spanning tree \n";

    cnt++;

    tree[cnt].u = i;

    tree[cnt].v = j;

    tree[cnt].weight = wt;
}

struct edge *del_pque()

{

    struct edge *tmp;

    tmp = frnt;

    cout << "Edge processed \n"
         << tmp->u;

    cout << "Edge processed \n"
         << tmp->v;

    cout << "Edge processed \n"
         << tmp->weight;

    frnt = frnt->link;

    return tmp;
}

int main()

{

    int i, j, wt_tree, cnt = 0;

    struct edge tree[max];

    create_graph();

    make_tree();

    cout << "Edges to be included in spanning tree \n";

    for (i = 1; i <= cnt; i++)

    {

        cout << tree[i].u;

        cout << tree[j].v;
    }

    cout << "Weight of this spanning tree is :" << wt_tree;
    return 0;
}
