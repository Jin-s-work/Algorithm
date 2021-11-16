
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

stack<int>st;
vector<int>v;
vector<char>c;
int num = 0;


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
        
    for(int i=0;i<n;i++){
        cin >> m;
        v.push_back(m);
        // 각각 입력받은 수를 vector에 넣어준다.
    }
    
    int cnt = 0;
    for(int i=1;i<=n;i++){
        st.push(i);
        c.push_back('+');
        // 각각 i를 1부터 stack에 넣어준다.
        // 그러고 +를 넣어준다.
        
        while(!st.empty()){     // stack이 없어질 때까지
            if(v[cnt] == st.top()){  // 목표하던 v의 cnt(0부터 -- ) 가 stack의 제일 마지막과 같으면
                st.pop();
                c.push_back('-');
                cnt++;
                // stack의 제일 top을 pop해주고, -를 c에 넣어주고, cnt 즉, 인덱스를 하나 증가시켜준다.
            }
            else            // 같지 않을 경우 while문을 break하고 다음 for문을 돌려준다.
                break;
        }
    }
    
    if(st.empty()){
        for(int i=0;i<c.size();i++){
            cout << c[i] << '\n';
        }       // stack이 완전히 없어진 경우 c를 모두 출력해준다.
    }
    else        // stack이 안없어진 경우 no를 출력한다.
        cout << "NO" << '\n';
    
    
    return 0;

}


// 스택은 제일 나중에 들어간 것이 제일 먼저 나오는 구멍이 한개라는 것을 이해시켜주려는 문제

// 처음엔 문제가 이해가 안되었는데, 전의 풀이와 해설을 보니 이해가 갔다..
// 좀 더 고민해보았다면, 나도 풀 수 있었을 거 같은데 머리가 먼가 안돌아가서 참고하였다..
