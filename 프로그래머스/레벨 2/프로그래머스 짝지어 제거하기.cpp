
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;
    
    stack<char>st;
    
    for(int i=0;i<s.length();i++){
        if(st.empty() || st.top() != s[i])
            st.push(s[i]);
        // 스택이 비어있거나, s[i]가 제일 위에 있던 글자와 다를 경우 스택에 넣어줌
        else if(st.top() == s[i])
            st.pop();
        
    }
    
    if(st.empty())
        answer = 1;
    /// 스택이 비어있다면 모두 지워진 것
    else
        answer = 0;

    return answer;
}

// 단순하게 연속 된 것을 비교하면 효율성이 O(n^2)이라서 스택을 이용하여 해야 한다.
// 스택을 이용하면 문자열을 효과적으로 할 수 잇으므로 항상 염두해 두어야 겠다.
