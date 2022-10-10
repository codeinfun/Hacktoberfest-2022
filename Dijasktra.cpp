#include <iostream>
using namespace std;

class graphs
{
public:
    int **matrix;
    int vertices;
    int *visited;
    graphs(int node);
    void add_edge(int n1, int n2, int weight);
    void display();
    void dijkstra(int vertex, int to);
    void prims(int ver);
};

graphs::graphs(int vertices)
{
    this->vertices = vertices;

    matrix = new int *[vertices];
    visited = new int[vertices];
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
        matrix[i] = new int[vertices];
        for (int j = 0; j < vertices; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void graphs::add_edge(int n1, int n2, int weight)
{
    matrix[n1][n2] = weight;
    matrix[n2][n1] = weight;
}

void graphs::display()
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void graphs::dijkstra(int vertex, int to)
{
    int veryMinPrevious;
    int prev = 0;
    int distance[vertices][vertices];
    int index = vertex;
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
        //IF PATH EXISTS THEN I HAVE TO INITIALIZE IT
        if (matrix[vertex][i] != 0)
        {
            distance[i][0] = i;
            distance[i][1] = matrix[vertex][i];
        }
        //OR ELSE INTILIZE IT TO -1
        else
        {
            distance[i][0] = -1;
            distance[i][1] = -1;
        }
    }
    
    distance[vertex][vertex] = 0;
    distance[vertex][vertex + 1] = 0;
    visited[vertex] = 1;
    
    for (int i = 0; i < vertices; i++)
    {
        visited[index] = 1;
        veryMinPrevious = 20000;
        for (int j = 0; j < vertices; j++)
        {
            if (!visited[j] && matrix[index][j] != 0 && matrix[index][j] < veryMinPrevious)
            {
                veryMinPrevious = matrix[index][j];
                prev += veryMinPrevious;
                index = j;
            }
        }
        if (distance[index][0] == -1 || distance[index][1] > prev)
        {
            distance[index][0] = index;
            distance[index][1] = prev;
        }
    }
    for (int i = 0; i < to; i++)
    {
        cout << "Edge: " << distance[i][0] << " Distance: " << distance[i][1] << "\n";
    }
}

void graphs::prims(int ver)
{
    int min;
    int prev = 0;
    int dist[vertices][vertices];
    int ind = ver;
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
        if (matrix[ver][i] != 0)
        {
            dist[i][0] = i;
            dist[i][1] = matrix[ver][i];
        }
        else
        {
            dist[i][0] = -1;
            dist[i][1] = -1;
        }
    }
    dist[ver][ver] = 0;
    dist[ver][ver + 1] = 0;
    visited[ver] = 1;
    for (int i = 0; i < vertices; i++)
    {
        visited[ind] = 1;
        min = 9999;
        for (int j = 0; j < vertices; j++)
        {
            if (!visited[j] && matrix[ind][j] != 0 && matrix[ind][j] < min)
            {
                min = matrix[ind][j];
                prev += min;
                ind = j;
            }
        }
        if (dist[ind][0] == -1 || dist[ind][1] > prev)
        {
            dist[ind][0] = ind;
            dist[ind][1] = min;
        }
    }
    for (int i = 0; i < vertices; i++)
    {
        cout << "Edge: " << dist[i][0] << " Distance: " << dist[i][1] << "\n";
    }
}

int main()
{
    graphs g(3);
    g.add_edge(0, 1, 2);
    g.add_edge(1, 2, 1);
    g.add_edge(0, 2, 4);

    cout<<"MATRIX OF GRAPH IS"<<endl;
    g.display();

    cout<<endl;
    cout<<endl;

    cout << "Dijkstra"<<endl;
    g.dijkstra(0, 3);

    cout<<endl;
    cout<<endl;
    cout << "Prim's\n";
    g.prims(0);

    return 0;
}