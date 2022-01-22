#include <iostream>
using std::string;
using std::max;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int ml = longestCommonSubsequence(word1, word2);
        return word1.size() + word2.size() - 2 * ml;
    }

private:
    int dp[501][501];
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size(), l2 = text2.size();

        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else 
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[l1][l2];
    }
};