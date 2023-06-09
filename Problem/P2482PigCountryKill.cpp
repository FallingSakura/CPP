#include<bits/stdc++.h>
using namespace std;
int n,m;//玩家数，牌堆中牌的数量
char Acard[2010];
char me[15];
char ss[10];
int fz;
bool ed=true;
struct pppig
{
    int HP,cnt;
    char SF;
    bool wq=false;
    char card[2010];
    int next,last;
}P[15];
void get_card(int x,int y)
{
    for(int i=1;i<=y;i++)
    {
        if(!m) m++;
        P[x].card[++P[x].cnt]=Acard[m];
        m--;
    }
}
bool put_J(int x,int y,int z)//使用锦囊牌的人，被使用锦囊的人，是不是第一次（因为只有第一次是无懈掉锦囊牌，后面都是判断是否无懈掉无懈）
{
    int i=x;//从使用无懈的这个人开始，后面依次有机会使用无懈
    while(true)
    {
        if(z==1)
        {
            if(me[y]==P[i].SF||(me[y]=='M'&&P[i].SF=='Z')||(me[y]=='Z'&&P[i].SF=='M'))//我和y是一伙的，如果有J我就要帮它挡下
                for(int j=1;j<=P[i].cnt;j++)
                    if(P[i].card[j]=='J')
                    {
                        P[i].card[j]='U';
                        me[i]=P[i].SF;
                        return !put_J(i,x,0);//i对使用锦囊牌的人使用了无懈可击，如果没有被无懈无懈掉的话，返回的就是0，！0就是1，那么我的这张无懈就生效了
                    }
        }
        else//是否无懈上一张无懈
        {
            if(((P[i].SF=='M'||P[i].SF=='Z')&& me[x]=='F')||(P[i].SF=='F'&&(me[x]=='M'|| me[x]=='Z')))//如果不是一个阵营,那我就要想办法让上一个无懈失效（无懈掉上一个无懈）
                for(int j=1;j<=P[i].cnt;j++)
                    if(P[i].card[j]=='J')
                    {
                        P[i].card[j]='U';
                        me[i]=P[i].SF;
                        return !put_J(i,x,0);//i对上一个使用无懈的人使用了无懈
                    }
        }
        i=P[i].next;
        if(i==x) break;//转了一圈都没有无懈
    }
    return false;//上一张无懈/锦囊牌生效，当前这一张无懈没生效
    //函数返回false代表可以使用锦囊牌，返回true代表无懈生效，锦囊牌失效
}
void Kill(int x,int y)
{
    for(int i=1;i<=P[y].cnt;i++)//我还有桃我不能死！
        if(P[y].card[i]=='P')
        {
            P[y].card[i]='U';
            P[y].HP++;
            return;
        }
    P[P[y].next].last=P[y].last;
    P[P[y].last].next=P[y].next;
    if(P[y].SF=='M')//主公寄了
    {
        ed=true;
        return;
    }
    if(P[y].SF=='F') fz--;//反贼-1
    if(!fz)//反贼寄光了
    {
        ed=true;
        return;
    }
    if(P[y].SF=='F') get_card(x,3);//击杀反贼摸三张
    if(P[y].SF=='Z'&&P[x].SF=='M')
    {
        P[x].cnt=0;
        P[x].wq=false;
    }
}
void put_K(int x,int y)
{
    for(int i=1;i<=P[y].cnt;i++)
    {
        if(P[y].card[i]=='D')//被攻击者有闪
        {
            P[y].card[i]='U';
            return;
        }
    }
    P[y].HP--;
    if(!P[y].HP) Kill(x,y);
}
void put_F(int x,int y)
{
    if(put_J(x,y,1)) return;
    if(P[x].SF=='M'&&P[y].SF=='Z')//忠臣自残
    {
        P[y].HP--;
        if(!P[y].HP) Kill(x,y);
        return;
    }
    int i,j;
    while(true)
    {
        for(i=1;i<=P[y].cnt;i++)//找杀
            if(P[y].card[i]=='K')
            {
                P[y].card[i]='U';
                break;
            }
        if(i>P[y].cnt)
        {
            P[y].HP--;//找遍了也没找到杀
            if(!P[y].HP) Kill(x,y);
            return;
        }
        for(j=1;j<=P[x].cnt;j++)
            if(P[x].card[j]=='K')
            {
                P[x].card[j]='U';
                break;
            }
        if(j>P[x].cnt)
        {
            P[x].HP--;
            if(!P[x].HP) Kill(y,x);
            return;
        }
    }
    return;
}
void put_N(int x)
{
    for(int y=P[x].next;y!=x;y=P[y].next)
        if(!put_J(x,y,1))//没有被无懈可击
        {
            int i;
            for(i=1;i<=P[y].cnt;i++)//第y只猪在找杀响应南蛮入侵
                if(P[y].card[i]=='K')//找到了
                {
                    P[y].card[i]='U';//出出来
                    break;
                }
            if(i>P[y].cnt)//找了一圈没找到
            {
                P[y].HP--;//扣血
                if(P[y].SF=='M'&&me[x]=='U') me[x]='L';//如果未表明身份且AOE到了主就是类反
                if(!P[y].HP) Kill(x,y);//判断击杀
                if(ed) return;
            }
        }
    return;
}
void put_W(int x)
{
    for(int y=P[x].next;y!=x;y=P[y].next)
        if(!put_J(x,y,1))
        {
            int i;
            for(i=1;i<=P[y].cnt;i++)//找闪
                if(P[y].card[i]=='D')
                {
                    P[y].card[i]='U';
                    break;
                }
            if(i>P[y].cnt)//没找到闪
            {
                P[y].HP--;
                if(P[y].SF=='M'&&me[x]=='U') me[x]='L';//如果未表明身份且AOE到了主就是类反
                if(!P[y].HP) Kill(x,y);
                if(ed) return;
            }
        }
    return;
}
void st()//开始
{
    char now_card;
    ed=true;
    if(fz) ed=false;//假如一开始就没有反
    if(ed) return;
    for(int i=1;i;i=P[i].next)
    {
        get_card(i,2);
        bool kill=false;//还没出过杀
        for(int j=1;j<=P[i].cnt;j++)
        {
            if(P[i].card[j]!='U')//没有被使用过
            {
                if(!P[i].HP) break;//死了就不用出牌
                now_card=P[i].card[j];
                if(now_card=='Z')//诸葛连弩
                {
                    P[i].wq=true;
                    P[i].card[j]='U';
                    j=0;
                    continue;
                }
                if(now_card=='P')//桃
                {
                    if(P[i].HP<4)
                    {
                        P[i].HP++;
                        P[i].card[j]='U';
                    }
                    continue;
                }
                if(now_card=='K')//杀
                {
                    if(kill&&!P[i].wq) continue;//出过杀且没有武器
                    if(P[i].SF=='M'&&me[P[i].next]!='F'&&me[P[i].next]!='L') continue;//是主但是下家既不是类也不是反
                    if(P[i].SF=='Z'&&me[P[i].next]!='F') continue;//是忠但下家不是反
                    if(P[i].SF=='F'&&me[P[i].next]!='M'&&me[P[i].next]!='Z') continue;//是反但下家不是忠也不是主
                    P[i].card[j]='U';//可以出
                    put_K(i,P[i].next);
                    me[i]=P[i].SF;//出杀即代表暴露身份
                    kill=true;//出过杀了
                    if(ed) return;
                    continue;
                }
                if(now_card=='F')//决斗
                {
                    if(P[i].SF=='F')
                    {
                        P[i].card[j]='U';
                        put_F(i,1);//是反贼那就和主公决斗
                        me[i]=P[i].SF;//暴漏身份
                        if(ed) return;
                        j=0;
                        continue;
                    }
                    for(int k=P[i].next;k!=i;k=P[k].next)
                        if((P[i].SF=='M'&&(me[k]=='L'||me[k]=='F'))||(P[i].SF=='Z'&&me[k]=='F'))//主和反或类决斗，忠和反决斗
                        {
                            P[i].card[j]='U';
                            put_F(i,k);
                            me[i]=P[i].SF;
                            if(ed) return;
                            j=0;
                            break;
                        }
                    continue;
                }
                if(now_card=='N')//南蛮入侵
                {
                    P[i].card[j]='U';
                    put_N(i);
                    if(ed) return;
                    j=0;
                    continue;
                }
                if(now_card=='W')//南蛮入侵
                {
                    P[i].card[j]='U';
                    put_W(i);
                    if(ed) return;
                    j=0;
                    continue;
                }
            }
        }
    }
}
int main()
{   
    // freopen("P2482_1.in","r",stdin);
    // freopen("out.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        P[i].next=i+1;
        P[i].last=i-1;
    }
    P[n].next=1,P[1].last=n;
    for(int i=2;i<=n;i++)
        me[i]='U';
    me[1]='M';
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<2010;j++)
            P[i].card[j]='U';
        scanf("%s",ss);
        P[i].SF=ss[0];
        for(int j=1;j<=4;j++)
        {
            scanf("%s",ss);
            P[i].card[j]=ss[0];
        }
        P[i].HP=P[i].cnt=4;
        if(P[i].SF=='F') fz++;
        P[i].wq=false;
    }
    for(int i=1;i<=m;i++)
        scanf("%s",ss),Acard[m-i+1]=ss[0];
    st();//开始
    if(P[1].HP<=0) printf("FP\n");//判断谁赢了
    else printf("MP\n");
    for(int i=1;i<=n;i++)
    {
        if(P[i].HP<=0) printf("DEAD\n");
        else{
            for(int j=1;j<=P[i].cnt;j++)//输出牌
                if(P[i].card[j]!='U') printf("%c ",P[i].card[j]);
            printf("\n");
        }
    }
    return 0;
}