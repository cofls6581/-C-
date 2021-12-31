#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string s;
    
    for(int i=0;i<n;++i){
        s="";
        arr1[i]= arr1[i]|arr2[i]; //bitor 연산자
        
        while(s.size()!=n){
            if(arr1[i]%2==0)
                s.push_back(' ');
            else
                s.push_back('#');
            arr1[i] /= 2;
        }
        reverse(s.begin(), s.end());
        answer.push_back(s);
    }
 
    return answer;
}
