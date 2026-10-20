#include <bits/stdc++.h>
using namespace std;

int minCost(vector<int> &height) { // t.c=o(n) s.c=o(1)
    int n=height.size();
    if(n==1) return 0;

   int prev1=0;
   int prev2=abs(height[1]-height[0]);
   int ans=prev2;

    for (int i = 2; i < n; i++) {
        int jump1 = prev2+abs(height[i]-height[i-1]);
        int jump2 = prev1+abs(height[i]-height[i-2]);
        ans = min(jump1,jump2);
        prev1=prev2;
        prev2=ans;
    }
    return ans;
}
int main() {
    vector<int> height={30,20,50,10,40}; // 30
    // vetcor<int> height={20,30,40,20}; // 20

    cout << minCost(height) << endl;
    return 0;
}