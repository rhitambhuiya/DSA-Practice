#include <bits/stdc++.h>
using namespace std;
 
//brute force approach

int sub_array(int a[], int n, int k)
{
    int count, finalcount = 1, sum = 0, flag = 0;
    for(int i=0; i<n; i++)
    {
        count = 1;
        sum = a[i];
        for(int j=i+1; j<n; j++)
        {
            if((sum + a[j]) <= k){
                sum += a[j];
                count++;
                continue;}
            break;
        }
        if(sum == k){
            flag = 1;
            finalcount = max(count, finalcount);}
    }
    if(flag == 1)
        return finalcount;
    return 0;
}

//better solution using unordered map

int sub_array_better(vector<int> a, int n, int k)
{
    map<int, int> map;
    int maxlen = 0;
    int sum = 0;
    int flag = 0;
    for(int i = 0;i < n;i++)
    {
        sum += a[i];
        if(sum == k)
            maxlen = i + 1;
        int temp = sum - k;
        if(map.find(temp) != map.end())
        {
            int len = i - map[temp];
            maxlen = max(maxlen, len); 
        }
        if(map.find(sum) == map.end())
            map[sum] = i;
    }
    return maxlen;
}


int sub_array_optimal(int arr[], int n, int k)
{
    int left = 0, right = 0, sum = 0, len = 0;
    while(right <= n)
    {
        if(sum == k)
        {
            len = max(len, right - left);
        }
        else if(sum > k)
        {
            sum -= arr[left++];
            continue;
        } 
        sum += arr[right++];
    }
    return len;
}
int main(){
    cout << "Enter the target: ";
    int target;
    cin >> target;
    cout << endl << "Enter the array elements: ";
    vector<int> input;
    int in;
    while(cin >> in)
        input.push_back(in);
    cout << endl << sub_array_better(input, input.size(), target);
}