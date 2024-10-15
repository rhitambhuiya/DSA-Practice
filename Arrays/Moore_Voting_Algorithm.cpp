#include <bits/stdc++.h>
using namespace std;

int moore(vector<int> &nums)
{
    int n = nums.size();
    int candidate, cnt = 0;
    for(auto i : nums)
    {
        if(cnt == 0)
        {
            candidate = i;
            cnt = 1;
        }
        else if(candidate == i)
            cnt++;
        else 
            cnt --;
    }
    cnt = 0;
    for(auto i : nums)
        if(i == candidate) cnt++;
    if(cnt > n/2) return candidate;
    return -1;
}

int main(){
    printf("Enter the array elements: ");
    vector<int> input;
    int in;
    while(cin >> in)
        input.push_back(in);
    cout << moore(input);
}