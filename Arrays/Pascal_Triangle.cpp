#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r)
    {
        int res = 1;
        for(int i = 0; i < r; i++)
        {
            res *= n - i;
            res /= i + 1;
        }
        return res;
    }

vector<int> generateRows(int r)
{
    vector<int> row;
    row.push_back(1);
    for(int i = 1; i < r; i++)
    {
        int curr =(row.back() * (r - i)) / i;
        row.push_back(curr);
    }
    return row;
}

void generate(int numRows) {
    vector<vector<int>> result;
    vector<int> row;
    if(numRows == 0)
    {
        cout << "Not Possible";
        return;
    }
    for(int i = 1; i <= numRows; i++)
    {
        row.clear();
        row = generateRows(i);
        result.push_back(row);
    }
    for(auto i : result)
    {
        for(int j : i)
            cout << j << " ";
        cout << endl;
    }
}

void printRow(int r)
{
    vector<int> row = generateRows(r);
    for(int  i : row)
        cout << i << " ";
}

void printElement(int r, int c)
{
    cout << nCr(r - 1, c - 1);
}

int main(){
    int ch;
    cout << "Enter 1. To generate entire Pascal's Triangle   2. To print a certain row   3. To print a certain element: " ;
    cin >> ch;
    switch(ch)
    {
        int n;
        case 1:
            cout << "Enter the number of rows: ";
            cin >> n;
            generate(n);
            break;
        case 2:
            cout << "Enter the row number: ";
            cin >> n;
            printRow(n);
            break;
        case 3:
            cout << "Enter the row number: ";
            int r;
            cin >> r;
            cout << "Enter the column number: ";
            int c;
            cin >> c;
            printElement(r, c);
            break;
    }
}