// class Trie{
//     public:
//     struct trienode{
//         bool end;
//         trie* child[26];
//     };
//     trienode* get()
//     {
//         trienode* node=new trienode();
//         node->end=false;
//         for(int i=0;i<26;i++)
//         {
//             node->child[i]=nullptr;
//         }

//         return node;
//     } 

// }
class Solution {
public:
    struct trienode {
        bool end;
        trienode* child[26];
    };

    trienode* get() {
        trienode* node = new trienode();
        node->end = false;
        for (int i = 0; i < 26; i++) {
            node->child[i] = nullptr;
        }
        return node;
    }

    trienode* root;

    Solution() {
        root = get();
    }

    void insert(string& word) {
        trienode* crawl = root;
        for (char c : word) {
            int idx = c - 'a';
            if (crawl->child[idx] == nullptr) {
                crawl->child[idx] = get();
            }
            crawl = crawl->child[idx];
        }
        crawl->end = true;
    }

    bool dfs(trienode* node, string& word, int pos, int cnt) {
        if (cnt > 2) return false;

        if (pos == word.size()) {
            return node->end;
        }

        int idx = word[pos] - 'a';

        for (int i = 0; i < 26; i++) {
            if (node->child[i] != nullptr) {
                if (dfs(node->child[i], word, pos + 1, cnt + (i != idx))) {
                    return true;
                }
            }
        }

        return false;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        for (auto &word : dictionary) {
            insert(word);
        }

        vector<string> ans;

        for (auto &q : queries) {
            if (dfs(root, q, 0, 0)) {
                ans.push_back(q);
            }
        }

        return ans;
    }
};