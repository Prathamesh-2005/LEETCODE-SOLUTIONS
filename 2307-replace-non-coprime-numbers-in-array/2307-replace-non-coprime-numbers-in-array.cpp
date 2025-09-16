class Solution {
public:
    int gcd(int a ,int b)
    {
        while(b!=0)
        {
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    int lcm(int a,int b)
    {
        return (a/gcd(a,b))*b;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        
        for (int x : nums) {
            ans.push_back(x);

            while (ans.size() >= 2) {
                int a = ans.back(); ans.pop_back();
                int b = ans.back(); ans.pop_back();

                int g = gcd(a, b);
                if (g > 1) {
                    ans.push_back(lcm(a, b)); 
                } else {
                    ans.push_back(b);
                    ans.push_back(a);
                    break;
                }
            }
        }

        return ans;
    }
};