/*
	BOJ3085
	<사탕 게임>
	문제
	상근이는 어렸을 적에 "봄보니 (Bomboni)" 게임을 즐겨했다.

가장 처음에 N×N크기에 사탕을 채워 놓는다. 사탕의 색은 모두 같지 않을 수도 있다. 상근이는 사탕의 색이 다른 인접한 두 칸을 고른다. 그 다음 고른 칸에 들어있는 사탕을 서로 교환한다. 이제, 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분(행 또는 열)을 고른 다음 그 사탕을 모두 먹는다.

사탕이 채워진 상태가 주어졌을 때, 상근이가 먹을 수 있는 사탕의 최대 개수를 구하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	char** block = new char*[n]; //2차원 배열 동적할당
	for (int i = 0; i < n; i++)
		block[i] = new char[n];
	for(int i=0;i<n;i++){ 
		for (int j = 0; j < n; j++) {
			cin>>block[i][j];
		}
	}

	int max1 = 0; //가로 교체
	for (int i = 0; i < n; i++) {
		int temMax = 0;
		for (int j = 0; j < (n - 1); j++) {
			if (block[i][j] != block[i][j + 1])  //인접 다르면 교체
				swap(block[i][j], block[i][j + 1]);
			else continue;

			for(int m=0;m<n;m++){  //열 확인
				int temp = 1;
				for (int k = 0; k < (n-1); k++) {
					if (block[m][k] == block[m][k + 1]) {
						temp += 1;
						if (temp > temMax) temMax = temp;
					}
					else temp = 1;
				}
			}
			for (int m = 0; m < n; m++) { //행 확인
				int temp = 1;
				for (int k = 0; k < (n - 1); k++) {
					if (block[k][m] == block[k+1][m]) {
						temp += 1;
						if (temp > temMax) temMax = temp;
					}
					else temp = 1;
				}
			}
			if (temMax > max1) max1 = temMax;
			swap(block[i][j], block[i][j+1]); //원상태 복구
		}
	}
	int max2 = 0; //세로 교체
	for (int i = 0; i < (n-1); i++) {
		int temMax = 0;
		for (int j = 0; j < n; j++) { //인접 다르면 교체
			if (block[i][j] != block[i + 1][j])
				swap(block[i][j], block[i + 1][j]);
			else continue;

			for (int m = 0; m < n; m++) {  //열 확인
				int temp = 1;
				for (int k = 0; k < (n - 1); k++) {
					if (block[m][k] == block[m][k + 1]) {
						temp += 1;
						if (temp > temMax) temMax = temp;
					}
					else temp = 1;
				}
			}
			for (int m = 0; m < n; m++) { //행 확인
				int temp = 1;
				for (int k = 0; k < (n - 1); k++) {
					if (block[k][m] == block[k + 1][m]) {
						temp += 1;
						if (temp > temMax) temMax = temp;
					}
					else temp = 1;
				}
			}
			if (temMax > max2) max2 = temMax;
			swap(block[i][j], block[i + 1][j]); //원상태 복구
		}
	}
	
	if (max1 < max2) swap(max1,max2);
	cout << max1;
	return 0;
}
