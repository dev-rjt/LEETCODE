class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int high, int &ans) {

        // COUNT REVERSE PAIRS
        int j = mid + 1;

        for(int i = low; i <= mid; i++) {

            while(j <= high && (long long)(arr[i]) > 2LL*arr[j]) {
                j++;
            }

            ans += (j - (mid + 1));
        }

        // MERGE STEP
        vector<int> temp;

        int left = low;
        int right = mid + 1;

        while(left <= mid && right <= high) {

            if(arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            }
            else {
                temp.push_back(arr[right++]);
            }
        }

        while(left <= mid) {
            temp.push_back(arr[left++]);
        }

        while(right <= high) {
            temp.push_back(arr[right++]);
        }

        for(int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    void mergesort(vector<int>& arr, int low, int high, int &ans) {

        if(low >= high) return;

        int mid = (low + high) / 2;

        mergesort(arr, low, mid, ans);
        mergesort(arr, mid + 1, high, ans);

        merge(arr, low, mid, high, ans);
    }

    int reversePairs(vector<int>& nums) {
        int ans = 0;

        mergesort(nums, 0, nums.size() - 1, ans);

        return ans;
    }
};
