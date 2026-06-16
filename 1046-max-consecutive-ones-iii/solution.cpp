class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        queue<int> q;
    
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                q.push(1);
                ans = max(ans,(int)q.size());
            }
            else{
                if(k==0){
                    while(q.size()!=0 && k==0){
                        if(q.front()==0) k++;
                        q.pop();
                    }
                    if(k!=0){
                        q.push(0);
                        k--;
                        ans = max(ans,(int)q.size());
                    }
                }
                else{
                    q.push(0);
                    k--;
                    ans = max(ans,(int)q.size());
                }
            }
        }
        return ans;
    }
};
