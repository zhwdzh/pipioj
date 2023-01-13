#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;

	while ( cin >> n ) {
		int salary[n], num = 0;
		for (int i = 0; i < n; i++) {
			cin >> salary[i];
		}
		for (int i = 0; i < n; i++) {
			int k = salary[i];
			int l1, l2, l3, l4, l5, l6;
			l1 = k / 100; //贪心算法的精髓之处，每次都尽可能用面额大的钱币付款
			l2 = (k - l1 * 100) / 50;
			l3 = (k - l1 * 100 - l2 * 50) / 10;
			l4 = (k - l1 * 100 - l2 * 50 - l3 * 10) / 5;
			l5 = (k - l1 * 100 - l2 * 50 - l3 * 10 - l4 * 5) / 2;
			l6 = k - l1 * 100 - l2 * 50 - l3 * 10 - l4 * 5 - l5 * 2;
			num = num + l1 + l2 + l3 + l4 + l5 + l6;
		}
		cout << num << endl;
	}

	return 0;

}
