
#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    int pnum = 0;
    int ynum = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] == 'p' || s[i] == 'P')
            pnum++;
        else if(s[i] == 'y' || s[i] == 'Y')
            ynum++;
    }
    
    if(pnum == ynum)
        answer = true;
    else
        answer = false;
    
    if(pnum == 0 && ynum == 0)
        answer = true;
    

    return answer;
}














