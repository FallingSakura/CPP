#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*懒得写了，目前进度走到将前缀表达式转为中缀表达式，但是同运算级并没有按照题目顺序*/
/*40%*/
struct fstack{//手写栈
    char w[30005];
    int t=0;//栈顶位置
    void push(int x)//插入
    {
        w[++t]=x;
    }
    char top()//返回顶部值
    {
        return w[t];
    }
    void pop()//弹出栈顶
    {
        t--;
    }
    bool empty()//判断是否为空
    {
        return t==0;
    }
}st,bas;
signed main()
{
    //st;//存放待处理符号
    //bas;//存放表达式
    char c;
    while((c=getchar())!=EOF)
    {
        if(c>='0'&&c<='9')
        {
            bas.push(c);
            continue;
        }
        if(c=='(')
        {
            st.push(c);
            continue;
        }
        if(c==')')
        {
            while(st.top()!='(')
            {
                bas.push(st.top());
                st.pop();//弹出(
            }
            st.pop();
            continue;
        }
        if(c=='^'&&(st.empty()||st.top()=='('))
        {
            st.push(c);
            continue;
        }
        else if(c=='^')
        {
            while((c=='^'&&(st.empty()||st.top()=='('))==false)
            {
                bas.push(st.top());
                st.pop();
            }
            st.push(c);
            continue;
        }
        if((c=='*'||c=='/')&&(st.empty()||st.top()=='('||st.top()!='^'))
        {
            st.push(c);
            continue;
        }
        else if(c=='*'||c=='/')
        {
            while(((c=='*'||c=='/')&&(st.empty()||st.top()=='('||st.top()!='^'))==false)
            {
                bas.push(st.top());
                st.pop();
            }
            st.push(c);
            continue;
        }
        if((c=='+'||c=='-')&&(st.empty()||st.top()=='('||(st.top()!='^'&&st.top()!='*'&&st.top()!='/')))
        {
            st.push(c);
            continue;
        }
        else if(c=='+'||c=='-')
        {
            while(((c=='+'||c=='-')&&(st.empty()||st.top()=='('||(st.top()!='^'&&st.top()!='*'&&st.top()!='/')))==false)
            {
                bas.push(st.top());
                st.pop();
            }
            st.push(c);
            continue;
        }
    }
    while(!st.empty())
    {
        bas.push(st.top());
        st.pop();
    }
    while(!bas.empty())
    {
        cout<<bas.top();
        bas.pop();
    }
    return 0;
}