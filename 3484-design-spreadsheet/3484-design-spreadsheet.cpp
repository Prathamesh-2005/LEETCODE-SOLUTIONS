class Spreadsheet {
public:
    unordered_map<string,int>mp;
    Spreadsheet(int rows) {
        
    }
    bool isNumber(string &s) {
        if (s.empty()) return false;
        for (char c : s) {
            if (!isdigit(c) && c != '-') return false;
        }
        return true;
    }
    void setCell(string cell, int value) {
        mp[cell]=value;
    }
    
    void resetCell(string cell) {
        mp[cell]=0;
    }
    
    int getValue(string formula) {
        int n=formula.size();
        string op1="";
        string op2="";
        bool flag=false;

        for(int i=0;i<n;i++)
        {
            if(formula[i]=='=')
            {
                continue;
            }
            else if(formula[i]=='+')
            {
                flag=true;
                continue;
            }
            else if(!flag)
            {
                op1+=formula[i];
            }
            else{
                op2+=formula[i];
            }
        }
           int val1, val2;

        if (mp.find(op1) != mp.end()) val1 = mp[op1];
        else if (isNumber(op1)) val1 = stoi(op1);
        else val1 = 0;  

        if (mp.find(op2) != mp.end()) val2 = mp[op2];
        else if (isNumber(op2)) val2 = stoi(op2);
        else val2 = 0;  

        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */