#include<iostream>
using namespace std;


int main()
{
    int vertex, edge;
    cin >> vertex;
    cin >> edge;
    int adj[vertex][vertex];
    bool visited[vertex];
    int distance[vertex];



    //init
    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            adj[i][j] = 0;
        }
    }
    for(int i = 0; i < vertex; i++){
        visited[i] = false;
    }
    for(int i = 0; i < vertex; i++){
        distance[i] = 1e8;
    }

    //input edge
    for(int i = 0; i < edge; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a][b] = w;
    }

    //set 0 as root
    distance[0] = 0;

    for(int i = 0; i < vertex; i++){

        int a = -1, b = -1, min = 1e8;

        for(int j = 0; j < vertex; j++){
            if(!visited[j] && distance[j] < min){//find the closest point
                a = j;
                min = distance[j];
            }
        }

        if(a == -1) break;//all point visited
        visited[a] = true;

        for(b = 0; b < vertex; b++){
            if(!visited[b] && adj[a][b] < distance[b]){
                distance[b] = adj[a][b];
            }
        }

    }

    int MST = 0;

    for(int i = 0; i < vertex; i++){
        if(distance[i] != 1e8){
            MST += distance[i];
        }
    }

    cout << MST << endl;

    return 0;
}