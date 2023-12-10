#include <iostream>
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

            for(int i = 0; i < maxe; i++)
            {
                for(int j = 0; j < maxe; j++)
                {
                    adjacencymatrix[i][j] = 0;
                }
            }
        }

        void addedge(int source, int dest)
        {
            adjacencymatrix[source][dest] = 1;
        }

        void printgraph()
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
};

int main()
{
    Graph G(5);

    G.addedge(0, 0);
    G.addedge(0, 1);
    G.addedge(0, 3);
    G.addedge(1, 2);
    G.addedge(1, 0);
    G.addedge(4, 4);

    G.printgraph();
}