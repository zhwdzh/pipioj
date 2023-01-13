#include<iostream>
#include<bits/stdc++.h>
#define INF 0x7ffff

using namespace std;

int vis[101];//���ʱ������
int MG[101][101];//�ڽӾ���

//-----------------------------------Prim����-------------------------------------------------
int prim(int M) {
	//dist�����ŵ����ϵ���������ľ���
	int dist[M];
	//ansΪ�������ansΪ-1���򲻿���
	int ans = 0;

	//�Ƚ���һ���������MMT
	for (int i = 1; i <= M; i++) {
		dist[i] = MG[1][i];
	}
	vis[1] = 1; //��ǵ�һ�����ѷ���

	//��ʣ�ඥ���������
	for (int i = 2; i <= M; i++) {
		int minCost = INF;
		int minId;

		//�ӵ�һ�����㿪ʼ��������С��δ�����Ҳ����ɻ�·�ĵ�
		for (int j = 1; j <= M; j++) {
			if (!vis[j] && minCost > dist[j]) {
				//���¶��㼰�ɱ�
				minCost = dist[j];
				minId = j;
			}
		}

		if (minCost == INF)	return -1;

		vis[minId] = 1;
		ans += dist[minId];

		//����dist����
		for (int j = 1; j <= M; j++) {
			if (!vis[j] && dist[j] > MG[minId][j]) {
				dist[j] = MG[minId][j];
			}
		}
	}
	return ans;

}

int main() {
	int M, N;

	//�����Ȩͼ
	while (cin >> M >> N) { //MΪ���㣬NΪ��
		int start, end, weight;

		//��ʼ���ڽӾ���
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= M; j++) {
				if (i == j) MG[i][j] = 0; //�Լ����Լ�����Ϊ0
				else MG[i][j] = INF; //�Լ���������ʼ������Ϊ�����
			}
		}

		//��ʼ�����ʱ������,Ϊ0��ʾδ����
		for (int i = 1; i <= M; i++) vis[i] = 0;

		for (int i = 1; i <= N; i++) {
			cin >> start >> end >> weight;
			MG[start][end] = MG[end][start] = weight; //����ͼ���ǵô�����
		}

		int res = prim(M);

		if (res == -1) cout<<"?"<<endl;
		else cout<<res<<endl;
	}

	return 0;
}

//-------------------------Kruskal����(�𰸴���50%)---------------------------------------------
//	#include<iostream>
//	#include<bits/stdc++.h>
//	using namespace std;
//
//	struct Edge {
//		int u, v, w; // u->v wΪȨֵ
//	};
//
//	int n, m, father[105];		//father[NV]��ʾ���鼯����
//	Edge g[5000];
//
//	bool cmp(Edge a, Edge b) {
//		return a.w < b.w;
//	}
//
//	int findFather(int x) {	//���鼯��ѯ���� ��·��ѹ��
//		return x == father[x] ? x : father[x] = findFather(father[x]);
//	}
//
//	// �ʺ�ϡ��ͼ
//	int kruskal() {
//		int ans = 0, numEdge = 0;
//
//		//����n���ߣ��Ѱ��������У������������ͬһ������ �ϲ�����
//		for (int i = 0; i < n; i++) {
//			int faU = findFather(g[i].u);
//			int faV = findFather(g[i].v);
//			if (faU != faV) {
//				father[faU] = faV;
//				ans += g[i].w;
//				numEdge++;
//				if (numEdge == n - 1) break;
//			}
//		}
//		if (numEdge != n - 1)
//			return -1;	//�޷���ͨʱ����-1
//		else
//			return ans;
//	}
//
//	int main() {
//		while (cin >> m >> n) {
//			//���鼯��ʼ��
//			for (int i = 1; i <= m; i++) father[i] = i;
//
//			//����n���ߣ�����Ȩֵ��С����
//			for (int i = 0; i < n; i++) {
//				cin >> g[i].u >> g[i].v >> g[i].w;
//			}
//			sort(g, g + n, cmp);
//
//			int res = kruskal();
//
//			if (res != -1) {
//				cout << res << endl;
//			} else {
//				cout << "?" << endl;
//			}
//		}
//		return 0;
//	}
