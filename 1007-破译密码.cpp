#include<bits/stdc++.h>
using namespace std;

const int N = 210;
char unin[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char op[10], code[N];

int main() {
	while (scanf("%s", op) != EOF) {
		if (strcmp(op, "ENDOFINPUT") == 0) break;
		getchar();   //��ȡһ���ַ�
		gets(code);  //��ȡһ���ַ���
		int n = strlen(code);
		for (int i = 0; i < n; i++) {
			char c = code[i];
			if (isupper(c)) {				
//			islower
//			islower()�����ж�һ���ַ��Ƿ�ΪСд��ĸ��Ҳ�����Ƿ�����a~z��
//			
//			cout << islower('a');//����
//			cout << islower('2');//���0
//			cout << islower('A');//���0
//			
//          isupper
//			isupper()�����ж�һ���ַ��Ƿ�Ϊ��д��ĸ��
//			
//			cout << isupper('a');//����0
//			cout << isupper('2');//����0
//			cout << isupper('A');//���ط���
				
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
