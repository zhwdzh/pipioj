#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//���Ա�����٣�Ҳ����DP������⣺https://mp.weixin.qq.com/s/3xUm-WOAQHmMBW3_E4pNQA

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int arr[100000];
		int flag = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			if (arr[i] > 0) flag = 1;
		}
		if (flag == 0) {
			printf("%d %d %d\n", 0, 0, 0);
			continue;
		}
		int sum = 0;
		int b = 0;
		int begin = 0;
		int besti, bestj;
		for (int i = 0; i < n; i++) {
			//arr[i-1]>0ʱ
			if (b > 0)	b = b + arr[i];
			//arr[i-1]<=0ʱ
			else {
				//6 -2 11 -4 13 -5 -2 10
				b = arr[i];
				begin = i; //����ʼ�ı��
			}
			if (b > sum) { //�������Ž�
				sum = b;
				besti = begin;
				bestj = i;
			}
		}
		printf("%d %d %d\n",sum,besti,bestj);
	}
	return 0;

}
