class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        // Total sum of all cards
        int total = 0;

        for (int x : cardPoints) {
            total += x;
        }

        // We leave exactly n-k cards in the middle.
        int windowSize = n - k;

        // If k == n, we can take all cards.
        if (windowSize == 0) {
            return total;
        }

        // Sum of first n-k cards
        int windowSum = 0;

        for (int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }

        // Minimum sum of a window of size n-k
        int minWindow = windowSum;

        int l = 0;

        for (int r = windowSize; r < n; r++) {

            windowSum -= cardPoints[l];
            windowSum += cardPoints[r];

            minWindow = min(minWindow, windowSum);

            l++;
        }

        // We want to maximize:
        //
        // cards taken = total - cards left
        //
        // Therefore:
        //
        // answer = total - minimum middle window

        return total - minWindow;
    }
};