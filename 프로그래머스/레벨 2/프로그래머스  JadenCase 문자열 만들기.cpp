

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    if(s[0] >= 'a' && s[0] <= 'z')
        s[0] = s[0] - 'a' + 'A';
    
    for(int i=0;i<s.length();i++){
        if(s[i] == ' '){
            if(s[i+1] >= 'a' && s[i+1] <= 'z')
                s[i+1] = s[i+1] - 'a' + 'A';
        }
        else{
            if(s[i+1] >= 'A' && s[i+1] <= 'Z')
                s[i+1] = s[i+1] - 'A' + 'a';
        }
        
    }
    
    
    return s;
}

// 머야 문자열 계속 푸니까 익숙해짐..













