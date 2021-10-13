/*
	BOJ15990
	<1, 2, 3 더하기 5>
	문제
	정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 3가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다. 단, 같은 수를 두 번 이상 연속해서 사용하면 안 된다.

1+2+1
1+3
3+1
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
*/

#include <iostream>
using namespace std;
#define mod 1000000009

int n, k;
int memo=4;
long long D[100001][4];

void dp(int start) {
	for (int i = start; i <= k; ++i) {
		D[i][1] =( D[i - 1][2] + D[i - 1][3]) % mod;
		D[i][2] =( D[i - 2][1] + D[i - 2][3]) % mod;
		D[i][3] = (D[i - 3][1] + D[i - 3][2]) % mod;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	D[1][1] = 1; D[1][2] = 0; D[1][3] = 0;
	D[2][2] = 1; D[2][3] = 0; D[2][1] = 0;
	D[3][2] = D[3][1] = D[3][3] = 1;
	for (int i = 0; i <n; ++i) {
		cin >> k;
		if (memo <=k) {
			dp(memo); 
			memo = k; 
		}
		cout << (D[k][1] + D[k][2] + D[k][3]) % mod << '\n';
	} 
	return 0;
}
