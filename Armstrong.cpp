#include <bits/stdc++.h>
using namespace std;


bool checkArmstrong(int n){
    int digits=0, temp = n, sum=0;
    while(temp>0)
    {
        digits++;
        temp/=10;
    }
    temp = n;
    while(temp>0)
    {
        sum+=pow(temp%10, digits);
        temp/=10;
    }
    if(sum == n)
        return true;
    return false;
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    if(checkArmstrong(n))
        cout<<"Armstrong Number";
    else
        cout<<"Not an Armstrong Number";
}