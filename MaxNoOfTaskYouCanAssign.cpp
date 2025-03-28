class Solution {
public:
    bool check(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> ws(workers.end() - k, workers.end());
        int p = pills;
        for (int i = k - 1; i >= 0; --i) {
            auto it = ws.lower_bound(tasks[i]);
            if (it != ws.end()) {
                ws.erase(it);
            } else {
                if (p == 0) return false;
                it = ws.lower_bound(tasks[i] - strength);
                if (it == ws.end()) return false;
                ws.erase(it);
                --p;
            }
        }
        return true;
    }
    
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int left = 0, right = min(tasks.size(), workers.size()), ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid, tasks, workers, pills, strength)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
