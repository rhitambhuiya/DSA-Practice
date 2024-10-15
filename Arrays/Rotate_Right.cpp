#include <bits/stdc++.h>
using namespace std;

vector<int> rotate(vector<int> nums, int k) {
    int n = nums.size();
    vector<int> temp(n);
    for(int i = 0; i< n; i++)
        temp[(i+k)%n] = nums[i];
    nums = temp;
    return nums;
}

int main(){
    vector<int> v;
    int input;
    printf("Enter the array elements: ");
    while(cin>>input)
        v.push_back(input);
    v = rotate(v, 3);
    for(auto i: v)
        cout << i << " ";
}