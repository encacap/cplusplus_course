#include <iostream>
#include <fstream>

using namespace std;

#define MAX 100

void readFile();

int graph[MAX][MAX] = {0};
int previous[MAX], queue[MAX], parent[MAX];
bool notSet[MAX];
int n, s, t;

void readFile()
{
	fstream infile("input.txt", ios::binary | ios::in);
	int a;
	infile >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			infile >> a;
			graph[i][j] = a;
		}
	infile.close();
}

int minKey(int key[], bool mstSet[])
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < n; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;
	return min_index;
}

void primMST()
{
	int key[MAX];
	bool mstSet[MAX];
	char chose;
	int a = -1, b = -1;

	cout << "Cay khung co chua canh bat buoc? (Y/N): ";
	cin >> chose;

	if (chose == 'y' || chose == 'Y')
	{
		cout << "Nhap hai dinh cua canh bat buoc: ";
		cin >> a >> b;
		if (graph[a][b] == 0)
		{
			cout << "Khong the tim thay cay khung nho nhat chua canh " << a << " - " << b;
			return;
		}
	}
	else
		a = 0;

	for (int i = 0; i < n; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[a] = 0;
	parent[a] = -1;

	for (int count = 0; count < n; count++)
	{
		int u = minKey(key, mstSet);

		if (count == 0 && a != -1 && b != -1)
			u = a;
		else if (count == 1 && a != -1 && b != -1)
			u = b;

		mstSet[u] = true;
		for (int v = 0; v < n; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}
}

void printMST()
{
	fstream outfile("output.txt", ios::binary | ios::out);
	cout << "Danh sach canh cua cay khung: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (parent[i] == -1)
			continue;
		outfile << i << " - " << parent[i] << endl;
		cout << i << " - " << parent[i] << endl;
	}
	outfile.close();
}

int main()
{
	// Giua hai dinh u va v khong co duong di thi graph[u][v] = 0
	// Dinh bat dau tu 0
	// Ket qua duoc luu vao file: output.txt
	readFile();
	primMST();
	printMST();
	return 0;
}