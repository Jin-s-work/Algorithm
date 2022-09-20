#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    for(int i=0;i<s.length();i++){
        if(i == 0){
            if(s[i] >= 'a' && s[i] <= 'z')
                s[i] = s[i] - 'a' + 'A';
        }
        
        if(s[i] == ' '){
            if(s[i+1] >= 'a' && s[i+1] <= 'z')
                s[i+1] = s[i+1] - 'a' + 'A';
        }
        
        if(s[i] >= 'A' && s[i] <= 'Z' && s[i-1] != ' ' && i != 0)
            s[i] = s[i] - 'A' + 'a';
        // 맨 앞을 빼고 중간에 있는 단어가 대문자일 경우 없애줌
        
    }
    
    
    
    
    return s;
}

// #include <string>
// #include <vector>

// using namespace std;

// string solution(string s) {
//     string answer = "";
    
//     if(s[0] >= 'a' && s[0] <= 'z')
//         s[0] = s[0] - 'a' + 'A';
    
//     for(int i=0;i<s.length();i++){
//         if(s[i] == ' '){
//             if(s[i+1] >= 'a' && s[i+1] <= 'z')
//                 s[i+1] = s[i+1] - 'a' + 'A';
//         }
//         else{
//             if(s[i+1] >= 'A' && s[i+1] <= 'Z')
//                 s[i+1] = s[i+1] - 'A' + 'a';
//         }
        
//     }
    
    
//     return s;
// }
