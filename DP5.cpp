#include <bits/stdc++.h>
using namespace std;

// Recursive method (brute force) O(2^n)
double unboundedKnapsack_Rec(vector<vector<int>> &items,int W,int n) {
    if(n==0 || W==0) return 0;
    int val=items[n-1][0];
    int wt=items[n-1][1];

    if(wt<=W) {
       int include=val+unboundedKnapsack_Rec(items,W-wt,n);
       int exclude=unboundedKnapsack_Rec(items,W,n-1);
       return max(include,exclude);
    } else {
       return unboundedKnapsack_Rec(items,W,n-1);
    }
}

// memoization O(n*w) Space [O(n*w)+O(n) Recursion stack]
double unboundedKnapsack_Memo(vector<vector<int>> &items,int W,int n,vector<vector<int>>& dp) {
    if(n==0 || W==0) return 0;
    if(dp[n][W]!=-1) return dp[n][W];
    int val=items[n-1][0];
    int wt=items[n-1][1];

    if(wt<=W) {
       int include=val+unboundedKnapsack_Memo(items,W-wt,n,dp);
       int exclude=unboundedKnapsack_Memo(items,W,n-1,dp);
       return dp[n][W]=max(include,exclude);
    } else {
       return dp[n][W]=unboundedKnapsack_Memo(items,W,n-1,dp);
    }
}

// Tabulation O(n*w) Space O(n*w)  
double unboundedKnapsack_Tab(vector<vector<int>> &items,int W,int n) {
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));
    for(int i=1;i<=n;i++) { // i items
        for(int j=1;j<=W;j++) { // j capacity knapsack
            int val=items[i-1][0];
            int wt=items[i-1][1];
            if(wt<=j) {
                int include=val+dp[i][j-wt];
                int exclude=dp[i-1][j];
                dp[i][j]=max(include,exclude);
            } else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main() {
    vector<vector<int>> items={
        {10,2},{45,5},{70,10},{75,12}
    };
    int W=30;
    vector<vector<int>> dp(items.size()+1,vector<int>(W+1,-1));
    cout << unboundedKnapsack_Tab(items,W,items.size()) << endl;
    return 0;
}
