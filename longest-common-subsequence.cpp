//https://leetcode.com/problems/longest-common-subsequence/

class Solution {
  map<pair<string,string>,int> answer;
  map<pair<int,int>,int> ans;
  string _text1,_text2;
public:
    int naive_approach(string text1,string text2){
      if(text1.empty() || text2.empty()) return 0;

      if(text1.back() == text2.back()){
        text1.pop_back();
        text2.pop_back();
        return 1 + naive_approach(text1,text2);
      }

      return max(
        naive_approach(string(text1.begin(),text1.end()-1),text2),
        naive_approach(text1,string(text2.begin(),text2.end()-1))
      );
    }

    int memoization_with_string(string text1,string text2){
      if(text1.empty() || text2.empty()) return 0;

      pair<string,string> state{text1,text2};
      auto it = answer.find(state);
      if(it != answer.end()){
        return it->second;
      }

      if(text1.back() == text2.back()){
        text1.pop_back();
        text2.pop_back();
        return answer[state] = 1 + memoization_with_string(text1,text2);
      }

      return answer[state] = max(
        memoization_with_string(string(text1.begin(),text1.end()-1),text2),
        memoization_with_string(text1,string(text2.begin(),text2.end()-1))
      );
    }

    int memoization_with_length(int m,int n){
      if(m == 0 || n == 0) return 0;

      pair<int,int> state{m,n};
      auto it = ans.find(state);
      if(it != ans.end()){
        return it->second;
      }

      if(_text1[m-1] == _text2[n-1]){
        return ans[state] = 1 + memoization_with_length(m-1,n-1);
      }

      return ans[state] = max(
        memoization_with_length(m-1,n),
        memoization_with_length(m,n-1)
      );
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        // _text1 = text1;
        // _text2 = text2;
        int m = text1.length(), n = text2.length();
        // return naive_approach(text1,text2);
        // return memoization_with_string(text1,text2);
        // return memoization_with_length(m,n);
        
        vector<vector<int>> arr(m+1,vector<int>(n+1));
        
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                if(text1[i] == text2[j]){
                    arr[i+1][j+1] = arr[i][j];
                }else{
                    arr[i+1][j+1] = max(arr[i+1][j],arr[i][j+1]);
                }
            }
        }
        return arr[m][n];
    }
};

  
