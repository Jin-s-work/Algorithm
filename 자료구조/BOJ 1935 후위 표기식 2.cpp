
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


double arr[26];
stack<double>st;
double a, b;
// 값이 소수로 계산되어서 stack이나 arr에 들어가므로 double로 한다.

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    string s;
    cin >> s;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    
    for(int i=0;i<s.size();i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            
            if(s[i] == '+'){
                st.push(b + a);
            }
            else if(s[i] == '-'){
                st.push(b - a);
            }
            else if(s[i] == '/'){
                st.push(b / a);
            }
            else if(s[i] == '*'){
                st.push(b * a);
            }
        }
        else{
            st.push(arr[s[i] - 'A']);
            // 부호가 아니라 알파벳일 경우 s[i]에서 A를 빼주어서 arr의 값을 넣어준다.
            // 앞에서 arr 값을 입력 받아서 사용 가능
        }
        
        
    }
    
    cout << fixed;
    cout.precision(2);
    cout << st.top();
    // 제일 마지막에 남는 스택의 top을 출력
    
    
    return 0;

}

// 스택을 활용하여 푸는 문제.
// 적당히 풀 수 있을 거 같은데 다시 나중에 풀어 봐야겠다..
