class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;

        for (int num : nums) {
            st.push(num);
            while (st.size() > 1) {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();

                int g = gcd(a, b);

                if (g == 1) {
                    st.push(b);
                    st.push(a);
                    break;
                } else {
                    st.push(lcm(a, b));
                }
            }
        }

        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
