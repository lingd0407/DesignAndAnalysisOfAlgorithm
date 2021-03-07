#include<iostream>
#include <algorithm>
using namespace std;
/*�����Լ����n�ַ���
1.�̳���
2.ŷ������㷨
   ����������a��b��a>b�������ǵ����Լ������a����b������c��b֮������Լ��
3.������𷨣�
   ����������a��b��a>b�������ǵ����Լ������a-b�Ĳ�ֵc�ͽ�С��b�����Լ���� 
4.�������������λ��ϣ�����������ȡģ���㣬�����㷨�����ȶ���ʱ�临�Ӷ�ΪO(log(max(a, b)))
5.C++�� 
6. t = min(a, b);
*/
int gcd_2(int a, int b){
	int c;
	while(b){
		c = a%b;
		a = b;
		b = c;
	}
	return a;
	
	//return b?Gcd(b, a%b):a;
} 
int gcd_3(int a, int b){
//	int c;
//	while(a!=b){
//		c = a - b;
//		a = b;
//		b = c;
//		if(a<b) swap(a,b);
//	}
//	return a;
	
	if(a==b) return a;
	if(a>b) gcd_3(a-b, b);
	else gcd_3(b-a, a);
	
} 
int gcd_4(int a, int b){
	if(a==b) return a;
	if(a<b) gcd_4(b, a);
	else{
		if(!a&1 && !b&1) return gcd_4(a>>1, b>>1);
		else if(!a&1 && b&1) return gcd_4(a>>1, b);
		else if(a&1 && !b&1) return gcd_4(a, b>>1);
		else gcd_4(b, a-b);
	}
		
} 
int gcd_5(int a, int b){
	int t = min(a,b);
	if(t==0) return a+b;
	while(a%t || b%t){
		t--;
	}
	return t;
	
}

int main(){
	int n = 60;
	int m = 22;
	cout << !(m&1) << " " << (!m&1);
	//cin >> n >> m;
	cout << gcd_2(n, m) <<endl;
	cout << gcd_3(n, m) << endl;
	cout << gcd_4(n, m) << endl;

	cout << __gcd(n, m) << endl;
	cout << gcd_5(n, m) << endl;

	return 0;
}

