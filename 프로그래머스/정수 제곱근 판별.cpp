#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    double temp=sqrt(n);
    if(temp==(int)temp) answer=(temp+1)*(temp+1);
    if(answer==0) answer=-1;
    
    return answer;
}
