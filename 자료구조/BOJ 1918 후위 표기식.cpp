
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
    
    string s;
    cin >> s;
    stack<char>st;
    string ans;
    
    for(int i=0;i<s.size();i++){
        
        if(s[i] == '+' || s[i] == '-'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        // +이거나 -일 경우 스택이 비어있지 않거나 직전에 스택에 쌓인 것이 (가 아닌 이상
        // 스택의 값들을 ans에 넣어주고, (가 나오면 +나 -를 스택에 넣어준다.
        // 즉 ()가 나올 경우 +-라도 우선순위가 있어 괄호 밖의 기호보다 먼저 넣어줌
        
        // 즉 다시 말해서 남은 스택이 없거나 (가 나올 경우 그냥 +-를 스택에 넣어준다.
        
        else if(s[i] == '*' || s[i] == '/'){
            while(!st.empty() && (st.top() == '*' || st.top() == '/')){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        // *나 /일 경우 스택이 비어있지 않거나 직전에 쌓인 스택이 *이거나 /일동안 ans에 넣어주다가
        // 다른 값이 스택의 top에 있을 경우 *나 /를 넣어준다.
        
        // 여기서도 스택이 안남아있거나 스택에 ()+-가 나올 경우 그냥 바로 넣어준다.
        // 즉 +-보다는 먼저 들어가는 것이다.
        
        else if(s[i] == '('){
            st.push(s[i]);
        }
        // (일 경우 스택에 (를 푸시해준다.
        
        else if(s[i] == ')'){
            while(st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        // )일 경우 직전에 스택에 쌓인 것이 (가 아닌 이상 그 전까지의 값들을 ans에 넣어준다.
        // (가 나올 경우 그냥 pop해준다.
        
        // )일 때는 (가 나오는 경우 (를 그냥 pop하는 것..
        
        else{
            ans += s[i];
        }
        // 그냥 알파벳일 경우 바로 ans에 넣어준다.
    }
    
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    // 스택에 아직 남은 경우 나머지 넣어줌
    
    cout << ans;
    
    
    return 0;

}


// 왠진 모르겠는데 다시 하니까 제대로 나온다.. 머디..
// 다시 정리하니까 알겠다.. 추후에 한번 더 풀어보아야 스택 연습이 될듯..!
