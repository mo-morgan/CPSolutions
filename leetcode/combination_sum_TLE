class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        unordered_map<int, vector<vector<int>>> m;
        
        for (int i = 0; i < candidates.size(); i++) {
            vector<vector<int>> v(1, vector<int> (1, candidates[i]));
            m[candidates[i]] = v;
        }
        
        
        for (int currentTarget = 1; currentTarget <= target; currentTarget++) {
            // ex: currentTarget = 6, our candidates are [1, 2, 3]
            // k = 6-3 = 3, 6-2 = 4, 6-1 = 5
            // so in m[3], we can append 3 to the vector of vectors
            // in m[4], we can append 2 to the vector of vectors
            // in m[5], we can append 1 to the vector of vectors
            for (auto cand : candidates) {
                // trying to fill up m[currentTarget]
                int k = currentTarget - cand;
                if (k <= 0) continue; 
                // if k == 0 then it is a candidate of itself

                // else
                // we grab the vectors currently at m[k] so we can just append cand to it
                vector<vector<int>> vec = m[k];
                if (vec.size() == 0) {
                    // no candidates yet for m[k], so undoable
                    continue;
                } 
                // ex: currentTarget = 5, k = 5-3 = 2
                // m[k] = [[2]]
                // we want m[currentTarget] = [[2, 3]]
                for (int i = 0; i < vec.size(); i++) {
                    vec[i].push_back(cand);
                    
                    m[currentTarget].push_back(vec[i]);
                }
            }
        }
        
        for(long long i = static_cast<long long>(m[target].size())-1; i >= 0; --i)
        {
            for(size_t j = 0; j < static_cast<size_t>(i); ++j)
            {
                if(is_permutation(m[target][static_cast<size_t>(i)].begin(), m[target][static_cast<size_t>(i)].end(), m[target][j].begin(), m[target][j].end()))
                {
                    m[target].erase(m[target].begin()+i);
                    break;
                }
            }
        }
        
        return m[target];
    }
};
