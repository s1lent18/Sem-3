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

};