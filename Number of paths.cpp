// Number of paths - https://www.geeksforgeeks.org/problems/number-of-paths0926/1

// Given a grid of size m x n, the task is to determine the number of distinct paths from the top-left corner to the bottom-right corner. At each step, one can either move down or right. Given the integers m and n, return the number of unique paths from the top-left corner to the bottom-right corner.

// Note: The test cases are designed such that the answer will always fit within a 32-bit integer.

// Examples:

// Input: m = 3, n = 3
// Output: 6
// Explanation: Let the given input 3*3 grid is filled as such:
// A B C
// D E F
// G H I
// The possible unique paths which exists to reach 'I' from 'A' following above conditions are as follows: ABCFI, ABEHI, ADGHI, ADEFI, ADEHI, ABEFI

// Input: m = 2, n = 3
// Output: 3
// Explanation: Let the given input 2*3 grid is filled as such:
// A B C
// D E F
// The possible unique paths which exists to reach 'F' from 'A' following above conditions are as follows: ABCF, ADEF and ABEF.
// Input: m = 1, n = 4
// Output: 1
// Explanation: Let the given input 1*4 grid is filled as such:
// A B C D 
// The only possible unique path is ABCD.
// Constraints:
// 1 ≤ m ≤ 100
// 1 ≤ n ≤ 100

// TLE Code

#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

long long solve(int R, int C, vector<vector<bool>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    if (R < 0 || R >= m || C < 0 || C >= n || grid[R][C] == 0) return 0;
    if (R == m - 1 && C == n - 1 && grid[R][C]) return 1;
    
    long long total = 0;
    bool temp = grid[R][C];
    grid[R][C] = 0;
    total = (solve(R + 1, C, grid) % mod + solve(R, C + 1, grid) % mod) % mod;
    grid[R][C] = temp;
    return total % mod;
}

long long numberOfPaths(int m, int n) {
    vector<vector<bool>> grid(m, vector<bool>(n, true));
    return solve(0, 0, grid);
}

int main() {
    int m, n;
    cin >> m;
    cin >> n;

    cout <<numberOfPaths(m, n) << endl;
    return 0;
}

// Can be optimized by using dp

#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
long long numberOfPaths(int m, int n) {
    vector<vector<long long>> sol(m, vector<long long>(n, 0));


//bascase
    for (int i = 0; i < m; ++i)
        sol[i][0] = 1;
    for (int j = 0; j < n; ++j)
        sol[0][j] = 1;

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            sol[i][j] = (sol[i - 1][j] + sol[i][j - 1]) % mod; //each cell
        }
    }

    return sol[m - 1][n - 1]; //return last...-1 size
}

int main() {
    int m, n;
    cin >> m;
    cin >> n;
    cout << numberOfPaths(m, n) << endl;
    return 0;
}
