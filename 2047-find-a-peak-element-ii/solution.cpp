class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = m-1;

        while(low<=high){
            int mid = (low+high)/2;
            int maxi = INT_MIN;

            int index = -1;

            for(int i=0;i<n;i++){
                if(mat[i][mid]>maxi){
                    maxi = mat[i][mid];
                    index = i;
                }
            }

            if(mid+1<m && mat[index][mid]<mat[index][mid+1]){
                low = mid+1; 
            }
            else if(mid-1>=0 && mat[index][mid]<mat[index][mid-1]){
                high = mid-1;
            }
            else{
                return {index,mid};
            }
        }
        return {0,0};
    }
};
