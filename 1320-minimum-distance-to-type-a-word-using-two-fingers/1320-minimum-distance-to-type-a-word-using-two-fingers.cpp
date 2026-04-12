class Solution {
public:
    map<tuple<int,int,int,int,int>, int> dp;

    pair<int,int> get(char ch)
    {
        int val = ch - 'A';  
        int x = val / 6;
        int y = val % 6;
        return {x, y};
    }

    int dist(int x1,int y1,int x2,int y2)
    {
        return abs(x1-x2) + abs(y1-y2);
    }

    int solve(int idx, string &word, int x1,int y1,int x2,int y2)
    {
        if(idx >= word.length())
            return 0;

        auto key = make_tuple(idx,x1,y1,x2,y2);

        if(dp.count(key))
            return dp[key];

        auto [x,y] = get(word[idx]);

        int f1, f2;

        if(x1 == -1)
            f1 = solve(idx+1, word, x, y, x2, y2);
        else
            f1 = dist(x1,y1,x,y) + solve(idx+1, word, x, y, x2, y2);

        if(x2 == -1)
            f2 = solve(idx+1, word, x1, y1, x, y);
        else
            f2 = dist(x2,y2,x,y) + solve(idx+1, word, x1, y1, x, y);

        return dp[key] = min(f1, f2);
    }

    int minimumDistance(string word) {
        return solve(0, word, -1, -1, -1, -1);
    }
};