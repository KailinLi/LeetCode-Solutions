class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>>adjacencyList(numCourses);
        vector<int>indegree(numCourses, 0);
        vector<int>res;
        size_t begin = 0;
        for (auto item : prerequisites) {
            ++indegree[item.first];
            adjacencyList[item.second].push_back(item.first);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!indegree[i]) res.push_back(i);
        }
        while (begin < res.size()) {
            int current = res[begin++];
            for (auto item : adjacencyList[current]) {
                if (!--indegree[item]) res.push_back(item);
            }
        }
        return res.size() == numCourses ? res : vector<int>{};
    }
};