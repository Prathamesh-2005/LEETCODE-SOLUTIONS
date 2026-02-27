class BrowserHistory {
public:
    stack<string>st1; //for history 
    stack<string>st2; //for future
    string ans;
    BrowserHistory(string homepage) {
        ans=homepage;
    }
    
    void visit(string url) {
        st1.push(ans);
        ans=url;
        while(!st2.empty())
        {
            st2.pop();
        }
    }
    
    string back(int steps) {
        
        while(steps!=0 && !st1.empty())
        {
            st2.push(ans);
            ans=st1.top();
            st1.pop();
            steps--;
        }
        return ans;
    }
    
    string forward(int steps) {
        
        while(steps!=0 && !st2.empty())
        {
            st1.push(ans);
            ans=st2.top();
            st2.pop();
            steps--;
        }
        return ans;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */