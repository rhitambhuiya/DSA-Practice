#include <bits/stdc++.h>
using namespace std;

vector<long long> lcmAndGcd(long long A , long long B) {
    // code here
    long long gcd, lcm, a=A, b=B;
    while(a>0 && b>0)
    {
        if(a>b)
            a-=b;
        else
            b-=a;
    }
    if(a == 0)
        gcd=b;
    else
        gcd=a;
    lcm=A*B/gcd;
    /*vector<long long> v;
    v.push_back(lcm);
    v.push_back(gcd);*/
    return {lcm, gcd};
}

//recursion concept, can't find lcm inside function, have to do inside main fucntion

long HCF(long A, long B)
{
    if(A == 0 || B == 0)
        return max(A, B);
    if(A>B)
        return HCF(A-B, B);
    return HCF(A, B-A);
}

/*long LCM(long A, long B)
{
    long MAX = max(A, B);
    long MIN = min(A, B);
    long i = MAX;
    while(true)
    {
        if(i%MIN == 0)
            return i;
        i+=MAX;
    }
}*/

int main(){
    int a, b;
    cout<<"Enter 2 numbers: ";
    cin>>a>>b;
    //vector<long long> v = lcmAndGcd(a, b);
    //cout<<v[0]<<" "<<v[1];
    cout<<a*b/HCF(a,b)<<" "<<HCF(a, b);
    return 0;
}