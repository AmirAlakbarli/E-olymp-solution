#include <bits/stdc++.h>

using namespace std;

int calculateMinScore(const vector<int> &cards)
{
    int n = cards.size();

    // Create a 2D table to store the minimum scores
    vector<vector<int>> minScores(n, vector<int>(n, 0));

    // Fill the table diagonally from bottom-left to top-right
    for (int gap = 2; gap < n; gap++)
    {
        for (int left = 0; left < n - gap; left++)
        {
            int right = left + gap;
            minScores[left][right] = INT_MAX;

            // Try removing each card between left and right
            for (int k = left + 1; k < right; k++)
            {
                int score = cards[left] * cards[k] * cards[right];
                minScores[left][right] = min(minScores[left][right], score + minScores[left][k] + minScores[k][right]);
            }
        }
    }

    return minScores[0][n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    scanf("%d", &n);
    vector<int> cards(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &cards[i]);

    int minScore = calculateMinScore(cards);

    printf("%d\n", minScore);

    return 0;
}