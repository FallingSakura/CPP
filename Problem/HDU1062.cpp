#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        stack<char> s;
        while(1)
        {
            char ch=getchar();
            if(ch==' '||ch=='\n'||ch==EOF)
            {
                while(!s.empty()) printf("%c",s.top()),s.pop();
                if(ch=='\n'||ch==EOF) break;
                printf(" ");
            }
            else s.push(ch);
        }
        puts("");
    }
    return 0;
}