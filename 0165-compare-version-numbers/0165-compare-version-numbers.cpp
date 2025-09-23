class Solution {
public:
    int compareVersion(string version1, string version2) {
        int ans=0;
        vector<string>ver1;
        vector<string>ver2;
        string temp="";
        int i=0;
        for(;i<version1.size();i++)
        {
            if(version1[i]=='.')
            {
                ver1.push_back(temp);
                temp.clear();
            }
            else {
                temp+=version1[i];
            }
        }
        ver1.push_back(temp);

        temp.clear();
        i=0;
        for(;i<version2.size();i++)
        {
            if(version2[i]=='.')
            {
                ver2.push_back(temp);
                temp.clear();
            }
            else {
                temp+=version2[i];
            }
        }
        ver2.push_back(temp);
        int n=max(ver1.size(),ver2.size());
        for(i=0;i<n;i++)
        {
            int num1=(i<ver1.size() ? stoi(ver1[i]) : 0);
            int num2=(i<ver2.size() ? stoi(ver2[i]) : 0);

            if(num1<num2)
            {
                return -1;
            }
            else if(num1>num2)
            {
                return 1;
            }
        }
        return 0;
    }
};