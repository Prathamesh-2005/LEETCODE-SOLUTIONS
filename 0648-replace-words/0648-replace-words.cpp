class Solution {
public:
    struct trie
    {
        bool end;
        trie* child[26];
        string word;   
    };
    trie* get()
    {
        trie* crawl=new trie();
        crawl->word="";
        crawl->end=false;

        for(int i=0;i<26;i++)
        {
            crawl->child[i]=nullptr;
        }
        return crawl; 
    }
    void insert(trie* root,string& sub)
    {
        trie* crawl=root;

        for(int i=0;i<sub.length();i++)
        {
            int idx=sub[i]-'a';
            if(crawl->child[idx]==nullptr)
            {
                crawl->child[idx]=get();
            }
            crawl=crawl->child[idx];
        }
        crawl->end=true;
        crawl->word=sub;
    }
    string prefix(trie* root,string& word)
    {
        trie* crawl=root;
        for(auto& c:word)
        {
            int idx=c-'a';
            if(crawl->child[idx]==nullptr)
            {
                return word;
            }
            crawl=crawl->child[idx];
            if(crawl->end==true)
            {
                return crawl->word;
            }
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans="";
        int n=dictionary.size();
        trie* root=get();
        for(int i=0;i<n;i++)
        {
            insert(root,dictionary[i]);
        }
        string curr="";
        int m=sentence.length();
        for(int i=0;i<=m;i++)
        {
            if(i<m && sentence[i]!=' ')
            {
                curr+=sentence[i];
            }
            else{
                if(!curr.empty())
                {
                    if(!ans.empty())
                    {
                        ans+=" ";
                    }
                    ans+=prefix(root,curr);
                    curr="";
                }
            }
        }
        return ans;
    }
};