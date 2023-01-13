#include<bits/stdc++.h>
using namespace std;

struct node{
	int u,v,w;//���� u ���� v��v ֻҪ w Ԫ
}e[250000];

//tot ��¼��С�������ı���,k ��¼ͼ�ı���+1
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
			if(i<j&&x!=0) {//�Գƾ���ǧ��ǵ�û���Ż��� 0��������
				e[k].u=i;
				e[k].v=j;
				e[k].w=x;
				k++;
			}
		}
	}
	//�� 0 ���������ȨΪ a �ı�
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
