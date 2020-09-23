var graph,row,column,dp;

var helper = (i,j,prev) => {
    if(i < 0 || j < 0 || i >= row || j >= column ) return 0;
    if( graph[i][j] <= prev ) return 0;
    if( graph[i][j] == -1 ) return 0;
    
    if(dp[i][j]) return dp[i][j];

    let c = graph[i][j];
    graph[i][j] = -1;
    dp[i][j] = 1 + Math.max(helper(i,j+1,c),helper(i,j-1,c),helper(i+1,j,c),helper(i-1,j,c));
    graph[i][j] = c;

    return dp[i][j];
}

var longestIncreasingPath = function(matrix) {
    graph = matrix;
    row = matrix.length;
    column = matrix[0].length;

    if(row == 0) return 0; // check for empty matrix
    
    dp = Array.from({length: row}, (val,i) => new Array(column));

    let maxValue = 0;
    for(let i = 0; i < row; i++){
        for(let j = 0; j < column; j++){
            maxValue = Math.max(maxValue,helper(i,j,-1));
        }
    }
    
    return maxValue;
};