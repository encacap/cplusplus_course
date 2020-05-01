#include <iostream>
#include <fstream>

using namespace std;

#define MAX 100

void readFile();

int graph[MAX][MAX] = {0};
int previous[MAX], queue[MAX];
bool notSet[MAX];
int n, s, t;

void readFile() 
{
    fstream infile("../Graphing/adjacencyMatrix.txt", ios::binary | ios::in);
    int a, b;
    infile >> n;
    while (infile >> a >> b) graph[a][b] = 1;
    for (int i = 1;i <= n; i++) { 
        notSet[i] = true; 
        previous[i] = 0; 
    }
    infile.close();
}

void result(void)
{ 
    if (previous[t] == 0) { 
        cout << "Khong co duong di tu " << s << " den " << t; 
        return; 
    } 
    cout << "Duong di tu " << s << " den " << t << " la: "; 
    int j = t;
    cout << t << " <= "; 
    while(previous[j] != s) { 
        cout << previous[j] << " <= "; 
        j = previous[j]; 
    } 
    cout << s; 
} 

void DFS(int u){
    notSet[u] = false;
    for (int v = 1; v <= n; v++) {
        if (notSet[v] == true && graph[u][v] == 1) {
            previous[v] = u;
            DFS(v);
        }
    }
}

void BFS(int s) { 
    int qHead = 1, qTail = 1, u;
    queue[qHead] = s;
    notSet[s] = false;
    while (qHead <= qTail) {
        u = queue[qHead];
        qHead = qHead + 1; 
        for (int p = 1;p <= n; p++) { 
            if(graph[u][p] && notSet[p]) { 
                qTail = qTail + 1;
                queue[qTail] = p; 
                notSet[p]= false;
                previous[p] = u; 
            } 
        } 
    } 
} 

int main() {
    cout << "Nhap hai dinh can tim duong di: ";
    cin >> s >> t;
    readFile();
    DFS(s);
    result();
    return 0;
}