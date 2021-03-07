#include<iostream>
#include<math.h>
using namespace std;
int A[1000];   //假定n小于1000 
int L[100];
//实现埃拉托色尼筛选法：输出一个小于或等于n的所以质数的数组
void sieve(int n){
	for(int i=2; i<=n; i++){
		A[i] = i;
	}
	for(int i=2; i<=sqrt(n); i++){
		if(A[i]!=0){
			int j = i*i;
			while(j<=n){
				A[j] = 0;
				j = j+i;
			}
		}
	} 
	int k = 0;
	for(int i=2; i<=n; i++){
		if(A[i]){
			L[k++] = A[i];
		}
	}
} 
 
int main(){
	
	
	sieve(500);
	for(int i=0; i<500; i++){
		cout << L[i] << endl;
	}
	return 0;
	
}

