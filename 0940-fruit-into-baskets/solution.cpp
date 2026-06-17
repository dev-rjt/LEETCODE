class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0;
        int n = fruits.size();

        queue<int> q;
        pair<int,int> b1 = {-1,0};
        pair<int,int> b2 = {-1,0};
        int ans = 0;

        for(int i=0;i<n;i++){
            int type = fruits[i];

            if(b1.first==type) b1.second++;

            else if(b2.first==type) b2.second++;

            else if(b1.first==-1){
                b1.first = type;
                b1.second = 1;
            }
            else if(b2.first==-1){
                b2.first = type;
                b2.second = 1;
            }
            else{
                ans = max(ans,b1.second+b2.second);

                while(b1.second!=0 && b2.second!=0){
                    int t = q.front();
                    q.pop();

                    if(b1.first==t) b1.second--;
                    else b2.second--;
                }

                if(b1.second==0){
                    b1.first = type;
                    b1.second = 1;
                }
                else{
                    b2.first = type;
                    b2.second = 1;
                }
            }
            q.push(type);

            // cout << i << " " << b1.first << " " << b1.second << " " <<b2.first << " " << b2.second << endl; 
        }
        
        ans = max(ans,b1.second+b2.second);
        return ans;
    }
};
