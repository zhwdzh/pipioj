#include<bits/stdc++.h>
using namespace std;

char mp[12][12];//地图
//保安位置(sx,sy)及朝向 sd，小偷位置(tx,ty)即朝向 ty，答案 ans，专属值 tdz
int sx, sy, sd, tx, ty, td, ans, tdz;
bool zt[160005];//记录专属值是否出现
void move(int x, int y, int d, int h) { //移动函数,d 表示方向，h 代表保安还是小偷
	if (d == 0) {
		if (mp[x - 1][y] == '*') if (h == 0) sd = 1;
			else td = 1;
		else if (h == 0) sx--;
		else tx--;
	} else if (d == 1) {
		if (mp[x][y + 1] == '*') if (h == 0) sd = 2;
			else td = 2;
		else if (h == 0) sy++;
		else ty++;
	} else if (d == 2) {
		if (mp[x + 1][y] == '*') if (h == 0) sd = 3;
			else td = 3;
		else if (h == 0) sx++;
		else tx++;
	} else {
		if (mp[x][y - 1] == '*') if (h == 0) sd = 0;
			else td = 0;
		else if (h == 0) sy--;
		else ty--;
	}
}
bool pd() { //判断循环终止条件：如果保安坐标与小偷坐标相等，则他们重叠，返回 0，退出循环
	if (sx == tx && sy == ty) return 0;
	else return 1;
}
int main() {
//由于边界也是障碍，所以直接将数组的 0 和 11 下标的元素设为障碍
	for (int i = 0; i <= 11; i++) mp[i][0] = '*', mp[i][11] = '*';
	for (int i = 1; i <= 11; i++) mp[0][i] = '*', mp[11][i] = '*';
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 'S') sx = i, sy = j;
			if (mp[i][j] == 'T') tx = i, ty = j;
		}
	}
	while (pd()) { //模拟每分钟
		tdz = sx + sy * 10 + tx * 100 + ty * 1000 + sd * 10000 + td * 40000;
		if (zt[tdz]) { //进入同一个坐标并且方向相同就输出 0 并结束程序
			cout << 0 << endl;
			return 0;
		}
		zt[tdz] = 1; //标记
		move(sx, sy, sd, 0);
		move(tx, ty, td, 1); //依次移动农夫和奶牛
		ans++;//分钟数加一
	}
	cout << ans << endl; //输出
	return 0;
}
