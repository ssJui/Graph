#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> color;
int n, m;

bool isSafe(int v, int c)
{
    for(int u = 0; u < n; u++)
    {
        if(graph[v][u] == 1 && color[u] == c)
            return false;
    }
    return true;
}

bool graphColoring(int v)
{
    
    if(v == n)
        return true;

    for(int c = 1; c <= m; c++)
    {
        if(isSafe(v, c))
        {
            color[v] = c;

            if(graphColoring(v + 1))
                return true;

            color[v] = 0;
        }
    }

    return false;
}

int main()
{
    cout << "Enter number of vertices: ";
    cin >> n;

    graph.assign(n, vector<int>(n));

    cout << "Enter adjacency matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Enter number of colors (m): ";
    cin >> m;

    color.assign(n, 0);

    if(graphColoring(0))
    {
        cout << "\nColor Assignment:\n";

        for(int i = 0; i < n; i++)
        {
            cout << "Vertex " << i
                 << " -> Color " << color[i]
                 << endl;
        }
    }
    else
    {
        cout << "No solution exists with "
             << m << " colors.\n";
    }

    return 0;
}