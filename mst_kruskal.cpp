#include <iostream>
using namespace std;
*/ this code targets an acyclic directed weighted graph/*
int adjacencymatrix[9][9];
int parent[9];
int minimum;
int u, v, total, vertice;
int no_of_edges = 1;
void graph()
{
    cout << "enter no of vertices:" << endl;
    cin >> vertice;
    printf("\nEnter the edges adjacency matrix:\n");
    for (int i = 0; i < vertice; i++)
    {
        for (int j = 0; j < vertice; j++)
        {
            cin >> adjacencymatrix[i][j];
            if (adjacencymatrix[i][j] == 0)
            {
                adjacencymatrix[i][j] = 999;
            }
        }
    }
}
// void graphdisplay(){
//      for (int i = 0; i < vertice; i++)
//     {
//         for (int j = 0; j <vertice; j++)
//         {
//             cout<<adjacencymatrix[i][j]<<" ";

//         }
//         cout<<endl;

//     }

// }
void kruskal()
{
    while (no_of_edges < vertice)
    {
        minimum = 999;

        for (int i = 0; i < vertice; i++)
        {
            for (int j = 0; j < vertice; j++)
            {
                if (adjacencymatrix[i][j] < minimum)
                {
                    minimum = adjacencymatrix[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        while (parent[u] != 0)
        {
            u = parent[u];
        }
        while (parent[v] != 0)
        {
            v = parent[v];
        }
        if (u != 0)
        {
            no_of_edges++;
            cout << "edge found =>(" << u << "," << v << ") = " << minimum << endl;
            cout << endl;
            total += minimum;
            parent[v] = u;
        }
     
        adjacencymatrix[u][v] = adjacencymatrix[v][u] = 999;
       // cout << "weight of minimum spanning tree is =" << total << endl;
    }

    cout << "weight of minimum spanning tree is =" << total << endl;
}
int main()

{
    graph();
    kruskal(); 
    return 0;
}
