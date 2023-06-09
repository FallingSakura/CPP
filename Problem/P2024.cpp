#include <stdio.h>
const int maxn = 501000;
int f[maxn],h[maxn],n,k,d,x,y;
void init() {
	for(int i=1; i<=3*n; i++)//维护三倍并查集
    { 
		f[i] = i;
		h[i] = 0;
	}
}
int find(int i) {
	return f[i]==i ? f[i] : f[i]=find(f[i]);
}
void merge(int a, int b) {
	int fa = find(a);
	int fb = find(b);
	if(fa != fb) {
		if(h[fa] < h[fb]) {//按秩合并
			f[fa] = fb;
		} else {
			f[fb] = fa;
			if(h[fa]==h[fb]) h[fa]++;
		}
	}
}

int main(void) {
	scanf("%d%d",&n,&k);//n个动物，k句话
	init();//初始化 
	int ans=0;  //记录谎话数量 
	while(k--) {
		scanf("%d %d %d", &d, &x, &y);
		if(x>n || y>n || (d==2 && x==y))//X或Y比N大，或自己吃自己
        {  
			ans++;
			continue;
		}
		//分情况讨论 
		if(d==1) 
        {  //同类时 
			if(find(x)==find(y+n) || find(x+n)==find(y))//如果Y吃X，或X吃Y 
            {
				ans++;
				continue;
			}
			merge(x, y);
			merge(x+n, y+n);
			merge(x+2*n, y+2*n);
		} else if(d==2)
        {  //不同类且X吃Y时 
			if(find(x)==find(y) || find(x)==find(y+n))//如果X和Y同类或Y吃X
            {
			
				ans++;
				continue;
			}
			merge(x+n, y);
			merge(x+2*n, y+n);
			merge(x, y+2*n);
		}
	}
	printf("%d\n", ans);
	return 0;	
}
