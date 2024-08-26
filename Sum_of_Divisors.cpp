#include <bits/stdc++.h>
using namespace std;

int SumOfDivisors(int n)
{
    int sum = 0;
    for(int i=1; i<=n; i++)
        sum += (n/i)*i; // counting the contribution of each factor till 'n' and then finding the contributed value
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