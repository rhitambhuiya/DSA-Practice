#include <bits/stdc++.h>
using namespace std;

void set_zeroes_better(vector<vector<int>> &v, int m, int n)
{
    vector<int> row(m, 0);
    vector<int> col(n, 0);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            if(v[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
    }
    for(int  i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(row[i] == 1 || col[j] == 1)
                v[i][j] = 0;
}

void set_zeroes_optimal(vector<vector<int>> &v, int m, int n)
{
    int col1 = 1;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(v[i][j] == 0)
            {
                v[i][0] =  0;
                if(j == 0) col1 = 0;
                else v[0][j] = 0;
            }
        }
    }
    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(v[i][0] == 0 || v[0][j] == 0)
                v[i][j] = 0;
        }
    }
    if(v[0][0] == 0)    
        fill(v[0].begin(), v[0].end(), 0);
    if(!col1)
    {
        int i = 0;
        while(i < m)
            v[i++][0] = 0;
    }
}

int main(){
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;
    vector<vector<int>> matrix(m);
    int in;
    for(int i = 0; i < m; i++)
    {
        cout << endl << "Enter elements of row " << (i+1) <<": ";
        while(cin >> in)
            matrix[i].push_back(in);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    set_zeroes_optimal(matrix, m, n);
    cout << endl;
    for(auto i : matrix){
        for(int j : i)
            cout << j << " ";
        cout<< endl;}
    return 0;
}