#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    for(int i = 1; i< n; i++)
        if(nums[i-1] > nums[i])
            count++;
    if(nums[n-1] > nums[0])
        count++; 
    return count <= 1;
}

int main(){
    vector<int> v;
    int input;
    printf("Enter the array elements: ");
    while(cin>>input)
        v.push_back(input);
    if(check(v))
        cout<<"Array is sorted after rotating";
    else
        cout<<"Array can't be sorted";
    return 0;
}