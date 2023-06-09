#include<bits/stdc++.h>
using namespace std;
int s[200005];
void qsort(int a[],int l,int r)
{
    int i=l,j=r,flag=a[(l+r)/2],tmp;
    do{
        while(a[i]<flag) i++;
        while(a[j]>flag) j--;
        if(i<=j)
        {
            swap(a[i],a[j]);
            // tmp=a[i];
            // a[i]=a[j];
            // a[j]=tmp;
            i++,j--;
        }
    }while(i<=j);
    if(l<j)
        qsort(a,l,j);
    if(i<r)
        qsort(a,i,r);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&s[i]);
    qsort(s,1,n);
    for(int i=1;i<=n;i++)
    {
        printf("%d ",s[i]);
    }
}