#include <bits/stdc++.h>
using namespace std;

static bool compare(vector<int> &a, vector<int> &b){
    double a1=(1.0*a[0]/a[1]);
    double b1=(1.0*b[0]/b[1]);
    return a1>b1;
}

double fractionalknapsack(vector<vector<int>>& items,int K){
    sort(items.begin(),items.end(),compare); // O(nlogn)
    int maxVal=0.0;
    for(auto &item:items) {
        int val=item[0];
        int wt=item[1];

        if(wt<=K) {
            maxVal+=val;
            K-=wt;
        } else {
            maxVal+=((double)val/wt)*K;
            break;
        }
    }
    return maxVal;
}

int main() {
    vector<vector<int>> items={
        {60,10},{100,20},{120,30},{80,40},{150,15}
    }; // val,wt

    int K=60;
    cout << fractionalknapsack(items,K) << endl;
    return 0;
}