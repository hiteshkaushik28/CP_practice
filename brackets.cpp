// Author : Hitesh Kaushik
// Compilation : g++ <filename.cpp>
// Run : ./a.out

#include <bits/stdc++.h>
using namespace std;

void check(string s){
    bool ok = true;
    stack<char> st;
    for(char c : s){
        if(c == '(' || c == '{' || c == '[')
            st.push(c);
        else{
            if(c == ')'){
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else{
                    ok = false;
                    break;
                }
            }
            else if(c == '}'){
                if(!st.empty() && st.top() == '{')
                    st.pop();
                else{
                    ok = false;
                    break;
                }
            }
            else{
                if(!st.empty() && st.top() == '[')
                    st.pop();
                else{
                    ok = false;
                    break;
                }
            }
        }   
    }
    if(ok && st.empty())
        cout << "YES\n";
    else
        cout << "NO\n";
}   

int main()
{
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        check(s);
    }
    return 0;
}
