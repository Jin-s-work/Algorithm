
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
    ll ans = 0;
    ll num = 1;             // 곱해주는 것이므로 1부터 해야한다.
    bool check = false;
    
    for(int i=0;i<s.size();i++){
        
        if(s[i] == '('){
            st.push('(');
            num *= 2;
        }
        else if(s[i] == ')'){       // 옆에 (가 있으면 2로
            if(st.empty() || st.top() != '('){
                check = true;
                break;
                // 비어 있거나 바로 저장된 stack이 (가 아닐 경우 true로 하고 끝냄
            }
            else{
                if(s[i-1] == '(')   // 스택 보다 바로 원래 문자열 옆이 (이면/
                    ans += num;     // 곱해준 num을 ans에 더해준다.
                                    // 즉 num은 그때그때 곱할때 사용하여 각자 더한다.
                st.pop();
                num /= 2;        // 바로 옆이 (가 아닐 경우 st를 pop해주고, num을 다시 돌아가게 한다.
            }
            // 즉, st의 제일 마지막으로 들어온 원소는 (이지만, 왼쪽의 문자열은 (가 아닌 경우
        }
        else if(s[i] == '['){
            st.push('[');
            num *= 3;
        }
        else if(s[i] == ']'){       // 왼쪽에 [가 있으면 3으로
            if(st.empty() || st.top() != '['){
                check = true;
                break;        // 즉 그냥 바로 ]나 )가 올 경우 true로 하고 나가서 할수 없는 0을 출력
            }                 // [가 아닐 수도 없는 것이 앞에 )가 있으면 이미 pop으로 빠져나가 있어야하므로
            else{
                if(s[i-1] == '['){
                    ans += num;
                }
                st.pop();
                num /= 3;
                    
            }
        }
    }
    
    if(!st.empty() || check)
        cout << 0 << '\n';
    else
        cout << ans << '\n';
    
    
    return 0;

}

// 스택 문제 쉬운듯하지만 어렵다..
