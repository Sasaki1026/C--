#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> edgePair;

struct graph
{
    int V, E;
    vector<pair<int, edgePair> > edges;

    //constructor
    graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, {u,v}});
    }

    int Kruskal();

};

struct disjoint//check disjoint sets of all vertices
{
    int *parent, *rank;
    int n;

    disjoint(int n)
    {
        this->n = n;
        parent = new int[n+1];
        rank = new int[n+1];

        for (int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int a)
    {
        if(a != parent[a]){
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }

    void merge(int x, int y)
    {
        x = find(x), y = find(y);

        if (rank[x] > rank[y]) parent[y] = x;

        else parent[x] = y;
  
        if (rank[x] == rank[y]) rank[y]++;

    }
};

int graph::Kruskal()
{
    int mstWeight = 0;

    //sort edges increasing order
    sort(edges.begin(), edges.end());

    disjoint ds(V);

    vector<pair<int, edgePair>>::iterator it;
    for (it = edges.begin(); it != edges.end(); it++){
        int u = it->second.first;
        int v = it->second.second;

        int setU = ds.find(u);
        int setV = ds.find(v);

        if (setU != setV){
            mstWeight += it->first;
            ds.merge(setU, setV);
        }
    }

    return mstWeight;
}

int main()
{
    int vertex, edge;
    cin >> vertex >> edge;
    graph g(vertex, edge);

    for (int i = 0; i < edge; i++){
        int v1,v2,w;
        cin >> v1 >> v2 >> w;
        g.addEdge(v1,v2,w);
    }

    int ans = g.Kruskal();
    cout << ans << endl;

    return 0;

}