class Solution {
public:
    int countPalindromicSubsequence(string s) {
        set<char> st(s.begin(), s.end()); 
        int n = s.length();
        int count = 0;

        for (auto& c : st) { 
            int f = -1;
            int l = -1;

            for (int i = 0; i < n; i++) {
                if (c == s[i]) {
                    if (f == -1) { 
                        f = i;
                    }
                    l = i; 
                }
            }

            if (f == l) { 
                continue; 
            }

            set<char> st1; 
            for (int i = f + 1; i < l; i++) { 
                st1.insert(s[i]);
            }

            count += st1.size();
        }
        return count; 
    }
};
