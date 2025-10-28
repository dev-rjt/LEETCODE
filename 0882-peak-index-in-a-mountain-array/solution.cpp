class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l =0;
        int r = n-1;
        int mid = l + (r-l)/2;

        while(l<r) {

            if(arr[mid]<arr[mid+1]) {
                l = mid+1;
            }

            else{
                r = mid ;
            }

            mid = l + (r-l)/2;
        }

        return mid;
    }
};
