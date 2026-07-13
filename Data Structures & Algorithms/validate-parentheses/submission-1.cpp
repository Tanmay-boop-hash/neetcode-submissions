class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(char ch: s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
                continue;
            }
            if(st.empty()) {
                return false;
            }
            else {
                if((ch == ')' && st.top()=='(' )|| (ch == '}' && st.top()=='{')|| (ch == ']' && st.top() == '[')) st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};
