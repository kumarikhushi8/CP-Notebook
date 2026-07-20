/*
Problem: CF 160A - Twins

Topic:
- Greedy
- Sorting
- Binary Search (solution approach)

Approach:
1. Sort the coins in descending order so that the highest-value coins are considered first.
2. Use Binary Search on the number of coins to take.
3. For each candidate count, check whether the sum of the first 'count' coins
   is strictly greater than the sum of the remaining coins.
4. Return the minimum count satisfying the condition.

Time Complexity: O(n log n + n log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
bool canDistribute(int mid, int n, vector<int>&a,int sum){
    int takenAmt=0;
    for(int i=0;i<mid;i++){
        takenAmt+=a[i];
    }
    return takenAmt>sum-takenAmt;
}
int distribute(int n, vector<int>&a,int sum){
    int low=0;
    int high=n;
    int count=low;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(canDistribute(mid,n,a,sum)){
           high=mid-1;
            count=mid;
        }else{
            low=mid+1;
        }
    }
    return count;
}
int main() {
int n;
cin>>n;
vector<int>a(n);
for(int i=0;i<n;i++){
    cin>>a[i];
}
sort(a.rbegin(),a.rend());
cout<<distribute(n,a,accumulate(a.begin(), a.end(), 0));
}
