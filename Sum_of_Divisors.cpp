#include <bits/stdc++.h>
using namespace std;

int SumOfDivisors(int n)
{
    int sum = 0;
    for(int i=1; i<=n; i++)
        sum += (n/i)*i;
    return sum;
}

int main()
{
    int n, sum = 0;
    cout<<"Enter a number: ";
    cin>>n;
    sum = SumOfDivisors(n);
    cout<<sum;
}