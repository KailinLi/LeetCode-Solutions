class Solution {
public:
    vector<vector<int>> res;
    vector<int> cp;
    void dfs(int u, vector<vector<int>> &graph) {
        if (u == graph.size() - 1) {
            res.push_back(cp);
        }
        for (int i = 0; i < graph[u].size(); ++i) {
            cp.push_back(graph[u][i]);
            dfs(graph[u][i], graph);
            cp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        cp.push_back(0);
        dfs(0, graph);
        return res;
    }
};