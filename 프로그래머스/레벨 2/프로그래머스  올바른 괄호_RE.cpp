#include<string>
#include <iostream>
#include <queue>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    if(s[0] == ')')
        return false;
    
    queue<char>q;
    q.push(s[0]);
    int i = 0;
    while(1){
        
        i++;
        
        if(i == s.length())
            break;
        
        if(s[i] == '(')
            q.push(s[i]);
        else{
            if(q.empty())
                answer = false;
            // )일 경우에 pop을 보통하는데 pop할 (가 없을 경우에는 무조건 불가하므로 여기서 false로
            
            q.pop();
            
        }
    }
    
    if(!q.empty())
        answer = false;
    

    return answer;
}

// #include <string>
// #include <iostream>
// #include <stack>

// using namespace std;

// bool solution(string s)
// {
//     bool answer = true;
    
//     int num1 = 0;
//     int num2 = 0;
//     stack<char>st;
//     for(int i=0;i<s.length();i++){
//         if(s[i] == '('){
//             st.push(s[i]);
//             num1++;
//         }
//         else if(s[i] == ')' && !st.empty()){
//             num2++;
//             st.pop();
//         }
        
//         // 맨 마지막 테스트만 틀렸다..! 그래서 수정
//     }
    
//     if(num1 == num2)
//         answer = true;
//     else
//         answer = false;
    
//     if(s[0] == ')')
//         answer = false;


//     return answer;
// }



// // 이걸 사용하는 것이 정 풀이이긴 하다.
// // for(int i = 0; i < s.size(); i++)
// //     {
// //         if(s[i] == '(')
// //             st.push('(');
// //         else
// //         {
// //             if(!st.empty() && st.top() == '(')
// //                 st.pop();
// //             else
// //                 st.push(')');
// //         }
// //     }

