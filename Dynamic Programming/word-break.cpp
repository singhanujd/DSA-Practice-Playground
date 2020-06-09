class Solution {
    bool flag = false;
    map<string,bool> ans;
    // bool wordBreakRecursive(string s, vector<string>& wordDict) {
    //     if(s.empty()) return true;
    //     for(auto x: wordDict){
    //         bool isPrefix = mismatch(x.begin(),x.end(),s.begin(),s.end()).first == x.end();
    //         if(isPrefix){
    //             flag = flag || wordBreak(s.substr(x.size()),wordDict);
    //         }
    //     }
    //     return flag;
    // }

    bool wordBreakRecursive(string s, vector<string>& wordDict) {
        if(s.empty()) return true;
        for(auto x: wordDict){
            bool isPrefix = mismatch(x.begin(),x.end(),s.begin(),s.end()).first == x.end();
            if(isPrefix && wordBreak(s.substr(x.size()),wordDict)){
                return true;
            }
        }
        return false;
    }

    bool wordBreakRecursive1(string s, vector<string>& wordDict){
      if(s.empty()) return true;
      for(int i = 1; i <= s.size(); ++i){
        string prefix = s.substr(0,i);
        if(find(wordDict.begin(),wordDict.end(),prefix) != wordDict.end()
          && wordBreakRecursive1(s.substr(i),wordDict)
          ){
          return true;
        }
      }
      return false;
    }

    // bool wordBreakMemoized(string s, vector<string>& wordDict) {
    //     if(s.empty()) return true;
    //     auto it = ans.find(s);
    //     if(it != ans.end()) return it->second;
    //     for(auto x: wordDict){
    //         bool isPrefix = mismatch(x.begin(),x.end(),s.begin(),s.end()).first == x.end();
    //         if(isPrefix){
    //             flag = flag || wordBreak(s.substr(x.size()),wordDict);
    //         }
    //     }
    //     return ans[s] = flag;
    // }

    bool wordBreakMemoized(string s, vector<string>& wordDict) {
        if(s.empty()) return true;
        auto it = ans.find(s);
        if(it != ans.end()) return it->second;
        for(auto x: wordDict){
            bool isPrefix = mismatch(x.begin(),x.end(),s.begin(),s.end()).first == x.end();
            if(isPrefix && wordBreak(s.substr(x.size()),wordDict)){
                return true;
            }
        }
        return ans[s] = false;
    }

    bool wordBreakMemoized1(string s, vector<string>& wordDict){
      if(s.empty()) return true;  
      auto it = ans.find(s);
      if(it != ans.end()) return it->second;
        
      for(int i = 1; i <= s.size(); ++i){
        string prefix = s.substr(0,i);
        if(find(wordDict.begin(),wordDict.end(),prefix) != wordDict.end()
          && wordBreakMemoized1(s.substr(i),wordDict)
          ){
          return true;
        }
      }
      return ans[s] = false;
    }

    bool wordBreakMemoized2(string s, vector<string>& wordDict){
      if(s.empty()) return true;  
      auto it = ans.find(s.size());
      if(it != ans.end()) return it->second;
        
      for(int i = 1; i <= s.size(); ++i){
        string prefix = s.substr(0,i);
        if(find(wordDict.begin(),wordDict.end(),prefix) != wordDict.end()
          && wordBreakMemoized2(s.substr(i),wordDict)
          ){
          return true;
        }
      }
      return ans[s.size()] = false;
    }

    bool ifItExist(vector<string>& wordDict, string s){
      return find(wordDict.begin(),wordDict.end(),s) != wordDict.end();
    }
    bool wordBreakDP(int size, vector<string>& wordDict) 
    { 
        vector<bool> dp(size + 1, false);
        dp[0] = true;
        for (int i=1; i<=size; i++) 
        { 
            if (ifItExist(wordDict,s.substr(0, i))){
              dp[i] = true;  
            }  

            if (dp[i]) 
            { 
                if (i == size) return true; 

                for (int j = i+1; j <= size; j++) 
                { 
                    if (dp[j] == false && ifItExist(wordDict,s.substr(i, j-i))) dp[j] = true; 
                    if (j == size && dp[j] == true) 
                        return true; 
                } 
            } 
        } 
        return false; 
    } 

public:
    bool wordBreak(string s, vector<string>& wordDict) {
    //  return wordBreakRecursive(s,wordDict);   
    //  return wordBreakMemoized(s,wordDict);   
     return wordBreakDP(s,wordDict);   
    }
};
