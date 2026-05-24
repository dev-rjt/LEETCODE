class Solution {
public:
    int solve(vector<int> &arr,int d,vector<int> &dp,int n,int i){
        // base case
        if(i==0){
            if(arr[i+1]>=arr[i]) return 1;
        }

        else if(i==n-1){
            if(arr[i-1]>=arr[i]) return 1;
        }

        else{
            if(arr[i+1]>=arr[i] && arr[i-1]>=arr[i]) return 1;
        }

        if(dp[i]!=0) return dp[i];

        int a = min(i+d,n-1);
        int b = max(0,i-d);

        int ans = 0;

        for(int j=i+1;j<=a;j++){
            if(arr[j]<arr[i]) ans = max(solve(arr,d,dp,n,j),ans);
            else break;   
        }

        for(int j=i-1;j>=b;j--){
            if(arr[j]<arr[i]) ans = max(solve(arr,d,dp,n,j),ans);
            else break;
        }

        dp[i] = ans+1;
        return dp[i];

    }
    
    int maxJumps(vector<int>& arr, int d) {

        if(arr.size()==1) return 1;
        
        vector<int> dp(arr.size(),0);

        int ans = 0;
        
        for(int i=0;i<arr.size();i++){  
            ans = max(ans,solve(arr,d,dp,arr.size(),i));  
        }

        return ans;
    }
};
