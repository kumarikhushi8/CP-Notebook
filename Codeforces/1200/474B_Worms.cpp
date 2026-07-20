/*
Problem: CF 474B - Worms

Approach:
- Compute the prefix sum of worms in each pile.
- For each query, use Binary Search to find the first prefix sum
  that is greater than or equal to the worm label.
- The index of that prefix sum gives the pile number.

Time Complexity: O(n + m * log n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;
int display(int worm,vector<int>&arr, int n, vector<int>&sum){
    if(worm>sum[n-1])
        return n;
    int low=0,high=n-1;
    while(low<high){
        int mid=(low+high)/2;
        if(sum[mid]<worm)
            low=mid+1;
        else
            high=mid;
    }
    return low+1;
}
int main() {
int n;
cin>>n;
vector<int>arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
}
vector<int>sum(n);
sum[0]=arr[0];
for(int i=1;i<n;i++){
    sum[i]=sum[i-1]+arr[i];
}
int k;
cin>>k;
vector<int>juicy(k);
for(int i=0;i<k;i++){
    cin>>juicy[i];
    cout<<display(juicy[i],arr,n,sum)<<endl;
}
}
