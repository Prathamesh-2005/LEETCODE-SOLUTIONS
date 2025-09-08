class Solution {
public:
    struct trie
    {
        int idx;
        trie* child[26];

         ~trie()
     {
        for(int i=0;i<26;i++)
        {
            if(child[i])
            delete child[i];
        }
    }
    };

    trie* get(int i)
    {
        trie* root =new trie();
        root->idx=i;

        for(int i=0;i<26;i++)
        {
            root->child[i]=nullptr;
        }
        return root;
    }
    void insert(trie* root,int i,vector<string>& wordsContainer)
    {
        string word=wordsContainer[i];
        int n=word.length();

        for(int j=n-1;j>=0;j--)
        {
            char ch=word[j];
            int idx=ch-'a';

            if(root->child[idx]==nullptr)
            {
                root->child[idx]=get(i);
            }
            root=root->child[idx];
            if(wordsContainer[root->idx].length()>wordsContainer[i].length())
            {
                root->idx=i;
            }
        }
    }
    int search(trie* root,string& word)
    {
        int result=root->idx;
        int n=word.length();

        for(int j=n-1;j>=0;j--)
        {
            int idx=word[j]-'a';
            root=root->child[idx];

            if(root==nullptr)
            {
                return result;
            }
            result=root->idx;
        }
        return result;
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n=wordsContainer.size();
        int m=wordsQuery.size();
        vector<int>ans(m);
        trie* root=get(0);

        for(int i=0;i<n;i++)
        {
            int idx=root->idx;
            if(wordsContainer[idx].length()>wordsContainer[i].length())
            {
                root->idx=i;
            }
            insert(root,i,wordsContainer);
        }
        for(int i=0;i<m;i++)
        {
            ans[i]=search(root,wordsQuery[i]);
        }
        delete root;
        return ans;
    }
};