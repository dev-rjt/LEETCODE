class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long size = mass;
        sort(asteroids.begin(),asteroids.end());

        for(int i=0;i<asteroids.size();i++){
            if(size<asteroids[i]) return false;
            else size+= asteroids[i];
        }

        return true;
    }
};
