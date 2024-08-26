#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
    int a=0, b=1, c=b;
    int i=2;
    while(i<=n)
    {
        c=a+b;
        a=b;
        b=c;
        i++;
    }
    return c;
}

int main(){
    cout<<"Enter a number: ";
    int n;
    cin>>n;
    cout<<"F("<<n<<") = "<<fib(n);
}