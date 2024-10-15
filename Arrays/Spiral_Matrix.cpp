#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int size = m * n;
    vector<int> output;
    int count = 0;
    int i, j;
    int flag = 0;
    while(count < size)
    {
        i = j = flag;
        flag++;
        while(j < n)
        {
            output.push_back(matrix[i][j]);
            j++;
            count++;
            if(count == size)
                return output;
        }
        j--;
        i++;
        while(i < m)
        {
            output.push_back(matrix[i][j]);
            i++;
            count++;
            if(count == size)
                return output;
        }
        i--;
        j--;
        while(j >= flag-1)
        {
            output.push_back(matrix[i][j]);
            j--;
            count++;
            if(count == size)
                return output;
        }
        j++;
        i--;
        while(i >= flag)
        {
            output.push_back(matrix[i][j]);
            i--;
            count++;
            if(count == size)
                return output;
        }
    }
    return output;
}

int main()
{
    cout << endl << "Enter the no. of rows: ";
    int m;
    cin >> m;
    cout << endl << "Enter the no. of columns: ";
    int n;
    cin >> n;
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
    vector<int> v = spiralOrder(matrix);
    cout << "Spiral Printing: ";
    for(auto i : v)
        cout << i << " ";
    return 0;
}