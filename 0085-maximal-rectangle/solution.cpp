class Solution {
public:

    vector <int> NextSmallestElement(vector<int> arr,int col){
        stack <int> s;
        s.push(-1);
        vector <int> ans(col);

        for(int i=col-1;i>=0;i--){
            while(s.top()!=-1 && arr[s.top()]>=arr[i]){
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

     vector <int> PrevSmallestElement(vector<int> arr,int col){
        stack <int> s;
        s.push(-1);
        vector <int> ans(col);

        for(int i=0;i<col;i++){
            while(s.top()!=-1 && arr[s.top()]>=arr[i]){
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int MaxAreaInHistogram(vector<int> arr,int col){
        vector <int> prev(col);
        vector <int> next(col);

        prev = PrevSmallestElement(arr,col);
        next = NextSmallestElement(arr,col);

        int area = INT_MIN;

        for(int i=0;i<col;i++){
            int l = arr[i];
            if(next[i]==-1) next[i] = col;
            int b = next[i]-prev[i]-1;
            area = max(area,l*b);
        }

        return area;
    }

    

    int maximalRectangle(vector<vector<char>>& matrix) {
      int row = matrix.size();
      int col = matrix[0].size();

      vector<vector<int>> mat(row,vector<int>(col,0));

      for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++){
            if(matrix[i][j]=='1') mat[i][j] = 1;
        }
      }

      int area = MaxAreaInHistogram(mat[0],col);

      for(int i=1;i<row;i++){
        for(int j=0;j<col;j++){
            if(mat[i][j]){
                mat[i][j] = mat[i-1][j] + 1;
            }
        }
        area = max(area,MaxAreaInHistogram(mat[i],col));
      }

        return area;
    }
};
