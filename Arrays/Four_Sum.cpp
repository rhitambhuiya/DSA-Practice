#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> nums, int target)
{
    int size = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> final;
    vector<int> temp;
    int i, j, m, n;
    for(i = 0; i < size; i++)
    {
        if(i != 0 && nums[i - 1] == nums[i]) continue;
        for(j = i + 1; j < size; j++)
        {
            if(j != 1 && nums[j - 1] == nums[j]) continue;
            m = j + 1;
            n = size - 1;
            while(m < n)
            {
                int sum = nums[i] + nums[j] + nums[m] + nums[n];
                if(sum < target)
                    m++;
                else if(sum > target)
                    n--;
                else
                {
                    temp = {nums[i], nums[j], nums[m], nums[n]};
                    final.push_back(temp);
                    m++, n--;
                    while(m < n && nums[m - 1] == nums[m]) m++;
                    while(m < n && nums[n + 1] == nums[n]) n--;
                }
            }
        }
    }
    return final;
}

int main(){
    printf("\nEnter the target: ");
    int target;
    cin >> target;
    printf("Enter the array elements: ");
    vector<int> input;
    int in;
    while(cin >> in)
        input.push_back(in);
    vector<vector<int>> v = fourSum(input, target);
    if(v.empty())
        cout << endl << "No suitable subarray";
    for(auto i : v)
    {
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}