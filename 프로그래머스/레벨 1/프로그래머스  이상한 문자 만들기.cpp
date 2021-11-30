

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int n = s.length();
    int k = 0;
    
    for(int i=0;i<n;i++){   // s의 길이만큼 동안
        if(k % 2 == 0){     // 짝수 일때
            if((s[i] >= 'a') && (s[i] <= 'z'))
                s[i] = s[i] - 'a' + 'A';
            // s[i]가 소문자 일 경우에 대문자로 바꾸어 준다.
        }
    else{
        if((s[i] >='A') && (s[i] <='Z'))
            s[i] = s[i] - 'A' + 'a';
    }       // k가 홀수 이고, s[i]가 대문자일때, 소문자로 바꾸어 준다.
    
    k++;
    // 인덱스를 계속 증가해주다가
    if(s[i] == ' '){
        k = 0;
    }   // s[i]가 " " 즉 빈공간을 만나면, k를 0으로 초기화한다.
}
    
    for(int i=0;i<n;i++){
        answer += s[i];
    }
    
    return answer;
}













