class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> pos;
        for (int i = 0; i < target.size(); ++i) {
            pos[target[i]] = i;
        }

        vector<int> seq;
        for (int num : arr) {
            if (pos.count(num)) {
                int idx = pos[num];
                auto it = lower_bound(seq.begin(), seq.end(), idx);
                if (it == seq.end()) seq.push_back(idx);
                else *it = idx;
            }
        }

        return target.size() - seq.size();
    }
};
