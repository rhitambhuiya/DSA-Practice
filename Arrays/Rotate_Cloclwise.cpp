#include <bits/stdc++.h>
using namespace std;

void rotate_brute(vector<vector<int>> &v, int m)
{
    vector<vector<int>> copy1(m, vector<int>(m));
    int it = m-1;
    for(auto i : v){
        int it1 = 0;
        for(auto j : i)
        {
            copy1[it1++][it] = j;
        }
        it--;
    }
    v.assign(copy1.begin(), copy1.end());
}

void rotate_optimal(vector<vector<int>> &v, int m)
{
    //Clockwise rotated matrix is basically the transpose of the original matrix with each row reversed
    for(int i = 0; i < m; i++)
        for(int j = 0; j < i; j++)
            swap(v[i][j], v[j][i]);
    for(int i = 0; i < m; i++)
        reverse(v[i].begin(), v[i].end());
}

int main(){
    int m;
    cout << "Enter the number of rows and columns: ";
    cin >> m;
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
    rotate_optimal(matrix, m);
    cout << endl;
    for(auto i : matrix){
        for(int j : i)
            cout << j << " ";
        cout<< endl;}
    return 0;
}