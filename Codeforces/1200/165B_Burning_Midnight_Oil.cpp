/*
Problem: CF 165B - Burning Midnight Oil

Approach:
- Use Binary Search on the answer (minimum starting value 'v').
- For each candidate 'v', calculate:
      v + floor(v/k) + floor(v/k^2) + ...
- If the total lines written are at least n, try a smaller value.
- Otherwise, increase the starting value.

Time Complexity: O(log n * log_k n)
Space Complexity: O(1)
*/


#include <bits/stdc++.h>
using namespace std;
bool canWrite(int mid, int n,int k){
    //check if taking mid value can generate n lines of code by the given formula v+v/k+v/k*k
    int lines=0;
    int denominator=mid;
    while(denominator>0){
        lines+=denominator;
        denominator=denominator/k;
    }
    return lines>=n;
}
int programCode(int n, int k){
    int low=0;
    int high=n;
    int ans=low;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(canWrite(mid,n,k)){
            high=mid-1;
            ans=mid;
        }else{
            low=mid+1;
        }
    }
    return ans;
}
int main() {
int n;
cin>>n;
int k;
cin>>k;
cout<<programCode(n,k);
}
