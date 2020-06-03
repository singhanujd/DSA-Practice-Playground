class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        auto cmp = [](auto a, auto b){return a[1] - a[0] > b[1] - b[0];};
        sort(costs.begin(),costs.end(),cmp);
        int ans = 0;
        int n = costs.size();
        for(int i = 0; i < n/2; ++i){
            ans += costs[i][0];
            ans += costs[n-i-1][1];
        }
        return ans;
    }
};