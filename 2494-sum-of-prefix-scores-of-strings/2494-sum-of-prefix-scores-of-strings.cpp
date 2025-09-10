class Solution {
public:
    struct trie
    {
        // bool end;
        int prefix;
        trie* child[26];
    };
    trie* get()
    {
        trie* node=new trie();
        for(int i=0;i<26;i++)
        {
            node->child[i]=nullptr;
        }
        node->prefix=0;
        return node;
    }
    void insert(trie* root,string& word)
    {
        trie* crawl=root;
        for(int i=0;i<word.length();i++)
        {
            int idx=word[i]-'a';
            if(crawl->child[idx]==nullptr)
            {
                crawl->child[idx]=get();
            }
            crawl=crawl->child[idx];
            crawl->prefix++;
        }
    }
    int search(trie* root,string& word)
    {
        trie* crawl=root;
        int cnt=0;
        for(int i=0;i<word.length();i++)
        {
            int idx=word[i]-'a';
            crawl=crawl->child[idx];
            cnt+=crawl->prefix;
        }
        return cnt;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int>ans;
        int n=words.size();

        trie* root=get();
        for(int i=0;i<n;i++)
        {
            insert(root,words[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            int cnt=search(root,words[i]);
            ans.push_back(cnt);
        }
        return ans;
    }
};