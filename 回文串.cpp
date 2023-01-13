#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
	int count = 0;
	string a;

	while ( cin >> a ) {
		count++;
		int flag = 0; //标志位 判断是不是回文串
		int len = a.size();
		printf("case%d: ", count);
		for (int i = 0; i < len / 2; i++) {
			if (a[i] != a[len - i - 1]) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			printf("no\n");
		} else {
			printf("yes\n");
		}
	}

	return 0;

}
