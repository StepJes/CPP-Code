#include <iostream>
using namespace std;

class adjMatrix

{

    int **adj;

    bool *visited;

    int n, i, j;

public:
    adjMatrix(int n)

    {

        this->n = n;

        visited = new bool[n];

        adj = new int *[n];

        for (i = 1; i <= n; i++)

        {

            adj[i] = new int[n];

            for (j = 1; j <= n; j++)

            {

                adj[i][j] = 0;
            }
        }
    }

    int add_edge(int origin, int dest)

    {

        if (origin > n || dest > n || origin < 0 || dest < 0)

        {

            cout << "Wrong nodes";
        }
        else

        {

            adj[origin][dest] = 1;
        }
    }

    int display()

    {

        for (i = 1; i <= n; i++)

        {

            for (j = 1; j <= n; j++)

            {

                cout << adj[i][j] << "\t";
            }

            cout << "\n";
        }
    }
};

int main()

{

    int nodes, Max_edges, i, origin, dest;

    cout << "Enter maximum node: ";

    cin >> nodes;

    adjMatrix am(nodes);

    Max_edges = nodes * (nodes - 1);

    cout << "Enter -1 -1 to exit";

    for (i = 0; i < Max_edges; i++)

    {

        cout << "\nEnter edges: ";

        cin >> origin >> dest;

        if ((origin == -1) && (dest == -1))

            break;

        else

            am.add_edge(origin, dest);
    }

    am.display();

    return 0;
}
