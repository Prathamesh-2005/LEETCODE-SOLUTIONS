class Solution {
public:
    void right(vector<int>& arr,int k)
    {
        k=k%arr.size();
        reverse(arr.begin(),arr.end());
        reverse(arr.begin(),arr.begin()+k);
        reverse(arr.begin()+k,arr.end());
    }

    void left(vector<int>& arr,int k)
    {
        k=k%arr.size();
        reverse(arr.begin(),arr.begin()+k);
        reverse(arr.begin()+k,arr.end());
        reverse(arr.begin(),arr.end());
    }
    bool areSimilar(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>mat=grid;
        k=k%m;

        for(int i=0;i<n;i++)
            {
                if(i & 1)
                {
                    left(mat[i],k);
                }else{
                    right(mat[i],k);
                }
            }

        return mat==grid;
    }
};