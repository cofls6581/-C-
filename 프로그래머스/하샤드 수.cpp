#include <string>
using namespace std;

bool solution(int x) {
    int sum=0;
    int k=x;
    while(k>9){
        sum+=k%10;
        k=k/10;
    }
    sum+=k;
    if ((x % sum) ==0)
        return true;
    else
        return false;
}
