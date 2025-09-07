class Solution {
public:
    vector<string>ans;
    vector<vector<int>>direc={{-1,0},{0,-1},{1,0},{0,1}};
    int n,m;
    struct node{
        bool end;
        string word;
        node* child[26];
    };
    node* get()
    {
        node* crawl=new node();
        crawl->end=false;
        crawl->word="";

        for(int i=0;i<26;i++)
        {
            crawl->child[i]=nullptr;
        }
        return crawl;
    }
    void insert(node* root,string& word)
    {
        node* crawl=root;

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
        crawl->word=word;
    }
    void solve(vector<vector<char>>& board,int i,int j,node* root)
    {
        if(i<0 || i>=n || j<0 || j>=m)
        {
            return ;
        }

        if(board[i][j]=='$' || root->child[board[i][j]-'a']==nullptr)
        {
            return ;
        }
        
        root=root->child[board[i][j]-'a'];

        if(root->end==true)
        {
            ans.push_back(root->word);
            root->end=false;
        }
        char temp=board[i][j];
        board[i][j]='$';
        for(auto& d:direc)
        {
            int I=i+d[0];
            int J=j+d[1];
            solve(board,I,J,root);
        }
        board[i][j]=temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
         n=board.size();
         m=board[0].size();
        node* root=get();

        for(auto& s:words)
        {
            insert(root,s);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int idx=board[i][j]-'a';
                if(root->child[idx]!=nullptr)
                {
                    solve(board,i,j,root);
                }
            }
        }
        return ans;
    }
};