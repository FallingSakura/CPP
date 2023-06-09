#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    stack<int> s;
    int a,b;
    char c;
    cin>>a;
    int m=10000;
    a=a%m;
    s.push(a);
    while(cin>>c>>b)
    {
        if(c=='*')
        {
            a=s.top();
            s.pop();
            s.push(a*b%m);
        }
        else    s.push(b);
    }
    a=0;
    while(s.size())
    {
        a+=s.top();
        s.pop();
        a%=m;
    }
    cout<<a<<endl;
    return 0;
}