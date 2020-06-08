//https://leetcode.com/problems/edit-distance/
class Solution {
    string word1,word2;
    map<pair<int,int>,int> ans;
    int mini(int x, int y, int z) 
    { 
        return min(min(x, y), z); 
    }
public:
    int findMinDistance(int m,int n){
        if(m == 0) return n;
        if(n == 0) return m;
        
        pair<int,int> state{m,n};
        auto it = ans.find(state);
        if(it != ans.end()) return it->second;
        
        if(word1[m-1] == word2[n-1]){
            return ans[state] = findMinDistance(m-1,n-1);
        }
        
        return ans[state] = 1 + mini(
            findMinDistance(m,n-1), //insert
            findMinDistance(m-1,n),  //remove
            findMinDistance(m-1,n-1) //replace
        );
    }
    
    int iterative_dp(int m,int n){
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0) dp[i][j] = j ;
                else if(j == 0) dp[i][j] = i;
                else if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + mini(dp[i-1][j-1],dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[m][n];
    }
    
    int minDistance(string _word1, string _word2) {
        word1 = _word1;
        word2 = _word2;
        int m = word1.length(), n = word2.length();
        // return findMinDistance(m,n);
        return iterative_dp(m,n);
    }
};