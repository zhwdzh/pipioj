#include<bits/stdc++.h>
using namespace std;

char mp[12][12];//��ͼ
//����λ��(sx,sy)������ sd��С͵λ��(tx,ty)������ ty���� ans��ר��ֵ tdz
int sx, sy, sd, tx, ty, td, ans, tdz;
bool zt[160005];//��¼ר��ֵ�Ƿ����
void move(int x, int y, int d, int h) { //�ƶ�����,d ��ʾ����h ����������С͵
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
bool pd() { //�ж�ѭ����ֹ�������������������С͵������ȣ��������ص������� 0���˳�ѭ��
	if (sx == tx && sy == ty) return 0;
	else return 1;
}
int main() {
//���ڱ߽�Ҳ���ϰ�������ֱ�ӽ������ 0 �� 11 �±��Ԫ����Ϊ�ϰ�
	for (int i = 0; i <= 11; i++) mp[i][0] = '*', mp[i][11] = '*';
	for (int i = 1; i <= 11; i++) mp[0][i] = '*', mp[11][i] = '*';
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 'S') sx = i, sy = j;
			if (mp[i][j] == 'T') tx = i, ty = j;
		}
	}
	while (pd()) { //ģ��ÿ����
		tdz = sx + sy * 10 + tx * 100 + ty * 1000 + sd * 10000 + td * 40000;
		if (zt[tdz]) { //����ͬһ�����겢�ҷ�����ͬ����� 0 ����������
			cout << 0 << endl;
			return 0;
		}
		zt[tdz] = 1; //���
		move(sx, sy, sd, 0);
		move(tx, ty, td, 1); //�����ƶ�ũ�����ţ
		ans++;//��������һ
	}
	cout << ans << endl; //���
	return 0;
}
