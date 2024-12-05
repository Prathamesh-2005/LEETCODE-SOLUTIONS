class Solution {
public:
    bool canChange(string start, string target) {
        int i=0;
        int j=0;
        int n=start.length();
        int m=target.length();

        while(i<n || j<m)
        {
            while(i<n && start[i]=='_') i++;

            while(j<m && target[j]=='_') j++;

            if(i==n || j==m)
            {
                return (i==n && j==m);
            }

            if((start[i]!=target[j]) || (start[i]=='L' && j>i) || (start[i]=='R' && i>j))
            {
                return false;
            }

            i++;
            j++;
        }
        return true;
        
    }
};