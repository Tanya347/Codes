/************************************************************************************** TABULATION **********************************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countUniqueTriples(const vector<int>& A) {
    int N = A.size();
    int k = 3; // Length of the subsequences
    vector<vector<int>> dp(N + 1, vector<int>(k + 1, 0));
    unordered_map<int, int> last_seen;

    // Base case: dp[m][0] = 1 for all m (1 subsequence of length 0, the empty subsequence)
    for (int m = 0; m <= N; ++m) {
        dp[m][0] = 1;
    }

    for (int m = 1; m <= N; ++m) {
        for (int length = 1; length <= k; ++length) {
            // Case 1: A[m] not chosen
            dp[m][length] = dp[m - 1][length];

            // Case 2: A[m] chosen
            dp[m][length] += dp[m - 1][length - 1];

            // Subtract duplicates if A[m] has been seen before
            if (last_seen.find(A[m - 1]) != last_seen.end()) {
                int prev_index = last_seen[A[m - 1]];
                dp[m][length] -= dp[prev_index][length - 1];
            }
        }

        // Update the last seen index for A[m]
        last_seen[A[m - 1]] = m - 1;
    }

    // The result is stored in dp[N][k]
    return dp[N][k];
}

int main() {
    vector<int> A = {1, 1, 1, 1, 2};
    cout << "Number of unique triples: " << countUniqueTriples(A) << endl;
    return 0;
}

/************************************************************************************** MEMOIZATION **********************************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Memoization table: dp[m][k] stores the result for T(m, k)
unordered_map<int, unordered_map<int, int>> dp;
unordered_map<int, int> last_seen; // Tracks the last seen index of each element

int countSubsequences(int m, int k, const vector<int>& A) {
    // Base cases
    if (k == 0) return 1; // One subsequence of length 0 (empty)
    if (m == 0) return 0; // No subsequences if no elements are available
    
    // Check memoization
    if (dp[m].find(k) != dp[m].end()) return dp[m][k];

    // Recursive relation
    int result = countSubsequences(m - 1, k, A); // Case: A[m-1] not chosen
    result += countSubsequences(m - 1, k - 1, A); // Case: A[m-1] chosen

    // Remove duplicates if A[m-1] was seen before
    if (last_seen.find(A[m - 1]) != last_seen.end()) {
        int prev_index = last_seen[A[m - 1]];
        result -= countSubsequences(prev_index, k - 1, A);
    }

    // Store the result in the memoization table
    dp[m][k] = result;

    // Update last seen for current element
    last_seen[A[m - 1]] = m - 1;

    return result;
}

int countUniqueTriples(const vector<int>& A) {
    dp.clear();
    last_seen.clear();
    int N = A.size();
    int k = 3; // Length of the subsequences
    return countSubsequences(N, k, A);
}

int main() {
    vector<int> A = {1, 1, 1, 1, 2};
    cout << "Number of unique triples: " << countUniqueTriples(A) << endl;
    return 0;
}

/************************************************************************************** OPTIMIZED APPROACH **********************************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countDistinctSubsequences(const vector<int>& A, int k) {
    int n = A.size();
    vector<int> sumDistinct(k + 1, 0);
    unordered_map<int, vector<int>> hash;

    // Base case: 1 way to form a subsequence of length 0 (empty subsequence)
    sumDistinct[0] = 1;

    for (int i = 0; i < n; ++i) {
        int element = A[i];

        // If the element is new, initialize its contribution
        if (hash.find(element) == hash.end()) {
            hash[element] = vector<int>(k + 1, 0);
        }

        // Store the previous contributions of this element
        vector<int> prev = hash[element];

        // Update contributions for this element
        for (int j = 1; j <= k; ++j) {
            hash[element][j] = sumDistinct[j - 1];
        }

        // Update sumDistinct to account for new contributions and remove old ones
        for (int j = 2; j <= k; ++j) {
            sumDistinct[j] = sumDistinct[j] - prev[j] + hash[element][j];
        }

        // Increment the count of subsequences of length 1
        sumDistinct[1] += 1;

        // Debugging output (optional)
        cout << "Element: " << element << " -> Contributions: ";
        for (int j = 1; j <= k; ++j) {
            cout << hash[element][j] << " ";
        }
        cout << " | SumDistinct: ";
        for (int j = 1; j <= k; ++j) {
            cout << sumDistinct[j] << " ";
        }
        cout << endl;
    }

    return sumDistinct[k];
}

int main() {
    vector<int> A = {1, 2, 1, 1, 1, 3, 2, 1};
    int k = 3;

    cout << "Number of distinct subsequences of length " << k << ": ";
    cout << countDistinctSubsequences(A, k) << endl;

    return 0;
}
