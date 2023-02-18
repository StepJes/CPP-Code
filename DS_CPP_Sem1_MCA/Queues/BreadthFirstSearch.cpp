#include <iostream>

#include <conio.h>

#include <iomanip>

using namespace std;

int adj[10][10], n, visited[10];

void bfs(int v)

{

    int q[10], front = -1, rear = -1, i;

    visited[v] = 1;

    q[++rear] = v;

    cout << "Visiting order...\n";

    while (front != rear)

    {

        v = q[++front];

        cout << v;

        for (i = 0; i < n; i++)

        {

            if (!visited[i] && adj[v][i])

            {

                visited[i] = 1;

                q[++rear] = i;
            }
        }
    }
}

int main()

{

    int i, j, m, a, b, v;

    char c;

    cout
        << "\nEnter the no of nodes And no of edges:";

    cin >> n >> m;

    for (i = 0; i < n; i++)

    {

        for (j = 0; j < n; j++)

        {

            adj[i][j] = 0;
        }
    }

    for (i = 1; i <= m; i++)

    {

        cout << "enter an edge\n";

        cin >> a >> b;

        adj[a][b] = 1;

        adj[b][a] = 1;
    }

    do

    {

        cout << "Adjancency matrix\n";

        for (i = 0; i < n; i++)

        {

            for (j = 0; j < n; j++)

            {

                cout << setw(4) << adj[i][j];
            }

            cout << "\n";
        }

        cout << "enter initial value\n";

        cin >> v;

        for (i = 0; i < n; i++)

        {

            visited[i] = 0;
        }

        bfs(v);

        cout << "Do u wish to continue(y/n)????";

        cin >> c;

    }

    while (c != 'n');

    getch();
}
