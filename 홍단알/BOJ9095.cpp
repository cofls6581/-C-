/*
	BOJ9095
	<1, 2, 3 더하기>
	문제
	정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
*/

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int dp[12] = { 0, 1, 2, 4  };
	for(int i=4;i<11;++i)
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	
	int n;
	cin >> n;
	int ans;
	while (n > 0) {
		cin >> ans;
		cout<<dp[ans]<<'\n';
		n--;
	}

	return 0;
}
