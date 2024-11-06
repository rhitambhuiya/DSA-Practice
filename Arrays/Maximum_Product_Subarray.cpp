#include <bits/stdc++.h>
using namespace std;

int max_prod_brute(vector<int> &nums)
{
    int n = nums.size();
    int maxprod = INT_MIN, prod = 1;
    for(int i = 0; i < n; i++)
    {
        prod = 1;
        for(int j = i; j < n; j++)
        {
            prod *= nums[j];
            maxprod = max(prod, maxprod);
        }
    }
    return maxprod;
}

int main(){
    vector<int> nums;
    int in;
    cout << "Enter the array elements: ";
    while(cin >> in)
        nums.push_back(in);
    cout << "Maximum Product: " << max_prod_brute(nums);
}