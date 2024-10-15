#include <bits/stdc++.h>
using namespace std;

vector<int> subarray;
vector<int> kadane(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0, final = INT_MIN, len = 0, start = 0, end, start_index = 0;
    for(int i = 0; i < n; i++)
    {
        sum += nums[i];
        if(sum > final)
        {
            final = sum;
            start = start_index;
            end = i;
        }
        if(sum < 0) 
        {
            sum = 0;
            start_index = i+1;
        }
    }
    int length = end - start + 1;
    while(start <= end)
        subarray.push_back(nums[start++]);
    return {final, length};
}

int main(){
    cout << "Enter the array elements: ";
    vector<int> input;
    int in;
    while(cin >> in)
        input.push_back(in);
    vector<int> v = kadane(input);
    cout << "Maximum Sum: " << v[0] << ", Length = " << v[1];
    cout << endl << "Subarray: ";
    for(auto i : subarray)
        cout << i << " ";
}