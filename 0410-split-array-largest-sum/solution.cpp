class Solution {
public:
    // just did book allocation problem

    bool solve(vector<int> &arr,int k,int n,int pages){
        int students = 0;
        int cnt = 0;
        int pages_read = 0;
        
        while(students<k && cnt<n){
            pages_read += arr[cnt];
            if(pages_read>pages){
                students++;
                pages_read = 0;
            }
            // else if(pages_read==pages){
            //     students++;
            //     cnt++;
            //     pages_read = 0;
            // }
            else{
                cnt++;
            }
        }
        
        if(cnt==n) return true;
        return false;
    }

    int splitArray(vector<int>& arr, int k) {
        if(k>arr.size()) return -1;
        int low = 0;
        int high = 0;
        
        for(int i=0;i<arr.size();i++){
            high+=arr[i];
        }
        
        int ans = 0;
        
        while(low<=high){
            int mid = (low+high)/2;
            
            bool isPossible = solve(arr,k,arr.size(),mid);
            
            // cout << mid << " " << isPossible << endl;
            
            if(isPossible){
                high = mid-1;
                ans = mid;
            }
            else low = mid+1;
        }
        
        return ans;
    }
};
