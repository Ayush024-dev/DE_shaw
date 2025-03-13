// 📝 **Problem link:** [Matrix Chain Multiplication](https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=matrix-chain-multiplication)

/*
📖 **Problem Statement:**
Given an array `arr[]` which represents the dimensions of a sequence of matrices where the `i`-th matrix has the dimensions `(arr[i-1] x arr[i])` for `i >= 1`, find the most efficient way to multiply these matrices together.

The efficient way is the one that involves the **least number of multiplications**.
*/

// 🧠 **Approach:**
// Let's start with the approach! We are given an array where each element represents the dimensions of a matrix. How? See this example: `[10, 20, 30, 40, 50]`
// As per the problem statement: the `i`-th matrix has the dimensions `arr[i-1] * arr[i]`. So the first matrix dimension would be `arr[0] * arr[1]`, the second matrix would be `arr[1] * arr[2]`, and so on.
// From these five numbers, we can form **4 matrices**. Let’s name them `A`, `B`, `C`, and `D`.

// 🧱 **Base Concept:**
// What are the number of operations in multiplying two matrices?
// Suppose matrix `A` has dimensions `10x20` and matrix `B` has dimensions `20x30`.
// The number of operations required to multiply them will be:
// `(rows of A) * (common value of columns of A and rows of B) * (columns of B)`
// Using the example:
// `A: 10x20`, `B: 20x30` ➡️ `Resulting Matrix: 10x30`
// Number of operations: `10 * 20 * 30 = 6000` ops

// ✅ **Objective:**
// We need to find the **minimum number of operations** to multiply matrices `A`, `B`, `C`, and `D`.
// We partition the matrix chain and check the operations required every time.
// Possible partitions:
// - `(A) * (BCD)`
// - `(AB) * (CD)`
// - `(ABC) * (D)`
// Every partition results in two matrices being multiplied, and we already know the operations needed.
// Each child matrix also has its own partitions, so the operations add up.
// The **minimum of all those results** will be our answer.

// 📝 **Rules for DP Partition:**
// 1️⃣ **Define the block:** Our initial block would be from `1` to `n-1` because the dimension of the first matrix is `arr[1] * arr[0]`.
// 2️⃣ **Base case:** When `i == j`, we have only one matrix, and the number of operations required is `0`.
// 3️⃣ **Partitioning:** Loop from `i` to `j` (excluding `j`) and calculate results for each partition.
//    Each partition splits into two subproblems: `i -> k` and `k+1 -> j`.
// 4️⃣ **Return the minimum answer.**

// 💻 **Code:**
class Solution {
public:
    int mcm(int n, vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
        if (i == j) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        
        for (int k = i; k < j; k++) {
            int steps = arr[i-1] * arr[k] * arr[j] + mcm(n, arr, i, k, dp) + mcm(n, arr, k+1, j, dp);
            mini = min(mini, steps);
        }
        
        return dp[i][j] = mini;
    }

    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int i = n-1; i >= 1; i--) {
            for (int j = i + 1; j < n; j++) {
                int mini = 1e9;
                
                for (int k = i; k < j; k++) {
                    int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                    mini = min(mini, steps);
                    dp[i][j] = mini;
                }
            }
        }

        return dp[1][n-1];
    }
};
