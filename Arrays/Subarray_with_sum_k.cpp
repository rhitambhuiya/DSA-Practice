#include <bits/stdc++.h>
using namespace std;

int count_subarrays_brute(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += nums[j];
            if(sum == k) count++;
        }
    }
    return count;
}

int count_subarrays_optimal(vector<int> &nums, int k)
{
    map<int, int> map;
    int n = nums.size();
    int count = 0;
    int sum = 0;
    map[0] = 1;
    for(int i = 0; i < n; i++){
        sum += nums[i];
        int temp = sum - k;
        if(map.find(temp) != map.end())
            count += map[temp];
        map[sum]++;
    }
    return count;
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
    cout << endl << count_subarrays_optimal(input, target);
}