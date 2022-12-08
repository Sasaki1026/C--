#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minDistance(int dis[], bool visit[], int nodeNum)
{
    int min = INT_MAX;
    int index;
    for(int k = 0; k < nodeNum; k++){
        if(!visit[k] && dis[k] <= min){
            min = dis[k];
            index = k;
        }
    }

    return index;
}



int main()
{
    int node, source, destination;
    cin >> node >> source >> destination;
    int adj[node][node];
    int d[node];
    bool v[node];

    for (int i = 0; i < node; i++){//reset
        d[i] = INT_MAX;
        v[i] = false;
    }

    for(int i = 0; i < node; i++){//input adjcent
        for(int j = 0; j < node; j++){
            cin >> adj[i][j];
        }
    }

    d[source] = 0;

    for(int i = 0; i < node; i++){

        int min = minDistance(d,v,node);
        v[min] = true;
        for(int i = 0; i < node; i++){
            
            if(!v[i] && adj[min][i] && d[min] != INT_MAX && d[min] + adj[min][i] < d[i]){
                d[i] = d[min] + adj[min][i];
            }
        }
    }

    cout << d[destination] << endl;


    return 0;
}