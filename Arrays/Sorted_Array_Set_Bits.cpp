//Only adjacent elements can be swapped in order to sort the array, if their number of set bits are equal

#include <bits/stdc++.h>
using namespace std;

bool canSortArray(vector<int> &nums)
{
    int n = nums.size();
    int minOfSegment = nums[0];
    int maxOfSegment = nums[0];
    int maxOfPrevSegment = INT_MIN;
    int setbit = __builtin_popcount(nums[0]);
    for(int i = 1; i < n; i++)
    {
        if(__builtin_popcount(nums[i]) == setbit)
        {
            minOfSegment = min(nums[i], minOfSegment);
            maxOfSegment = max(nums[i], maxOfSegment);
        }
        else
        {
            if(minOfSegment < maxOfPrevSegment)
                return false;
                
            maxOfPrevSegment = maxOfSegment;

            minOfSegment = nums[i];
            maxOfSegment = nums[i];
            setbit = __builtin_popcount(nums[i]);
        }
    }
    if(minOfSegment < maxOfPrevSegment)
        return false;
    return true;
}

int main(){
    vector<int> nums;
    cout << "Enter array elements: ";
    int input;
    while(cin >> input)
        nums.push_back(input);
    if(canSortArray(nums))  cout << "Array can be sorted";
    else    cout << "Array can't be sorted";

    return 0;
}