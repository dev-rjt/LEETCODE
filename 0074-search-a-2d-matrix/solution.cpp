class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int col = matrix[0].size();
        
        int n = rows*col;

        int l = 0;
        int r = n-1;
        int mid = l +(r-l)/2;
        


        while(l<=r){
            int i = mid/col;
            int j = mid%col;

            if(matrix[i][j]==target) {
                return true;
            }

            else if(matrix[i][j]>target){
                r = mid-1;
            }

            else {
                l = mid+1;
            }

            mid = l +(r-l)/2;
        }

        return false;


        
        
    }
};
