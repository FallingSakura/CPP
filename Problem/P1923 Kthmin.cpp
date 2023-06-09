#include<bits/stdc++.h>
using namespace std;
int ans=0,k,s[5000005],n;
void qsort(int a[],int l,int r)
{
    if(l==r)
    {
        ans=a[l];
        return;
    }
    int i=l,j=r,flag=a[(l+r)/2];
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
    if(k<=j) qsort(a,l,j);
    else if(k>=i) qsort(a,i,r);
    else qsort(a,j+1,i-1);
}
int main()
{
    scanf("%d%d",&n,&k);
    k+=1;
    for(int i=1;i<=n;i++)
        scanf("%d",&s[i]);
    qsort(s,1,n);
    printf("%d",ans);
}