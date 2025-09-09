class Solution {
public:
    struct trie{
        trie* child[10];
    };

    trie* get()
    {
        trie* node=new trie();
        for(int i=0;i<10;i++)
        {
            node->child[i]=nullptr;
        }
        return node;
    }
    
    void insert(int num,trie* root)
    {
        trie* crawl=root;
        string temp=to_string(num);
        for(auto& c:temp)
        {
            int idx=c-'0';
            if(crawl->child[idx]==nullptr)
            {
                crawl->child[idx]=get();
            }
            crawl=crawl->child[idx];
        }
    }

    int search(int num,trie* root)
    {
        int ans=0;
        string temp=to_string(num);
        trie* crawl=root;
        for(auto& c:temp)
        {
            int idx=c-'0';
            if(crawl->child[idx]!=nullptr)
            {
                ans++;
                crawl=crawl->child[idx];
            }
            else{
                break;
            }
        }
        return ans;
    }
    
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        int ans=0;

        trie* root=get();
        for(int i=0;i<n;i++)
        {
            insert(arr1[i],root);
        }
        for(int i=0;i<m;i++)
        {
            ans=max(ans,search(arr2[i],root));
        }
        return ans;
    }
};