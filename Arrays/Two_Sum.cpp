#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum_brute(vector<int>& nums, int target) {
        vector<int> v(2);
        int n = nums.size();
        int i, j;
        i = 0;
        int sum, flag = 0;
        while(i<n)
        {
            sum = nums[i];
            if(sum == target)
                return {i};
            j = i+1;
            while(j<n)
            {
                sum += nums[j];
                if(sum == target)
                {
                    flag = 1;
                    break;
                }
                sum -= nums[j];
                j++;
            }
            if(flag == 1)
                return {i,j};
            i++;
        }
        return {-1, -1};
    }

    vector<int> twoSum_better(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> map;
        if(n == 1 && nums[0] == target)
            return {0};
        for(int i = 0; i < n; i++)
        {
            int temp = target - nums[i];
            if(map.find(temp) != map.end())
                return {i, map[temp]};
            map[nums[i]] = i;
        }
        return {-1, -1};
    }

    string twoSum_optimal(vector<int>& nums, int target)
    {
        int sum = 0;
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        if(nums.size() == 1 && nums[0] == target)
            return "YES";
        while(left<right)
        {
            sum = nums[left] + nums[right];
            if(sum > target)
                right--;
            else if(sum < target)
                left++;
            else
                return "YES";
        }
        return "NO";
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
    vector<int> v = twoSum_better(input, target);
    cout << v[0] << " " << v[1]<<"\n";
    cout << twoSum_optimal(input, target);

    return 0;
}