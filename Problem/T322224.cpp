#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int a,b;
    scanf("%lld%lld",&a,&b);
    int c=ceil(1.0*(a-b)/100);
    cout<<c;
    return 0;
}