#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
	string a;

	while ( cin >> a ) {
		int len = a.size();
		int tmp[4] = {0, 0, 0, 0};
		int count = 0;

		if (len < 8) {
			cout << "NO" << endl;
			continue;
		}

		for (int i = 0; i < len; i++) {
			if (a[i] <= 'Z' && a[i] >= 'A') {
				tmp[0] = 1;
			} else if (a[i] <= 'z' && a[i] >= 'a') {
				tmp[1] = 1;
			} else if (a[i] <= '9' && a[i] >= '0') {
				tmp[2] = 1;
			} else if (a[i] == '~' || a[i] == '!' || a[i] == '@' || a[i] == '#' || a[i] == '$' || a[i] == '%' || a[i] == '^') {
				tmp[3] = 1;
			}
		}

		for (int i = 0; i <= 3; i++) {
			if (tmp[i] == 1) {
				count++;
			}
		}
		if (count >= 3) cout << "YES" << endl;
		else cout << "NO" << endl;

	}

	return 0;

}
