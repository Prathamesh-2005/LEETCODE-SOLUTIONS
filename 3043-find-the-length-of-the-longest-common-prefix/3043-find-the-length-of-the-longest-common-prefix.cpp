class Solution {
public:
    struct trie{
        trie* digit[10];
    };

    trie* get()
    {
        trie* node=new trie();
        for(int i=0;i<10;i++)
        {
            node->digit[i]=nullptr;
        }
        return node;
    }
    trie* root;

    Solution()
    {
        root=get();
    }

    void insert(int num)
    {
        trie* crawl=root;
        string nums=to_string(num);

        for(int i=0;i<nums.length();i++)
        {
            int idx=nums[i]-'0';
            if(crawl->digit[idx]==nullptr)
            {
                crawl->digit[idx]=get();
            }
            crawl=crawl->digit[idx];
        }
    }

    int find(int num)
    {
        string nums=to_string(num);
        int cnt=0;
        trie* crawl=root;
        for(int i=0;i<nums.length();i++)
        {
            int idx=nums[i]-'0';
            if(crawl->digit[idx]==nullptr)
            {
                return cnt;
            }
            cnt++;
            crawl=crawl->digit[idx];
        }
        return cnt;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans=INT_MIN;

        for(int i=0;i<arr1.size();i++)
        {
            insert(arr1[i]);
        }

        for(int i=0;i<arr2.size();i++)
        {
            ans=max(ans,find(arr2[i]));
        }

        return ans==INT_MIN ? 0 : ans;
    }
};