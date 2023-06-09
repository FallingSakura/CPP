#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    string s;
    cin>>s;
    stack<int> st;
    for(int i=0;s[i]!='@';i++)
    {
        int now=0;
        while(s[i]>='0'&&s[i]<='9')
        {
            now*=10;
            now+=s[i]-'0';
            i++;
        }
        if(s[i]=='.')
        {
            st.push(now);
            now=0;
            continue;
        }
        if(s[i]=='+')
        {
            int a=st.top();
            st.pop();
            a+=st.top();
            st.pop();
            st.push(a);
            continue;
        }
        if(s[i]=='-')
        {
            int a=-st.top();
            st.pop();
            a+=st.top();
            st.pop();
            st.push(a);
            continue;
        }
        if(s[i]=='*')
        {
            int a=st.top();
            st.pop();
            a*=st.top();
            st.pop();
            st.push(a);
            continue;
        }
        if(s[i]=='/')
        {
            int a=st.top(),b;
            st.pop();
            b=st.top();
            st.pop();
            st.push(b/a);
        }
    }
    printf("%d",st.top());
    return 0;
}