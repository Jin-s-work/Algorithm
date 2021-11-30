

#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i=0;i<s.size();i++){
        if(s[i] != ' '){        // 여기까지는 이해해서 제대로 했는데..
            if(s[i] >= 'a' && s[i] <= 'z')  // a부터 z사이일때
                answer += (s[i] - 'a' + n) % 26 + 'a'; // 26넘으면 안되므로 나누어준다.
            else                            // 아닐 경우
                answer += (s[i] - 'A' + n) % 26 + 'A';
        }
        // 소문자일 때 따로 나누어서 26이 넘어도 안되게 -'a'를 해서 숫자로 만들어준 후
        // % 26 을 통하여 넘어도 순환하게 만들어 주고 다시 'a'를 더한다.
        
        // 대문자일 때는 반대로 해주면 된다.
        else
            answer += ' ';
        // 아닐 경우 즉, 공백일 경우에는 ' '를 더해주면 된다.
    }
    
    return answer;
}













