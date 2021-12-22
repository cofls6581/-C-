#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int nP=0,nY=0;
    
    for(int i=0 ;i<s.size(); ++i){
        if(s[i]=='P'|| s[i]=='p')
            nP++;
        else if(s[i]=='y'|| s[i] =='Y')
            nY++;
    }
    
    if(nP==nY) answer=true;
    else answer=false;
    
    return answer;
}
