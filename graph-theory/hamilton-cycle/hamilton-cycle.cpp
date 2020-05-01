#include <iostream>
#include <fstream>

using namespace std;

#define MAX 100

int graph[MAX][MAX] = {{0}, {0}};
int C[MAX], B[MAX] = {1, 0};
int cycles[MAX][MAX];
int n, m, d = 0;

void readFile()
{
	fstream infile("input.txt", ios::binary | ios::in);
	int a, b;
	infile >> n >> m;
	while (infile >> a >> b)
		graph[a][b] = 1, graph[b][a] = 1;
	infile.close();
}

void printCycle(bool isCycle)
{
	fstream outfile("output.txt", ios::binary | ios::out);
	if (!isCycle)
	{
		cout << 0;
		outfile << 0;
	}
	else
	{
		cout << d;
		outfile << d;
		for (int i = 0; i < d; i++)
		{
			cout << endl;
			outfile << endl;
			for (int j = 0; j <= n; j++)
			{
				cout << cycles[i][j] << " ";
				outfile << cycles[i][j] << " ";
			}
		}
	}
	outfile.close();
}

void saveCycle(void)
{
	for (int i = n; i >= 0; i--)
		cycles[d][i] = B[i];
	d++;
	cout << endl;
}

void hamilton(int *B, int *C, int i)
{
	int j, k;
	for (j = 1; j <= n; j++)
	{
		if (graph[B[i - 1]][j] == 1 && C[j] == 0)
		{
			B[i] = j;
			C[j] = 1;
			if (i < n)
				hamilton(B, C, i + 1);
			else if (B[i] == B[0])
				saveCycle();
			C[j] = 0;
		}
	}
}

int main()
{
	// Ket qua duoc luu vao file: output.txt
	readFile();
	hamilton(B, C, 1);
	if (d == 0)
		printCycle(false);
	else
		printCycle(true);
	return 0;
}