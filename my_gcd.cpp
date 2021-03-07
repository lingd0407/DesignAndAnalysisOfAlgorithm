#include<iostream>
#include <algorithm>
using namespace std;
/*求最大公约数的n种方法
1.短除法
2.欧几里得算法
   两个正整数a和b（a>b），它们的最大公约数等于a除以b的余数c和b之间的最大公约数
3.更相减损法：
   两个正整数a和b（a>b），它们的最大公约数等于a-b的差值c和较小数b的最大公约数。 
4.更相减损术与移位结合：不但避免了取模运算，而且算法性能稳定，时间复杂度为O(log(max(a, b)))
5.C++库 
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

