#include <iostream>
#include <fstream>

using namespace std;

#define MAX 100

int graph[MAX][MAX] = {{0}, {0}};
int eulerVertices[MAX];
int n, m, u = 1;

void readFile()
{
    fstream infile("input.txt", ios::binary | ios::in);
    int a, b;
    infile >> n >> m;
    while (infile >> a >> b)
        graph[a][b] = 1, graph[b][a] = 1;
    infile.close();
}

int countOddVertex()
{
    int deg, oddDeg = 0;
    for (int i = 1; i <= n; i++)
    {
        deg = 0;
        for (int j = 1; j <= n; j++)
            deg += graph[i][j];
        if (deg % 2 != 0)
            oddDeg++;
    }
    return oddDeg;
}

void printCycle(bool isCycle, int count)
{
    fstream outfile("output.txt", ios::binary | ios::out);
    if (isCycle == false)
    {
        outfile << 0;
        cout << 0;
    }
    else
    {
        outfile << 1 << endl;
        cout << 1 << endl;
        for (int i = count; i > 0; i--)
        {
            outfile << eulerVertices[i] << " ";
            cout << eulerVertices[i] << " ";
        }
    }
    outfile.close();
}

void searchEulerCycle()
{
    int v, x, top, count;
    int stack[MAX];
    top = 1;
    stack[top] = u;
    count = 0;
    do
    {
        v = stack[top];
        x = 1;
        while (x <= n && graph[v][x] == 0)
            x++;
        if (x > n)
        {
            count++;
            eulerVertices[count] = v;
            top--;
        }
        else
        {
            top++;
            stack[top] = x;
            graph[v][x] = 0;
            graph[x][v] = 0;
        }
    } while (top != 0);
    printCycle(true, count);
}

int main()
{
    // Ket qua duoc luu vao file: output.txt
    readFile();
    if (countOddVertex() > 0)
        printCycle(false, 0);
    else
        searchEulerCycle();
    return 0;
}