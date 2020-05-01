#include <iostream>
#include <fstream>

#define V 10

using namespace std;

int readFile(int graph[V][V]) 
{
    fstream infile("adjacencyMatrix.txt", ios::binary | ios::in);
    int a, b, n;
    infile >> n;
    while (infile >> a >> b) graph[a][b] = 1;
    infile.close();
    return n;
}

bool isScalar(int graph[V][V], int n) 
{
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            if (graph[i][j] != graph[j][i]) return false;
    return true;
}

int main() {
    int graph[V][V] = {{0}};
    int n = readFile(graph);
    if (isScalar(graph, n)) cout << "Do thi vo huong";
    else cout << "Do thi co huong";
    return 0;
}