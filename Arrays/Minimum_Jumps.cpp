#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{
        if (n == 1)
            return 0;
        if(arr[0] == 0)
            return -1;

        //maxReach is the maximum possible index till whoch we can  jump
        int maxReach = arr[0], jump = 1, step = arr[0];
        for(int i=1; i<n; i++)
        {
            if(i == n-1) // array traversed
                return jump;
            maxReach = max(maxReach, i+arr[i]);
            step--;
            if(step == 0)
            {
                jump++;
                if(i == maxReach) // indicates that traversal is stuck if 0 is encountered
                    return -1;
                step = maxReach - i;
            }
        }
        return -1;
    }

int main()
{
    cout<<"Enter the array size: ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int jump = minJumps(arr, n);
    if(jump == -1){
        cout<<"Can't traverse array";
        exit(0);}
    cout<<endl<<"Jumps required: "<<jump;
}