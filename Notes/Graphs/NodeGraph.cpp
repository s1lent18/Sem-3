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
        }

        void dijkstra(char startVertex) 
        {
            int distance[maxe];
            bool visited[maxe];

            for (int i = 0; i < numberofvertices; i++) 
            {
                distance[i] = 1000000;
                visited[i] = false;
            }

            distance[startVertex % 65] = 0;

            for (int count = 0; count < numberofvertices - 1; count++) 
            {
                int minDistance = 1000000;
                int minIndex;

                for (int v = 0; v < numberofvertices; v++) 
                {
                    if (!visited[v] && distance[v] <= minDistance) 
                    {
                        minDistance = distance[v];
                        minIndex = v;
                    }
                }

                visited[minIndex] = true;

                for (int v = 0; v < numberofvertices; v++) 
                {
                    if (!visited[v] && adjacencymatrix[minIndex][v] && distance[minIndex] != 1000000 && distance[minIndex] + adjacencymatrix[minIndex][v] < distance[v])
                    {
                        distance[v] = distance[minIndex] + adjacencymatrix[minIndex][v];
                    }
                }
            }

            cout << "Shortest distances from vertex " << startVertex << " to other vertices:" << endl;

            for (int i = 0; i < numberofvertices; i++) 
            {
                cout << startVertex << " to " << char(i + 65) << ": " << distance[i] << endl;
            }
        }

        void display()
        {
            for(int i = 0; i < numberofvertices; i++)
            {
                for(int j = 0; j < numberofvertices; j++)
                {
                    cout << adjacencymatrix[i][j] << " ";
                }
                cout << endl;
            }
        }

        void prims()
        {
            vector<int> parent(numberofvertices, -1);
            vector<int> key(numberofvertices, 100000);
            vector<bool> mstset(numberofvertices, false);

            key[0] = 0;

            for (int i = 0; i < numberofvertices - 1; i++)
            {
                int minkey = 100000;
                int u;

                for (int j = 0; j < numberofvertices; j++)
                {
                    if (!mstset[j] && key[j] < minkey)
                    {
                        minkey = key[j];
                        u = j;
                    }
                }

                mstset[u] = true;

                for (int v = 0; v < numberofvertices; v++)
                {
                    if (adjacencymatrix[u][v] && !mstset[v] && adjacencymatrix[u][v] < key[v])
                    {
                        parent[v] = u;
                        key[v] = adjacencymatrix[u][v];
                    }
                }
            }

            cout << "Edges of Minimum Spanning Tree (Prim's Algorithm):" << endl;

            for (int i = 1; i < numberofvertices; i++)
            {
                cout << char(parent[i] + 65) << " - " << char(i + 65) << " Weight: " << adjacencymatrix[i][parent[i]] << endl;
            }
        }

        void kruskal() 
        {
            // Helper structure for sorting edges
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

            sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) 
            {
                return a.weight < b.weight;
            });

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

    char startVertex = 'A';

    G.prims();

    return 0;
}
