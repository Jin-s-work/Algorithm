
#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <functional>
#include <map>
#include <set>

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h, w;




int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> t;
    
    while(t--){
        
        string s;
        cin >> s;
        
        stack<char>st;
        bool check = true;
        // 기본은 true로 해논다. 왜냐하면 기본적인 상태는 true이기에
        
        for(int i=0;i<s.size();i++){
            if(s[i] == '(')
                st.push('(');           // (가 나올 경우 (를 stack에 push
            else if(s[i] == ')'){
                if(!st.empty() && st.top() == '(')
                    st.pop();           // stack이 비어있지 않고 제일 위가 (인 경우 pop 해준다.
                                        // 즉 제일 위의 top인 (를 없애줌
                else{
                    check = false;      // stack이 비어있는데, )가 온 경우 false로 해주고 break
                    break;              // stack이 안 비어 있어도 wㅔ일 위가 (가 아니면 똑같이
                }                       // 원래 true이다가 안 될 경우에 false로 바꾸어줌
            }                           // 기본적인 상태는 true
        }
        
        if(st.empty() && check)     // stack이 비어있고, check가 true일 경우 YES
            cout << "YES" << '\n';
        else                        // stack이 아직 남아있거나 check가 거짓일 경우 무조건 NO
            cout << "NO" << '\n';
        
    }
    
    return 0;

}

// 되게 간단하게 했었는데 당연히 아님
// 자료 구조 문제 이므로 스택을 이용하여 넣고 뺀다.

// 처음 했던 방법이 안된 것은 )가 먼저 나와도 답은 원래대로 나오지만, 정당하게 괄호가 된 것이 아니기에
// 이런 경우를 제외하면 stack을 사용하여서 )가 나올 경우 그 전의 (를 제거해주면서 앞도 계속 확인해 주는 것이 필요하다.
