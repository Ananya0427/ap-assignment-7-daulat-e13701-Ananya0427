class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;

        
        auto removePair = [&](string &str, char first, char second, int val) -> int {
            stack<char> st;
            int points = 0;
            string temp;
            for (char c : str) {
                if (!st.empty() && st.top() == first && c == second) {
                    st.pop();
                    points += val;
                } else {
                    st.push(c);
                }
            }
            
            temp.reserve(st.size());
            while (!st.empty()) {
                temp += st.top();
                st.pop();
            }
            reverse(temp.begin(), temp.end());
            str = temp;
            return points;
        };

        if (x > y) {
            res += removePair(s, 'a', 'b', x); 
            res += removePair(s, 'b', 'a', y); 
        } else {
            res += removePair(s, 'b', 'a', y); 
            res += removePair(s, 'a', 'b', x); 
        }

        return res;
    }
};
