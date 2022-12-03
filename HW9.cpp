#include <iostream>
using namespace std;

int main()
{

    int vertex, edge;
    cin >> vertex >> edge;
    int MSTedge = 0;

    // adjacency matrix
    int adjM[vertex][vertex] = {0};

    for (int i = 0; i < edge; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adjM[a][b] = w;
    }

    // create an array to check visited vertex
    bool visit[vertex];

    // initialise the visit array to false
    for (int i = 0; i < vertex; i++)
    {
        visit[i] = false;
    }

    visit[0] = true;

    int totalWeight = 0;

    while (MSTedge < vertex - 1)
    {

        int min = 1e9;
        int nextPoint;

        for (int i = 0; i < vertex; i++)
        {
            if (visit[i])
            {
                for (int j = 0; j < vertex; j++)
                {
                    if (!visit[j] && adjM[i][j])
                    {
                        if (min > adjM[i][j])
                        {
                            min = adjM[i][j];
                            nextPoint = j;
                        }
                    }
                }
            }
        }

        totalWeight += min;

        visit[nextPoint] = true;
        MSTedge++;
    }

    cout << totalWeight << endl;

    return 0;
}