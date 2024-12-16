// M-Coloring Problem - https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

// You are given an undirected graph consisting of v vertices and a list of edges, along with an integer m. Your task is to determine whether it is possible to color the graph using at most m different colors such that no two adjacent vertices share the same color. Return true if the graph can be colored with at most m colors, otherwise return false.

// Note: The graph is indexed with 0-based indexing.

// Examples:

// Input: v = 4, edges[] = [(0,1),(1,2),(2,3),(3,0),(0,2)], m = 3
// Output: true
// Explanation: It is possible to color the given graph using 3 colors, for example, one of the possible ways vertices can be colored as follows:
// Vertex 0: Color 3
// Vertex 1: Color 2
// Vertex 2: Color 1
// Vertex 3: Color 2
// Input: v = 3, edges[] = [(0,1),(1,2),(0,2)], m = 2
// Output: false
// Explanation: It is not possible to color the given graph using only 2 colors because vertices 0, 1, and 2 form a triangle.
// Expected Time Complexity: O(mV)
// Expected Auxiliary Space: O(v2)

// Constraints:
// 1 ≤ v ≤ 20
// 1 ≤ edges.size() ≤ (v*(v-1))/2
// 0 ≤ edges[i][j] ≤ n-1
// 1 ≤ m ≤ v


#include <bits/stdc++.h>
using namespace std;

bool isSafe(int currV, int color, const vector<vector<int>>& matrix, vector<int>& colors) {
    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[currV][i] == 1 && colors[i] == color) {
            return false;
        }
    }
    return true;
}

bool helper(int currV, int v, int m, vector<int>& colors, const vector<vector<int>>& matrix) {
    if (currV == v) {
        return true;
    }
    for (int color = 1; color <= m; color++) {
        if (isSafe(currV, color, matrix, colors)) {
            colors[currV] = color;
            if (helper(currV + 1, v, m, colors, matrix)) {
                return true;
            }
            colors[currV] = 0;
        }
    }
    return false;
}

bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
    vector<vector<int>> matrix(v, vector<int>(v, 0));
    for (const auto& edge : edges) {
        matrix[edge.first][edge.second] = 1;
        matrix[edge.second][edge.first] = 1;
    }
    vector<int> colors(v, 0);
    return helper(0, v, m, colors, matrix);
}

int main() {
    int v, e, m;
    cin >> v >> e;

    vector<pair<int, int>> edges(e);
    for (int i = 0; i < e; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    cin >> m;

    if (graphColoring(v, edges, m)) {
        cout << "T";
    } else {
        cout << "F";
    }

    return 0;
}
