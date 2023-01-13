#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
	int m, n, x, y, z;

	while ( cin >> m >> n ) {
		int num = 0;

		if (m < 100 || n > 999 || m > n) {
			cout << "error";
		}

		for (int i = m; i <= n; i++) {
			x = i / 100;
			y = i % 100 / 10;
			z = i % 10;
			if (i == pow(x, 3) + pow(y, 3) + pow(z, 3)) {
				cout << i << " ";
				num++;
			}
			if (i == n && num != 0) {
				cout << endl;
			}
		}

		if (num == 0) {
			cout << "no" << endl;
		}
	}

	return 0;

}
