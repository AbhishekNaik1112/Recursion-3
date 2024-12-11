// Flood Fill Algorithm - https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

// An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

// Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

// To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the new color.

// Examples:

// Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]
// Explanation: From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected by a path of the same color as the starting pixel are colored with the new color.Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
// Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 0
// Output: [[0,0,0],[0,0,0]]
// Explanation: The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.
// Input: image = [[0,0,0],[0,0,0]], sr = 1, sc = 1, newColor = 0
// Output: [[0,0,0],[0,0,0]]
// Explanation: The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.
// Constraints:
// 1 <= n <= m <= 500
// 0 <= pixel values <= 10
// 0 <= newColor <= 10
// 0 <= sr <= (n-1)
// 0 <= sc <= (m-1)

#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>>& matrix, int r, int c, int originalColor, int newColor, int row, int col) {
    if (r < 0 || r >= row || c < 0 || c >= col || matrix[r][c] != originalColor) {  //bounds
        return;
    }

    matrix[r][c] = newColor;  //changing to new color

    helper(matrix, r - 1, c, originalColor, newColor, row, col);
    helper(matrix, r + 1, c, originalColor, newColor, row, col); // recursive calls
    helper(matrix, r, c - 1, originalColor, newColor, row, col);
    helper(matrix, r, c + 1, originalColor, newColor, row, col);
}

vector<vector<int>> findAll(vector<vector<int>>& matrix, int sr, int sc, int newColor) {
    int row = matrix.size();
    int col = matrix[0].size();
    int originalColor = matrix[sr][sc]; //og color

    if (originalColor != newColor) {  //if not same
        helper(matrix, sr, sc, originalColor, newColor, row, col);
    }
    return matrix; // if same return
}

int main() {
    int m, n, sr, sc, newColor;
    cin >> m >> n;
    cin >> sr >> sc >> newColor;

    vector<vector<int>> matrix(m, vector<int>(n));  //input
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }


    vector<vector<int>> sols = findAll(matrix, sr, sc, newColor);

    for (const auto& sol : sols) {
        for (int i : sol) {
            cout << i << " ";
        }
        cout<<endl;
    }

    return 0;
}
