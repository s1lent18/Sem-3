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
};