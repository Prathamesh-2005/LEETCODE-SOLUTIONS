#define ll long long 
class Solution {
public:
    vector<string> op = {"+", "-", "*"};

    bool check(string& expr, int target) {
        int n = expr.length();
        ll ans = 0;
        ll curr = 0;
        ll last = 0; 
        char oper = '+';     

        for (int i = 0; i < n; i++) {
            char c = expr[i];

            if (isdigit(c)) {
                curr = curr * 10 + (c - '0'); 
            }

            if (!isdigit(c) || i == n - 1) { 
                if (oper == '+') {
                    ans += curr;
                    last = curr;
                } 
                else if (oper == '-') {
                    ans -= curr;
                    last = -curr;
                } 
                else if (oper == '*') {
                    ans -= last;        
                    ans += last * curr;  
                    last = last * curr;
                }

                oper = c;   
                curr = 0; 
            }
        }

        return ans == target;
    }

    void solve(int idx, string num, int target, string expr, vector<string>& ans) {
        if (idx == num.length()) {
            if (!expr.empty() && check(expr, target)) {
                ans.push_back(expr);
            }
            return;
        }

        for (int i = idx; i < num.size(); i++) {
            if (i > idx && num[idx] == '0') break; 

            string part = num.substr(idx, i - idx + 1);

            if (expr.empty()) {
                solve(i + 1, num, target, part, ans);
            } else {
                for (auto& o : op) {
                    solve(i + 1, num, target, expr + o + part, ans);
                }
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(0, num, target, "", ans);
        return ans;
    }
};
