#include <bits/stdc++.h>
using namespace std;


bool isPalindrome(string s)
{
    /*int len = s.length();
    string str, copy;
    for(char c : s)
    {
        if(c>=65 && c<=90){
            str=(char)(c+32)+str;
            copy+=(char)(c+32);}
        else if(c>=97 && c<=122 || (c>=48 && c<=57)){
            str=c+str;
            copy+=c;}
    }
    if (str == copy)
        return true;
    return false;*/
    int start = 0;
    int end = s.length() - 1;
    while(start<=end)
    {
        if(isalnum(s[start]) == false)
        {
            start++;
            continue;
        }
        if(isalnum(s[end]) == false)
        {
            end--;
            continue;
        }
        if(tolower(s[start])!=tolower(s[end]))
            return false;
        start++;
        end--;
    }
    return true;
}

int main(){
    cout<<"Enter a string: ";
    string s;
    getline(cin, s);
    if(isPalindrome(s))
        cout<<"Palindrome String";
    else
        cout<<"Not a Palindrome String";
}