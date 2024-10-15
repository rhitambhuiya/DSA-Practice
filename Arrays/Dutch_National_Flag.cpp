#include <bits/stdc++.h>
using namespace std;

void swap_num(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void dutch_national_flag(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, mid = 0;
    int high = n-1;
    while(mid <= high)
    {
        if(nums[mid] == 0)
            swap_num(nums[low++], nums[mid++]);
        else if(nums[mid] == 1)
            mid++;
        else
            swap_num(nums[mid], nums[high--]);
    }
}

int main(){
    printf("Enter the array elements: ");
    vector<int> input;
    int in;
    while(cin >> in)
        input.push_back(in);
    dutch_national_flag(input);
    for(auto i : input)
        cout << i;
}