class Solution {
public:
    struct VectorHash {
        size_t operator()(const std::vector<int>& v) const {
            std::hash<int> hasher;
            size_t seed = 0;
            for (int i : v) {
                seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        unordered_map<int, set<vector<int>, VectorHash>> m;
        
        for (int i = 0; i < candidates.size(); i++) {
            m[candidates[i]].insert(vector<int> (1, candidates[i]));
        }
        
        for (int currentTarget = 1; currentTarget <= target; currentTarget++) {
            for (auto cand : candidates) {
                int k = currentTarget - cand;
                if (k <= 0) continue; 
                
                if (m[k].size() == 0) {
                    continue;
                } 
                
                for (auto it = m[k].begin(); it != m[k].end(); it++) {
                    // append current cand to m[k]
                    const std::vector<int>& i = (*it);
                    vector<int> vec = i;
                    vec.push_back(cand);
                    m[currentTarget].insert(vec);
                }
            }
        }
        
        vector<vector<int>> ret;
        for (auto it = m[target].begin(); it != m[target].end(); it++) {
            const std::vector<int>& i = (*it);
            ret.push_back(i);
        }
        return ret;
    }
};
