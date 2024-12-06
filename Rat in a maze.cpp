// Rat in a maze - https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

// Consider a rat placed at position (0, 0) in an n x n square matrix mat. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

// The matrix contains only two possible values:

// 0: A blocked cell through which the rat cannot travel.
// 1: A free cell that the rat can pass through.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list.+

// The task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.

// Examples:

// Input: mat[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
// Output: ["DDRDRR", "DRDDRR"]
// Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
// Input: mat[][] = [[1, 0], [1, 0]]
// Output: []
// Explanation: No path exists and the destination cell is blocked.
// Input: mat = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
// Output: ["DDRR", "RRDD"]
// Explanation: The rat has two possible paths to reach the destination: 1. "DDRR" 2. "RRDD", These are returned in lexicographically sorted order.
// Constraints:
// 2 ≤ mat.size() ≤ 5
// 0 ≤ mat[i][j] ≤ 1

#include <bits/stdc++.h>
using namespace std;

int row, col;

void helper(vector<vector<int>>& arr, vector<string>& res, string s, int i, int j) {
    if (i < 0 || j < 0 || i > row || j > col || arr[i][j] == 0) return;
    
    if (i == row && j == col) {
        res.push_back(s);
        return;
    }
    
    arr[i][j] = 0;
    
    helper(arr, res, s + "U", i - 1, j);
    helper(arr, res, s + "D", i + 1, j);
    helper(arr, res, s + "L", i, j - 1);
    helper(arr, res, s + "R", i, j + 1);
    
    arr[i][j] = 1;
}

vector<string> findAll(vector<vector<int>> &arr) {
    vector<string> res;
    int n = arr.size();
    row = n - 1;
    col = n - 1;
    helper(arr, res, "", 0, 0);
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }

    vector<string> sols = findAll(arr);
    if (sols.empty()) {
        cout << "No sol" << endl;
    } else {
        for (const string& sol : sols) {
            cout << sol << endl;
        }
    }

    return 0;
}
