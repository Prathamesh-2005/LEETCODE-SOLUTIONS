class Solution {
public:
    struct trie
    {
        trie* left;
        trie* right;
    };
    void insert(int& num,trie* root)
    {
        trie* crawl=root;

        for(int i=31;i>=0;i--)
        {
            int ith_bit=(num>>i)&1;

            if(ith_bit==0)
            {
                if(crawl->left==nullptr)
                {
                    crawl->left=new trie();
                }
                crawl=crawl->left;
            }
            else{
                if(crawl->right==nullptr)
                {
                    crawl->right=new trie();
                }
                crawl=crawl->right;
            }
        }
    }
    int find(int& num,trie* root)
    {
        trie* crawl=root;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int ith_bit=(num>>i)&1;
            if(ith_bit==1)
            {
                if(crawl->left)
                {
                    ans+=(1<<i);
                    crawl=crawl->left;
                }
                else{
                    crawl=crawl->right;
                }
            }
            else{
                if(crawl->right)
                {
                    ans+=(1<<i);
                    crawl=crawl->right;
                }
                else{
                    crawl=crawl->left;
                }
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        trie* root =new trie();
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            insert(nums[i],root);
        }

        for(int i=0;i<nums.size();i++)
        {
            int temp=find(nums[i],root);
            ans=max(temp,ans);
        }
        return ans;
    }
};