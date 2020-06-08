#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
map<pair<int,int>,int> ans;

int knapSackRecursive(int W, int wt[],int val[],int n){
  if(W == 0 || n == 0) return 0;

  return max(
    val[n-1] + knapSackRecursive(W - wt[n-1], wt, val, n-1),
    knapSackRecursive(W, wt,val,n-1)
  );
}

int knapSackMemoized(int W, int wt[], int val[], int n){
  if(W == 0 || n == 0) return 0;

  pair<int,int> state{W,n};
  auto it = ans.find(state);
  if(it != ans.end()) return it->second;

  return ans[state] = max(
    val[n-1] + knapSackMemoized(W - wt[n-1], wt,val,n-1),
    knapSackMemoized(W,wt,val,n-1)
  );
}

int knapSackDP(int W, int wt[], int val[], int n){
  vector<vector<int>> dp(n + 1, vector<int>( W + 1));

  for(int i = 1; i <= n; i++){
    for(int w = 1; w <= W; w++){
      dp[i][w] = max(dp[i-1][w] , val[i-1] + dp[i-1][w-wt[i-1]]);
    }
  }
  return dp[n][W];
}

int main() 
{
  FASTIO; 
  int val[] = { 60, 100, 120 }; 
  int wt[] = { 10, 20, 30 }; 
  int W = 50; 
  int n = sizeof(val) / sizeof(val[0]); 
  cout << knapSackRecursive(W, wt, val, n); 
  cout << knapSackMemoized(W, wt, val, n); 
  cout << knapSackDP(W, wt, val, n); 
  return 0; 
} 
  