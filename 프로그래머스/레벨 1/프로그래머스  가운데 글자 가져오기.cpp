

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    if(s.length() == 1)
        return s;
    
    int n = s.length();
    if(s.length() % 2 == 0){
        answer += s[n/2 - 1];
        answer += s[n/2];
    }
    else
        answer += s[n/2];
    
    return answer;
}













