#include <bits/stdc++.h>
using namespace std;

void right_rotate(vector<int> &v, int start, int end)
{
    int temp = v[end];
    for(int i = end; i > start; i--)
        v[i] = v[i-1];
    v[start] = temp;
}

void alternate(vector<int> &nums)
{
    int n = nums.size();
    int pos = 0, neg = 1, j = 0;
    while(pos < n && neg < n)
    {
        //if the positive element is in correct position, we increment the positive pointer to point to the next positive position
        if(nums[pos] >= 0)
            pos += 2;

        //if the negative element is in correct position, we increment the negative pointer to point to the next negative position
        else if(nums[neg] < 0)
            neg += 2;

        //this condition implies both the negative and positive pointer are pointing to wrong elements
        //with the j pointer we traverse to the nearest negative element
        //we don't directly swap the elements since we need to preserve the order
        //we rotate the required portion one position to the right to preserve the order and bring alternate positive and negative numbers
        else
        {
            j = min(neg, pos); // so that j isn't before negative or positive pointer

            //if we encounter negative pointer pointing to wrong element before
            if(neg < pos){
            while(j < n && nums[j] > 0)
                j++;
            right_rotate(nums, neg, j);}

            //if we encounter positive pointer pointing to wrong element before
            else{
                while(j < n && nums[j] < 0)
                    j++;
                right_rotate(nums, pos, j);
            }
        }
    }
}

int main()
{
    cout << endl << "Enter the elements: ";
    vector<int> v;
    int input;
    while(cin >> input)
        v.push_back(input);
    alternate(v);
    cout << endl;
    for(auto &it : v)
        cout << it << " ";
    return 0;
}