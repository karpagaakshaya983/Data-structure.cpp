#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    int cost[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 10, 6, 5},
        {0, 10, 0, 999, 15},
        {0, 6, 999, 0, 4},
        {0, 5, 15, 4, 0}
    };

    int visited[5] = {0};
    int edges = 0, minCost = 0;

    visited[1] = 1;

    cout << "Edges in Minimum Spanning Tree:\n";

    while (edges < n - 1)
    {
        int min = 999, u = 0, v = 0;

        for (int i = 1; i <= n; i++)
        {
            if (visited[i])
            {
                for (int j = 1; j <= n; j++)
                {
                    if (!visited[j] && cost[i][j] != 0 &&
                        cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        cout << u << " - " << v << " : " << min << endl;
        minCost += min;
        visited[v] = 1;
        edges++;
    }

    cout << "Minimum Cost: " << minCost;

    return 0;
}
