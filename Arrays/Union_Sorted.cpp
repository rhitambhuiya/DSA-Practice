#include <bits/stdc++.h>
using namespace std;

vector<int> union_Arr(vector <int> arr1, vector<int> arr2, int n, int m)
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

void merge_sorted(int nums1[], int nums2[], int m, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while(i >= 0 && j >= 0)
    {
        if(nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }
    while(j >= 0)
        nums1[k--] = nums2[j--];
}

int main(){
    vector<int> arr1, arr2, unionArr;
    int input;
    int m, n;
    cout << "Enter the size of the first array: ";
    cin >> m;
    cout << "Enter the elements of the first array: ";
    while(cin >> input)
        arr1.push_back(input);
    cin.clear(); // to clear the error state
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // to ignore all the characters till the newline character, otherwise the input for sceond vector is skipped
    cout << "Enter the size of the second array: ";
    cin >> n;
    cout << "Enter the elements of the second array: ";
    while(cin >> input)
        arr2.push_back(input);
    int a[m + n] = {0};
    int b[n];
    copy(arr1.begin(), arr1.end(), a);
    copy(arr2.begin(), arr2.end(), b);
    
    // unionArr = union_Arr(arr1, arr2, arr1.size(), arr2.size()) ;
    merge_sorted(a, b, m, n);
    cout << "\nSorted Array: ";
    for(int i : a)
        cout << i << " ";
    // int n = unionArr.size();
    // if(n%2 != 0)
    //     cout << "\n" << unionArr[n/2];
    // else
    // {
    //     float med  = unionArr[n/2] + unionArr[n/2 - 1];
    //     cout << "\n" << med / 2;
    // }
    // cout << "\nSorted Array: ";
    // for(int i : unionArr)
    //     cout << i << " ";

    return 0;
}