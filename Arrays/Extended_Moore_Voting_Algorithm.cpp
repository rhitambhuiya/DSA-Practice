#include <bits/stdc++.h>
using namespace std;

vector<int> moore(vector<int> &nums)
{
    int n = nums.size();
    int candidate1, candidate2, cnt1 = 0, cnt2 = 0;
    candidate1 = candidate2 = INT_MIN;
    vector<int> ans;
    for(auto i : nums)
    {
        if(cnt1 == 0 && i != candidate2){
            candidate1 = i;
            cnt1 = 1;}
        else if(cnt2 == 0 && i != candidate1){
            candidate2 = i;
            cnt2 = 1;}
        else if(i == candidate1)
            cnt1++;
        else if(i == candidate2)
            cnt2++;
        else
            cnt1--, cnt2--;
        
    }
    cnt1 = 0, cnt2 = 0;
    for(auto i : nums)
    {
        if(i == candidate1)
            cnt1++;
        if(i == candidate2)
            cnt2++;
    }
    int min = n / 3;
    if(cnt1 > min)
        ans.push_back(candidate1);
    if(cnt2 > min)
        ans.push_back(candidate2);
    return ans;
}

int main(){
    printf("Enter the array elements: ");
    vector<int> input;
    int in;
    while(cin >> in)
        input.push_back(in);
    vector<int> ans = moore(input);
    cout << endl;
    if(ans.empty())  cout << "No Majority Element";
    for(int i : ans)
        cout << i << " ";
}