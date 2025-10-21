class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) {
            return;
        }

        if(m==0) {
            for(int i=0;i<n;i++) {
                nums1[i] = nums2[i];
            }
        }

        else {

            int arr[m+n];
            int i = 0;
            int j =0;
            int k =0;

            while(i<m && j<n) {
                if(nums1[i]>=nums2[j]) {
                    arr[k++] = nums2[j++];
                }

                else {
                    arr[k++]=nums1[i++];
                }
            }

            while(i<m) {
                arr[k++] = nums1[i++];
            }

            while(j<n) {
                arr[k++] = nums2[j++];
            }

            for(int a=0;a<m+n;a++) {
                nums1[a]=arr[a];
            }
        }
    }
};
