#include<iostream>
#include<bits/stdc++.h>
#define INF 0x7ffff

using namespace std;

int vis[101];//访问标记数组
int MG[101][101];//邻接矩阵

//-----------------------------------Prim方法-------------------------------------------------
int prim(int M) {
	//dist数组存放到集合到各个顶点的距离
	int dist[M];
	//ans为结果，若ans为-1，则不可行
	int ans = 0;

	//先将第一个顶点加入MMT
	for (int i = 1; i <= M; i++) {
		dist[i] = MG[1][i];
	}
	vis[1] = 1; //标记第一个点已访问

	//将剩余顶点依次添加
	for (int i = 2; i <= M; i++) {
		int minCost = INF;
		int minId;

		//从第一个顶点开始，加入最小的未访问且不构成回路的点
		for (int j = 1; j <= M; j++) {
			if (!vis[j] && minCost > dist[j]) {
				//更新顶点及成本
				minCost = dist[j];
				minId = j;
			}
		}

		if (minCost == INF)	return -1;

		vis[minId] = 1;
		ans += dist[minId];

		//更新dist数组
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

	//存入带权图
	while (cin >> M >> N) { //M为顶点，N为边
		int start, end, weight;

		//初始化邻接矩阵
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= M; j++) {
				if (i == j) MG[i][j] = 0; //自己到自己距离为0
				else MG[i][j] = INF; //自己到其他初始化距离为无穷大
			}
		}

		//初始化访问标记数组,为0表示未访问
		for (int i = 1; i <= M; i++) vis[i] = 0;

		for (int i = 1; i <= N; i++) {
			cin >> start >> end >> weight;
			MG[start][end] = MG[end][start] = weight; //无向图，记得存两遍
		}

		int res = prim(M);

		if (res == -1) cout<<"?"<<endl;
		else cout<<res<<endl;
	}

	return 0;
}

//-------------------------Kruskal方法(答案错误50%)---------------------------------------------
//	#include<iostream>
//	#include<bits/stdc++.h>
//	using namespace std;
//
//	struct Edge {
//		int u, v, w; // u->v w为权值
//	};
//
//	int n, m, father[105];		//father[NV]表示并查集数组
//	Edge g[5000];
//
//	bool cmp(Edge a, Edge b) {
//		return a.w < b.w;
//	}
//
//	int findFather(int x) {	//并查集查询函数 带路径压缩
//		return x == father[x] ? x : father[x] = findFather(father[x]);
//	}
//
//	// 适合稀疏图
//	int kruskal() {
//		int ans = 0, numEdge = 0;
//
//		//遍历n条边（已按升序排列），如果不属于同一个集合 合并集合
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
//			return -1;	//无法连通时返回-1
//		else
//			return ans;
//	}
//
//	int main() {
//		while (cin >> m >> n) {
//			//并查集初始化
//			for (int i = 1; i <= m; i++) father[i] = i;
//
//			//输入n条边，并按权值大小排序
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
