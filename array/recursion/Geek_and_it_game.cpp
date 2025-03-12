//qp link: https://www.geeksforgeeks.org/problems/geek-and-its-game-of-coins4043/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
/*
🎯 Problem Statement:
There are n coins.
Two players (Geek and opponent) play optimally.
On each turn, a player can remove 1, x, or y coins.
The player who picks the last coin wins.
Geek starts first — the task is to determine if Geek can guarantee a win if both players play optimally.
*/

/*
🌟 Goal:
Geek wants to leave the opponent in a losing position after his move.
If any of the possible next moves leaves the opponent in a guaranteed losing state → Geek wins ✅
If all possible next moves leave the opponent in a winning state → Geek loses ❌
*/
/*
🚀 Core Insight:
👉 Geek does NOT need all paths to lead to a win.
👉 Geek needs to find at least one path where he can force the opponent into a losing position.

🔎 Why OR (|) Fails:
OR would mean "if at least one path wins, Geek wins" → ❌
But Geek isn’t relying on chance — he is playing optimally!
Geek should pick a path that guarantees the opponent will lose, not just hope one path might work.
✅ Correct Strategy:
Geek explores three possible moves:
Remove 1 → n - 1
Remove x → n - x
Remove y → n - y
If any move leaves the opponent in a losing state → Geek wins ✅
If all possible moves leave the opponent in a winning state → Geek loses ❌
*/
class Solution {
  public:
    int solve(int n, int x, int y, vector<int> &dp){
        if(n==0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        
        if(n>=1 && solve(n-1, x, y,dp)==0) return dp[n]=1;
        if(n>=x && solve(n-x , x, y,dp)==0) return dp[n]=1;
        if(n>=y && solve(n-y, x, y,dp)==0)  return dp[n]=1;
        
        return dp[n]=0;
    }
    int findWinner(int n, int x, int y) {
        // code here
        vector<int> dp(n+1, -1);
        return solve(n, x, y,dp);
    }
};
/*
🔥 Logic Explanation:
solve(n - 1, x, y) == 0 → If removing 1 leaves opponent in a losing state → Geek wins
solve(n - x, x, y) == 0 → If removing x leaves opponent in a losing state → Geek wins
solve(n - y, x, y) == 0 → If removing y leaves opponent in a losing state → Geek wins
If all return 1 → Opponent can always respond optimally → Geek loses ❌
✅ Why This Works:
✔️ Geek only needs one winning path.
✔️ If there’s any path where Geek can force the opponent into a losing position, Geek wins.
✔️ Optimal play ensures that Geek will always take the winning path if available.
*/
