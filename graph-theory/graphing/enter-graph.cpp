#include <iostream>
#include <fstream>

#define V 100

using namespace std;

void adjacencyMatrix(int n);
void adjacencyList(int n);
void edgeList(int n);

void adjacencyMatrix(int n)
{
    fstream file("adjacencyMatrix.txt", ios::binary | ios::out);
    int edgeWeight;
    file << n << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cout << i << " - " << j << ": ";
            cin >> edgeWeight;
            if (edgeWeight != 0) file << i << " " << j << endl;
        }
    file.close();
}

void adjacencyList(int n)
{
    fstream file("adjacencyList.txt", ios::binary | ios::out);
    file << n << endl;
    string s;
    for (int i = 1; i <= n; i++) {
        cout << "Cac dinh ke voi dinh " << i << " (phan cach boi khoang trang): ";
        cin >> s;
        file << i << " " << s;
    }
    file.close();
}

void edgeList(int n) {
    fstream file("edgeList.txt", ios::binary | ios::out);
    char edge;
    int no_edge = 0;
    file << n << endl;
    cout << "Nhap cac canh cua do thi" << endl;
    cout << "-- Moi cap canh phan cach boi khoang trang" << endl;
    cout << "-- Nhap 0 de ket thuc" << endl;
    while (edge != '0') {
        no_edge++;
        cout << "Canh " << no_edge;
        cin >> edge;
        file << edge << endl;
    } 
    file.close();
}

int main() 
{
    int type = 0, n;
    cout << "Chon cach nhap: ";
    cout << endl << "1. Ma tran ke";
    cout << endl << "2. Danh sach ke";
    cout << endl << "3. Danh sach canh" << endl;
    cout << "Nhap lua chon: ";
    cin >> type;
    cout << "Nhap so dinh: ";
    cin >> n;
    switch (type)
    {
        case 1:
            adjacencyMatrix(n);
            break;
        case 2:
            adjacencyList(n);
            break;
        case 3:
            edgeList(n);
            break;
        default:
            cout << "Khong hop le!";
            break;
    }
}