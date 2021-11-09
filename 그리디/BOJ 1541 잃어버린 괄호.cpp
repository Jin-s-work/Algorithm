
#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstring>
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
    
    string st;
    cin >> st;
    
    string now;
    bool flag = false;
    int num = 0;
    
    for(int i=0;i<=st.size();i++){
        if(st[i] == '+' || st[i] == '-' || st[i] == '\0'){
            if(flag){   // flag가 true일 경우 뺄셈이므로 빼준다.
                num -= stoi(now);
                // 문제에서 괄호를 쳐주면서 해야 하는데, 그러므로, st[i]가 뺄셈일 경우 flag에 저장을
                // 해주고, 뒤를 모두 빼주면 되는 것이다.
            }
            else{       // flag가 false일 경우 더하기 이므로 int로 바꾸어서 더해줌
                num += stoi(now);
            }
            
            if(st[i] == '-')
                flag = true;
            
            now = "";
            // 기호일 경우 now를 더하거나 빼주었으므로, 초기화해서 새로 받아준다.
            continue;
            // st[i]가 기호일 경우는 밑처럼 더해주지 않고, continue로 그냥 넘어감
        }
        
        now += st[i];
        // 기호나 끝이 아닐 경우 숫자를 now에 더해줌
        // string으로 넣어주어야 자리수 맞춰서 넣어주므로 맞음
    }
    
    cout << num;
    
    return 0;
}

// 뺄셈 이후마다 괄호를 치면 빼는게 커지므로 최소가 된다.
// 왜냐하면 연산자가 같은 것이 연속으로 나올 수가 없기에 -가 한번 나오면 모두 뒤는 -로 해서 해주면 되는 것..
// 조건을 잘 읽어보면 풀만할 쉬운 문제였다.

// 문자열 파싱을 c++로 하는 것은 아직 불편하고 어려워서 전에 푼 풀이를 솔직히 보았다.
// 언능 다 풀고 문자열로 넘어가서 많이 풀어봐야겠다..
// 근데 막상 풀어보니 문자열 문제는 크게 아니었던 거 같아서 겁먹지 않고 하는 것이 중요할듯

