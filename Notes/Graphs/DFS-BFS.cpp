#include <iostream>
#include <queue>
#include <stack>
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

        void addedge(char source, char dest, int weight)
        {
            adjacencymatrix[source % 65][dest % 65] = weight;
        }

        void bfs(char startVertex)
        {
            bool visited[maxe] = {false};

            queue <int > Q;

            int start = startVertex % 65;

            visited[start] = true;

            Q.push(start);

            while(!Q.empty())
            {
                int curr = Q.front();
                
                Q.pop();

                for(int i = 0; i < numberofvertices; i++)
                {
                    if(adjacencymatrix[curr][i] && !visited[i])
                    {
                        visited[i] = 1;

                        cout << char(i + 65) << " ";

                        Q.push(i);
                    }
                }
            }
            cout << endl;
        }

        void dfs(char startVertex)
        {
            bool visited[maxe] = {false};

            stack <int > Q;

            int start = startVertex % 65;

            visited[start] = true;

            cout << startVertex << " ";

            Q.push(start);

            while(!Q.empty())
            {
                int curr = Q.top();
                
                Q.pop();

                for(int i = 0; i < numberofvertices; i++)
                {
                    if(adjacencymatrix[curr][i] && !visited[i])
                    {
                        visited[i] = 1;

                        cout << char(i + 65) << " ";

                        Q.push(i);
                    }
                }
            }
            cout << endl;
        }
};

int main() 
{
    Graph G(6);

    G.addedge('A', 'B', 1);
    G.addedge('A', 'C', 5);
    G.addedge('B', 'C', 2);
    G.addedge('B', 'D', 2);
    G.addedge('B', 'E', 1);
    G.addedge('D', 'E', 3);
    G.addedge('D', 'F', 1);
    G.addedge('E', 'F', 2);
    G.addedge('F', 'A', 1);

    char startVertex = 'A';

    G.bfs(startVertex);
    G.dfs(startVertex);

    return 0;
}