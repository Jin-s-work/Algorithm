
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

stack<char>st;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    string s;
    cin >> s;
    int num = 0;
    
    for(int i=0;i<s.size();i++){
        if(s[i] == '('){
            st.push('(');
        }
        else{       // )가 나올 경우
            st.pop();
            // 전에 걸 pop해주고, 그 전에 )가 나오기 전에 pop해서 괜찮다.
            if(s[i-1] == '(')       // 즉 stack에서 없어져도 입력된 s에서 전에 것이 ( 일 경우
                num += st.size();   // 그 바로 전이 (이면 스택에 쌓인 만큼 더해준다.
            else
                num++;              // 그 전이 (가 아닐 경우,
            
        }
    }
    // 따라서 처음 것이 ()만 나올 경우 st의 size만큼 인데, pop해주었기에 0이다.
    // 다음 것은 (가 계속 나올 경우 stack에 넣다가, )가 나올 때, 한번 pop해주고, 뺀 것만큼 남은 (수를 더해준다.
    // 그 다음 또 ()가 나올 떄, (이후 )가 나오므로, pop을 해주면 이제까지의 (에 대해서 더해준다.
    // 그러고 )가 나오면 여기서 마지막인 제일 위의 막대기만 잘리므로, +1만 해주면 된다.
    
    // 다시 (가 나오면 다시 시작 됨...
    
    
    cout << num;
    
    
    return 0;

}


// 이해는 가지만 쉽게 구현하기 힘들었을 거 같다... 스택 쉽지 않군
