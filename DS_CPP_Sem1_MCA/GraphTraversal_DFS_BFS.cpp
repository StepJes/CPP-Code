#include <iostream>

#include <stdio.h>

#define max 20

using namespace std;

int adj[max][max];

bool visited[max];

int n;

int frnt;

void create_graph()

{

    int i, max_edges, origin, destin;

    cout << "Enter no. of nodes: ";

    cin >> n;

    max_edges = n * (n - 1);

    for (i = 1; i <= max_edges; i++)

    {

        cout << "Enter edge (0 0 to quit) : " << i << "\n";
        cin >> origin >> destin;

        if (origin == 0 || destin == 0)

            break;

        if (origin > n || destin > n || origin <= 0 || destin <= 0)

        {

            cout << "Invalid edge \n";

            i--;
        }
        else

        {

            adj[origin][destin] = 1;
        }
    }
}

void display()

{

    int i, j;

    for (i = 1; i <= n; i++)

    {

        for (j = 1; j <= n; j++)

        {

            cout << adj[i][j] << "\t";
        }

        cout << "\n";
    }
}

void dfs(int v)

{

    int i, stack[max], top = -1, pop_v, j, t;
    int c;

    top++;

    stack[top] = v;

    while (top >= 0)

    {

        pop_v = stack[top];

        top--;

        if (visited[pop_v] == false)

        {

            cout << pop_v;

            visited[pop_v] = true;
        }
        else

            continue;

        for (i = n; i >= 1; i--)

        {

            if (adj[pop_v][i] == 1 && visited[i] == false)

            {

                top++;

                stack[top] = i;
            }
        }
    }
}

void bfs(int v)

{

    int i, frnt, rear;

    int que[20];

    frnt = rear = -1;

    cout << v;

    visited[v] = true;

    rear++;

    frnt++;

    que[rear] = v;

    while (frnt <= rear)

    {

        v = que[frnt];

        frnt++;

        for (i = 1; i <= n; i++)

        {

            if (adj[v][i] == 1 && visited[i] == false)

            {

                cout << i << "\t";

                visited[i] = true;

                rear++;

                que[rear] = i;
            }
        }
    }
}

void adj_nodes(int v)

{

    int i;

    for (i = 1; i <= n; i++)

    {

        int i;

        for (i = 1; i <= n; i++)

        {

            if (adj[v][i] == 1)

                cout << i;

            cout << "\n";
        }
    }
}

int main()

{

    int i, v, ch;

    create_graph();

    while (1)

    {

        cout << "\n";

        cout << "1. Adjacency Matrix \n";

        cout << "2. Depth first search using stack\n";

        cout << "3. Breadth first search\n";

        cout << "4. Exit \n";

        cout << "Enter your choice\n";

        cin >> ch;

        switch (ch)

        {

        case 1:

            cout << "Adjacency Matrix \n";

            display();

            break;

        case 2:

            cout << "Enter starting node for Depth First Search: \n";

            cin >> v;

            for (i = 1; i <= n; i++)

                visited[i] = false;

            dfs(v);

            break;

        case 3:

            cout << "Enter starting node for Breadth First Search: \n";

            cin >> v;

            for (i = 1; i <= n; i++)

                visited[i] = false;

            bfs(v);

            break;

        case 4:

            break;

        default:

            cout << "Wrong Choice";

            break;
        }
    }

    return 0;
}
