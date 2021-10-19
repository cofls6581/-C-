/*
	BOJ11053
	<가장 긴 증가하는 부분 수열>
	문제
	수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	vector <int> v(n + 1);
	vector <int> dp(n + 1);
	for (int i = 1; i <= n; ++i) { //값 초기화
		cin >> v[i];
		dp[i] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (v[j] < v[i] && dp[j] >= dp[i])
				dp[i] = dp[j] + 1;
		}
	}
	int ans = -1;
	while (n > 0) {
		ans = max(ans, dp[n]);
		--n;
	}
	cout << ans;
	return 0;
}
