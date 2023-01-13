#include<bits/stdc++.h>
using namespace std;

const int N = 210;
char unin[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char op[10], code[N];

int main() {
	while (scanf("%s", op) != EOF) {
		if (strcmp(op, "ENDOFINPUT") == 0) break;
		getchar();   //获取一个字符
		gets(code);  //获取一个字符串
		int n = strlen(code);
		for (int i = 0; i < n; i++) {
			char c = code[i];
			if (isupper(c)) {				
//			islower
//			islower()用来判断一个字符是否为小写字母，也就是是否属于a~z。
//			
//			cout << islower('a');//非零
//			cout << islower('2');//输出0
//			cout << islower('A');//输出0
//			
//          isupper
//			isupper()用来判断一个字符是否为大写字母。
//			
//			cout << isupper('a');//返回0
//			cout << isupper('2');//返回0
//			cout << isupper('A');//返回非零
				
			int t = (c - 'A' - 5 + 26) % 26;
				printf("%c", unin[t]);
			} else {
				printf("%c", c);
			}
		}
		printf("\n");
		scanf("%s", op);
	}
	return 0;
}
