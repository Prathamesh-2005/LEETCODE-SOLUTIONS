class Solution {
public:
    struct trie{
        trie *child[26];
        vector<string>vec;
    };
    trie* get()
    {
        trie* root=new trie();

        for(int i=0;i<26;i++)
        {
            root->child[i]=nullptr;
        }
        root->vec={};

        return root;
    }
    void insert(string word,trie* root)
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
            crawl->vec.push_back(word);
        }
    }
    vector<string> search(trie* root, string& str) {
    trie* crawl = root;
    for (char c : str) {
        int idx = c - 'a';
        if (crawl->child[idx] == nullptr)
            return {};  
        crawl = crawl->child[idx];
    }
    vector<string> ans = crawl->vec;
    if (ans.size() > 3)
        ans.resize(3);
    return ans;
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        trie* root=get();

        for(auto& pro:products)
        {
            insert(pro,root);
        }

        vector<vector<string>>ans;
        string str="";
        for(int i=0;i<searchWord.length();i++)
        {
            char ch=searchWord[i];
            str+=ch;
            vector<string>res=search(root,str);
            ans.push_back(res);
        }

        return ans;
    }
};