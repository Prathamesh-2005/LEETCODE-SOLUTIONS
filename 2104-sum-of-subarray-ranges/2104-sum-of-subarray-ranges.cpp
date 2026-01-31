#define ll long long 
class Solution {
public:
    vector<int>nsl(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]>nums[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int>nsr(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>ans(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int>ngl(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]<nums[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int>ngr(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>ans(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()]<=nums[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        ll mn=0;
        ll mx=0;

        int n=nums.size();
        vector<int>nslv=nsl(nums);
        vector<int>nsrv=nsr(nums);
        vector<int>nglv=ngl(nums);
        vector<int>ngrv=ngr(nums);
        for(int i=0;i<n;i++)
        {
            int nl=i-nslv[i];
            int nr=nsrv[i]-i;
            ll prod=(ll)nr*nl;
            mn+=(prod*nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            int nl=i-nglv[i];
            int nr=ngrv[i]-i;
            ll prod=(ll)nr*nl;
            mx+=(prod*nums[i]);
        }

        return mx-mn;
    }
};