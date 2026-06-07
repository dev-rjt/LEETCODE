class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;

        for(int i=0;i<piles.size();i++){
            high = max(high,piles[i]);
        }

        while(low<high){
            int mid = (low+high)/2;

            int time = 0;

            for(int i=0;i<piles.size();i++){
                if(piles[i]%mid){
                    time+=piles[i]/mid+1;
                }
                else{
                    time+=piles[i]/mid;
                }
            }

            if(time>h){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }

        return high;
    }
};
