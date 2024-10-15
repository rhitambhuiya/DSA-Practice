#include <bits/stdc++.h>
using namespace std;

vector<int> union_Arr(int arr1[], int arr2[], int n, int m)
{
    vector<int> v;
    set<int> a;
    int i, j;
    i = j = 0;
    while(i < n && j < m)
    {
        if(arr1[i] <= arr2[j])
        {
            a.insert(arr1[i]);
            i++;
        }
        else
        {
            a.insert(arr2[j]);
            j++;
        }
    }
    while(i < n)
    {
        a.insert(arr1[i]);
        i++;
    }
    while(j < m)
    {
        a.insert(arr2[j]);
        j++;
    }
    
    for(auto i : a)
        v.push_back(i);
    return v;
}

int main(){
    vector<int> arr1, arr2, unionArr;
    int input;
    cout << "Enter the elements of the first array: ";
    while(cin >> input)
        arr1.push_back(input);
    cout << "Enter the elements of the second array: ";
    cin.clear(); // to clear the error state
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // to ignore all the characters till the newline character, otherwise the input for sceond vector is skipped
    while(cin >> input)
        arr2.push_back(input);
    int a[arr1.size()], b[arr2.size()];
    copy(arr1.begin(), arr1.end(), a);
    copy(arr2.begin(), arr2.end(), b);
    unionArr = union_Arr(a, b, arr1.size(), arr2.size()) ;
    int n = unionArr.size();
    if(n%2 != 0)
        cout << "\n" << unionArr[n/2];
    else
    {
        float med  = unionArr[n/2] + unionArr[n/2 - 1];
        cout << "\n" << med / 2;
    }
    cout << "\nSorted Array: ";
    for(int i : unionArr)
        cout << i << " ";
}