#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    int n=arr.size();
    double sum=0;
    for(int i=0;i<=n-1;i++)
        sum+=arr[i];
    answer=sum/n;
    return answer;
}
