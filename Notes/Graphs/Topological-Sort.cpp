#include <iostream>
#include <queue>
using namespace std;

class Node
{
    public:
        char vertex;
        int indeg;

        Node()
        {

        };

        Node(char vertex, int indeg)
        {
            this->vertex = vertex;
            this->indeg = indeg;
        }
};

bool check(char * arr, char check, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == check)
        {
            return false;
        }
    }
    return true;
}

class Graph
{
    public:
        int numberofvertices;
        int ** adjacencymatrix;
        int * vertexindeg;

        Graph(int numberofvertices)
        {
            this->numberofvertices = numberofvertices;

            adjacencymatrix = new int * [numberofvertices];

            vertexindeg = new int [numberofvertices];
            
            for(int i = 0; i < numberofvertices; i++)
            {
                adjacencymatrix[i] = new int [numberofvertices];
            }
        }

        void append(char source, char dest)
        {
            adjacencymatrix[source % 65][dest % 65] = 1;

            vertexindeg[dest % 65]++;
        }

        void topologicalsort()
        {
            queue <int> Q;

            char * visited = new char [numberofvertices];

            int index = 0;

            do
            {
                for(int i = 0; i < numberofvertices; i++)
                {
                    if(vertexindeg[i] == 0 && check(visited, char(i + 65), numberofvertices))
                    {
                        Q.push(i);

                        visited[index] = char(i + 65);

                        index++;
                    }
                }

                while(!Q.empty())
                {
                    cout << char(Q.front() + 65) << " ";

                    for(int i = 0; i < numberofvertices; i++)
                    {
                        if(adjacencymatrix[Q.front()][i] == 1)
                        {
                            vertexindeg[i]--;
                        }
                    }
                    Q.pop();
                }
            } 
            while(vertexindeg[numberofvertices - 1] != 0);
            
            cout << char(numberofvertices + 64) << endl;
        }
};

int main()
{
    Graph G(6);

    G.append('A', 'B');
    G.append('A', 'C');
    G.append('B', 'D');
    G.append('B', 'E');
    G.append('C', 'D');
    G.append('C', 'E');
    G.append('D', 'F');
    G.append('E', 'F');

    G.topologicalsort();
}