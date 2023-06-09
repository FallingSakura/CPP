#include<bits/stdc++.h>
using namespace std;
int s[200005];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        scanf("%d",&s[i]);
    
    sort(s+1,s+1+n);
    int len=unique(s+1,s+1+n)-s;//unique函数返回去重后最后一个元素的指针，所以减去s的指针后便是去重后的数组长度（因为unique是把相同的往数组尾放）
    // cout<<len<<endl;
    if(k>len)
    {
        cout<<"NO RESULT";
    }
    else cout<<s[k];
    return 0;
}