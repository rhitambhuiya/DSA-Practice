#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum_better(vector<int>& nums, int  target)
{
    vector<vector<int>> final;
    int n = nums.size();
    set<vector<int>> st;
    vector<int> temp;
    map<int, int> hashSet; int count = 0;
    for(int i = 0; i < n; i++)
    {
        hashSet.clear();
        for(int j = i + 1; j < n; j++)
        {
            int third = target - (nums[i] + nums[j]);
            if(hashSet.find(third) != hashSet.end())
            {
                temp.clear();
                temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashSet[nums[j]] = count;
        }
    }
    final.assign(st.begin(), st.end());
    return final;
}

vector<vector<int>> threeSum_optimal(vector<int>& nums, int  target)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> final;
    int n = nums.size();
    int sum = 0;
    for(int i = 0; i < n - 2; i++)
    {
        if(i != 0 && nums[i] == nums[i-1])
            continue;
        int j = i + 1;
        int k = n - 1;
        while(j < k)
        {
            sum = nums[i] + nums[j] + nums[k];
            if(sum < target) j++;
            else if(sum > target) k--;
            else
            {
                final.push_back({nums[i], nums[j], nums[k]});
                j++, k--;
                while(j < k && nums[j - 1] == nums[j]) j++;
                while(j < k && nums[k + 1] == nums[k]) k--;
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
    vector<vector<int>> v = threeSum_optimal(input, target);
    for(auto i : v)
    {
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}