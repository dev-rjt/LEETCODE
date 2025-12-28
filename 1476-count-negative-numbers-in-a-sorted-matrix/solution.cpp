class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int i =0,j=n-1;

        int ans = 0;

        while(1){

            if(i>m-1 || j<0) break;

            if(grid[i][j]<0){
                ans+=m-i;
                j--;
            }

            else{
                i++;
            }
        }
        return ans;
    }
};
