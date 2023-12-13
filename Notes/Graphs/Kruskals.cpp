#include <iostream>
#include <vector>
using namespace std;

const int maxe = 10;

class Graph 
{
    private:
        int numberofvertices;
        int adjacencymatrix[maxe][maxe];

    public:
        Graph(int numberofvertices) 
        {
            this->numberofvertices = numberofvertices;

            for (int i = 0; i < maxe; i++) 
            {
                for (int j = 0; j < maxe; j++) 
                {
                    adjacencymatrix[i][j] = 0;
                }
            }
        }

        void addedge(char source, char dest, int weight) 
        {
            adjacencymatrix[source % 65][dest % 65] = weight;
            adjacencymatrix[dest % 65][source % 65] = weight;
        }

        void kruskal() 
        {
            struct Edge 
            {
                int src, dest, weight;
            };

            vector<Edge> edges;
            for (int i = 0; i < numberofvertices; i++) 
            {
                for (int j = 0; j < numberofvertices; j++) 
                {
                    if (adjacencymatrix[i][j] != 0) 
                    {
                        edges.push_back({i, j, adjacencymatrix[i][j]});
                    }
                }
            }

            // sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) 
            // {
            //     return a.weight < b.weight;
            // });

            vector<int> component(numberofvertices, -1);

            cout << "Edges of Minimum Spanning Tree (Kruskal's Algorithm):" << endl;

            for (const auto& edge : edges) 
            {
                int u = edge.src;
                int v = edge.dest;

                if (component[u] != component[v]) 
                {
                    cout << char(u + 65) << " - " << char(v + 65) << " Weight: " << edge.weight << endl;

                    int oldComponent = component[u];
                    int newComponent = component[v];

                    for (int i = 0; i < numberofvertices; i++) 
                    {
                        if (component[i] == oldComponent) 
                        {
                            component[i] = newComponent;
                        }
                    }
                }
            }
        }

};

int main() 
{
    Graph G(6);

    G.addedge('A', 'B', 1);
    G.addedge('A', 'C', 1);
    G.addedge('B', 'C', 2);
    G.addedge('B', 'D', 2);
    G.addedge('B', 'E', 1);
    G.addedge('C', 'E', 2);
    G.addedge('D', 'E', 3);
    G.addedge('D', 'F', 1);
    G.addedge('E', 'F', 2);
    return 0;
}
