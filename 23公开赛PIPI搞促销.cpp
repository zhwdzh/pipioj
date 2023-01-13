#include<bits/stdc++.h>
using namespace std;

struct node{
	int u,v,w;//买完 u 再买 v，v 只要 w 元
}e[250000];

//tot 记录最小生成树的边数,k 记录图的边数+1
int a,b,k=0,tot=0,ans,fa[505];
bool cmp(node x,node y){
	return x.w<y.w;
}

int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

void kruskal(){
	int j=0;
	while(j<k&&tot<b){
		if(find(e[j].u)!=find(e[j].v)){
			tot++;
			ans+=e[j].w;
			int xx=find(e[j].u);
			int yy=find(e[j].v);
			if(xx!=yy) fa[xx]=yy;
		}
		j++;
	}
}

int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++){
		for(int j=1;j<=b;j++){
			int x;
			scanf("%d",&x);
			if(i<j&&x!=0) {//对称矩阵，千万记得没有优惠是 0，不建边
				e[k].u=i;
				e[k].v=j;
				e[k].w=x;
				k++;
			}
		}
	}
	//从 0 向各点连边权为 a 的边
	for(int i=1;i<=b;i++) {
		e[k].u=0;
		e[k].v=i;
		e[k].w=a;
		k++;
	}
	for(int i=0;i<=b;i++) fa[i]=i;
	
	sort(e,e+k,cmp);
	kruskal();
	printf("%d\n",ans);
	
	return 0;
}
