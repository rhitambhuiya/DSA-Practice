#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void reverse(vector<int> &v, int i, int j)
{
    while(i < j){
    swap(v[i], v[j]);
    i++;
    j--;}
}

int main(){
    vector<int> v;
    int in;
    while(cin >> in)
        v.push_back(in);
    int n = v.size();
    int i = n-2;
    while(i >= 0 && v[i] >= v[i+1]) i--;

    if(i >= 0)
    {
        int j = n-1;
        while(j > i)
        {
            if(v[j] > v[i]){
                swap(v[j], v[i]);
                break;}
            j--;
        }
    }
    reverse(v.begin()+i+1, v.end());

    cout << endl;
    for(int i : v)
        cout << i << " ";
}