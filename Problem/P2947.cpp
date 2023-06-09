#include<bits/stdc++.h>
using namespace std;
int h[200005],ans[200005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
    }
    stack<int> st;
    for(int i=n;i>=1;i--)
    {
        while(!st.empty()&&h[st.top()]<=h[i]) st.pop();//比它矮的全部出栈
        //因为倒着遍历，所以新入栈的一定更靠左更靠前也更矮更有可能是更优解
        if(st.empty()) ans[i]=0;//右边没有奶牛比它高
        else ans[i]=st.top();//最近的且比它高的
        st.push(i);//入栈
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}