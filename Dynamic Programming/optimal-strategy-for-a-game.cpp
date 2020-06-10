// https://www.geeksforgeeks.org/optimal-strategy-for-a-game-dp-31/

#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> ans;

int optimalStrategyOfGameRecursive(int val[],int i, int j){
  if( i == j ) return val[i];
  if( j == i + 1) return max(val[i],val[j]);
  
  return max(
      val[i] + min(optimalStrategyOfGameRecursive(val,i+1,j-1),optimalStrategyOfGameRecursive(val,i+2,j)),
      val[j] + min(optimalStrategyOfGameRecursive(val,i+1,j-1),optimalStrategyOfGameRecursive(val,i,j-2))
  );
}


    
int optimalStrategyOfGameMemoized(int val[],int i, int j){
  ans.clear();
  pair<int,int> state{i,j};
  auto it = ans.find(state);
  if(it != ans.end()) return it->second;
  
  if( i == j ) return ans[state] = val[i];
  if( j == i + 1) return ans[state] = max(val[i],val[j]);
  
  
  return ans[state] = max(
      val[i] + min(optimalStrategyOfGameMemoized(val,i+1,j-1),optimalStrategyOfGameMemoized(val,+2,j)),
      val[j]+ min(optimalStrategyOfGameMemoized(val,i+1,j-1),optimalStrategyOfGameMemoized(val,i,j-2))
  );
}

int optimalStrategyOfGameDP(int val[],int n){
  vector<vector<int>> dp(n+1, vector<int>(n+1));
  
  for(int gap = 0; gap < n; gap++){
    for(int i = 0, j = gap; j < n; ++i,++j){
      int x = (i+2 <= j) ? dp[i+2][j] : 0;
      int y = (i+1 <= j-1) ? dp[i+1][j-1] : 0;
      int z = (i <= j-2) ? dp[i][j-2] : 0;

      dp[i][j] = max(
        val[i] + min(x,y),
        val[j] + min(y,z)
      );
    }
  }
  return dp[0][n-1];
}


int main(){
  int arr1[] = { 8, 15, 3, 7 }; 
  int n = sizeof(arr1) / sizeof(arr1[0]); 
  printf("%d\n",optimalStrategyOfGameRecursive(arr1, 0, n - 1)); 

  int arr2[] = { 2, 2, 2, 2 }; 
  n = sizeof(arr2) / sizeof(arr2[0]); 
  printf("%d\n",optimalStrategyOfGameRecursive(arr2, 0, n - 1)); 

  int arr3[] = { 20, 30, 2, 2, 2, 10 }; 
  n = sizeof(arr3) / sizeof(arr3[0]); 
  printf("%d\n",optimalStrategyOfGameRecursive(arr3, 0, n - 1)); 

  return 0; 
}