

#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    int num1 = 0;
    int num2 = 0;
    stack<char>st;
    for(int i=0;i<s.length();i++){
        if(s[i] == '('){
            st.push(s[i]);
            num1++;
        }
        else if(s[i] == ')' && !st.empty()){
            num2++;
            st.pop();
        }
        
        // 맨 마지막 테스트만 틀렸다..! 그래서 수정
    }
    
    if(num1 == num2)
        answer = true;
    else
        answer = false;
    
    if(s[0] == ')')
        answer = false;
    
    // 음 맞긴 했는데 별로 마음에 안듬

    return answer;
}





// 이걸 사용하는 것이 정 풀이이긴 하다.

// for(int i = 0; i < s.size(); i++)
//     {
//         if(s[i] == '(')
//             st.push('(');
//         else
//         {
//             if(!st.empty() && st.top() == '(')
//                 st.pop();
//             else
//                 st.push(')');
//         }
//     }











