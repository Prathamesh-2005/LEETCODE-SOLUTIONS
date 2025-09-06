class Trie {
public:
    struct TrieNode
    {
        bool end;
        TrieNode *child[26];
    };

    TrieNode* get()
    {
        TrieNode* node=new TrieNode();
        node->end=false;

        for(int i=0;i<26;i++)
        {
            node->child[i]=nullptr;
        }
        return node;
    }
    TrieNode* root;
    Trie() {
       root=get(); 
    }
    
    void insert(string word) {
        TrieNode* crawl=root;

        for(int i=0;i<word.length();i++)
        {
            int idx=word[i]-'a';

            if(crawl->child[idx]==nullptr)
            {
                crawl->child[idx]=get();
            }
            crawl=crawl->child[idx];
        }
        crawl->end=true;
    }
    
    bool search(string word) {
        TrieNode* crawl=root;

        for(int i=0;i<word.length();i++)
        {
            int idx=word[i]-'a';

            if(crawl->child[idx]==nullptr)
            {
                return false;
            }
            crawl=crawl->child[idx];
        }
        if(crawl!=nullptr && crawl->end==true)
        {
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawl=root;
        int i;
        for(i=0;i<prefix.length();i++)
        {
            int idx=prefix[i]-'a';

            if(crawl->child[idx]==nullptr)
            {
                return false;
            }
            crawl=crawl->child[idx];
        }
        if(i==prefix.length())
        {
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */