class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        int leftSum = 0;
        int rightSum = 0;

        for(int i = 0; i < k; i++)
            leftSum += cardPoints[i];

        int maxScore = leftSum;

        int rightIndex = n - 1;

        for(int i = k - 1; i >= 0; i--) {

            leftSum -= cardPoints[i];

            rightSum += cardPoints[rightIndex--];

            maxScore = max(maxScore, leftSum + rightSum);
        }

        return maxScore;
    }
};
