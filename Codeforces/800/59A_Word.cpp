/*
Problem: CF 59A - Word

Topic:
- Strings
- Implementation

Approach:
1. Count the number of uppercase and lowercase letters.
2. If uppercase letters are more, convert the entire string to uppercase.
3. Otherwise (including equal counts), convert the entire string to lowercase.

Time Complexity: O(n)
Space Complexity: O(1)
*/


#include <bits/stdc++.h>
using namespace std;
string convert(string &s){
    int n=s.size();
    int countU=0;
    int countL=0;
    for(auto i=0;i<n;i++){
        if(isupper(s[i])) countU++;
        else countL++;
    }
    if(countL>=countU){
        for(auto &i:s){
            i=tolower(i);
        }
    }else{
        for(auto &i:s){
            i=toupper(i);
        }
    }
    return s;
}
int main() {
string s;
cin>>s;
cout<<convert(s);
}
