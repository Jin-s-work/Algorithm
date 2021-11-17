
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

set<string>ans;
// 중복을 피하기 위해서 set에다가 insert해서 넣어준다.
vector<pair<int, int>>v;
string s;
bool c[201];
bool check[201];

void DFS(int num, int ind){
    if(num >= 1){           // 즉 처음에는 0,0으로 들어오므로 건너뛰고, 뒤에를 해준다.
        string str = "";
        for(int i=0;i<s.size();i++){
            if(c[i])
                continue;
            str += s[i];
        }
        ans.insert(str);
    }
    
    for(int i=ind;i<v.size();i++){
        if(check[i])
            continue;
        // true면 continue
        
        check[i] = true;            // check는 그 인덱스에 관해 지났는지 체크
        c[v[i].first] = true;       // st.top()
        c[v[i].second] = true;      // i        즉 인덱스(위치)
        DFS(num + 1, ind + 1);
        check[i] = false;
        c[v[i].first] = false;
        c[v[i].second] = false;
    }
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    stack<char>st;
    
    for(int i=0;i<s.size();i++){
        
        if(s[i] == '('){
            st.push(i);     // (일 경우 그에 따른 숫자를 스택에 넣어줌
        }
        else if(s[i] == ')'){
            v.push_back({st.top(), i});
            st.pop();       // )가 나올 경우 벡터에 st.top과 i를 넣어주고 pop해줌
        }                   // 즉 벡터에 괄호의 숫자와 끝나는 숫자를 넣어주는 것
    }
    
    DFS(0, 0);
    
    for(auto w : ans)
        cout << w << '\n';
    // 모든 w 출력 auto로 하면 편리하다.
    
    return 0;

}

// 3
// 1 2 3 12 13 23 123
// 7

// 4
// 1 2 3 4 12 13 14 23 24 34 123 124 134 234 1234
// 15

// 솔직히 이거 아직 잘 모르겠는데.. 흠...
