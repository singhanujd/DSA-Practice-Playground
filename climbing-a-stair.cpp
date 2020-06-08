#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
map<int,int> ans;

int climbStairRecursive(int n){
  if(n < 3) return n;
  return climbStairRecursive(n-1) + climbStairRecursive(n-2);
}

int climbStairMemoized(int n){
  if(n < 3) return n;

  auto it = ans.find(n);
  if(it != ans.end()) return it->second;

  return ans[n] = climbStairMemoized(n-1) + climbStairMemoized(n-2);
}

int climbStairDP(int n){
  if(n < 3) return n;
  int dp[n+1];
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  for(int i = 3; i <= n; i++){
    dp[i] = dp[i-1] + dp[i-2];
  }
  return dp[n];
}

int main(){
  FASTIO;
  cout<<climbStairRecursive(10)<<endl;
  cout<<climbStairMemoized(10)<<endl;
  cout<<climbStairDP(10)<<endl;
}