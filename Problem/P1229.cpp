#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int ans;
char a[N],b[N];
int main()
{
    cin>>a>>b;
    for(int i=0;a[i];i++)
        for(int j=1;b[j];j++)
            if(a[i]==b[j]&&a[i+1]==b[j-1])
                ans++;
    cout<<(1<<ans)<<endl;
}