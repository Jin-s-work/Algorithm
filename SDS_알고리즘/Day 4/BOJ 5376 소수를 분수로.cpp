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
#include <unordered_map>
#include <set>

// control i
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
ll n,m,k;
int l,r,t;
int h;


ll gcd(ll a, ll b){
    while(b){
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void circulate(string st){
    int sizes = st.size();
    ll up = 0LL;
    
    // 0. 뒤에만 보므로 2부터 해준다.
    int idx = 2;
    while(1){
        if(idx == sizes)        // idx를 증가시키다가 size와 idx가 같아지면 끝
            break;
        if(st[idx] == '(')      // 만약 (가 나오면 멈춘다.
            break;
        up = up * 10 + (st[idx] - '0');
        idx++;                  // 분자는 10을 곱해주고 idx에 맞는 수를 넣어준다.
    }                           // string이므로 -'0'을 해서 넣어줌
    
    int num1 = idx - 2;     // 들어온 수 중 0.을 제외한 나머지 문자열의 수
    int num2 = 0;
    
    if(idx != sizes){       // idx와 크기가 다를 경우
        ll tmp = up;        // 분자는 tmp에 저장해줌
        
        while(1){
            idx++;
            
            if(st[idx] == ')')      // )가 나오면 break
                break;
            up = up * 10 + (st[idx] - '0');
            // idx를 )가 나오기 전까지 증가시켜줌
            
            num2++;
            // num2를 그만큼 세준다.
        }
        
        if(up != tmp)       // ()안에 있는 수 까지를 한 분자랑 tmp가 다를 경우 전의 분자만큼 한 번 빼준다.
            up -= tmp;
        // 전체 - 비순환소수
    }
    
    ll down = 0LL;
    
    while(num2--){                  // 위에서 ()안의 수만큼
        down = down * 10 + 9;       // 분모는 10곱해주고 9를 더해준다.
    }
        if(down == 0LL)
            down = 1LL;             // 분모가 0LL일 경우 1LL로 갱신한다.
        
        while(num1--)               // 비순환 소수 자리수만큼 분모 뒤에 0을 채운다.
            down *= 10;
        
        ll div = gcd(up, down);
        
        cout << up / div << '/' << down / div << '\n';
        // 기약분수 여야 하므로, 최대공약수를 구해 나누어 준다.
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> t;
    string s;
    
    while(t--){
        
        cin >> s;
        circulate(s);
        
    }
    
    
    
    

    return 0;

}


// 생각하기 쉽지 않아서 참고함... 수학과 맞나
