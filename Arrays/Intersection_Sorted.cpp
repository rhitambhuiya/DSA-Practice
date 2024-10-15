#include <bits/stdc++.h>
using namespace std;

vector<int> intersect_Arr(int arr1[], int arr2[], int n, int m)
{
    vector<int> v;
    int i, j;
    i = j = 0;
    while(i < n && j < m)
    {
        if(arr1[i] == arr2[j])
        {
            v.push_back(arr1[i++]);
            j++;
        }
        else if(arr1[i] < arr2[j])
            i++;
        else
            j++;
    }
    return v;
}

int main(){
    vector<int> arr1, arr2, intersectArr;
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
    intersectArr = intersect_Arr(a, b, arr1.size(), arr2.size()) ;
    cout << "\nIntersection Array: ";
    for(int i : intersectArr)
        cout << i << " ";
}