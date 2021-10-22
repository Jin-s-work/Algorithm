
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
int h;


int ans;
string st[51];
bool check[26];

void counting(int a, int num){
    // num이 k일 경우 즉 모두 배웠을 경우에
    if(num == k){
        int tmp = 0;
        for(int i=0;i<n;i++){
            bool flag = 1;
            
            // 배우지 않은 알파벳이 있으르 경우 배울 수 없는 단어
            for(int j=0;j<st[i].length();j++){
                if(!check[st[i][j] - 'a']){
                    flag = 0;       // a를 빼준 즉, st[i][j]가 false일 경우 flag도 false로
                    break;          // 하고 break
                }
            }
                if(flag)        // flag가 참일 경우 tmp를 증가시켜준다.
                    tmp++;
            }
            ans = max(ans, tmp);        // 0-n까지 해보고 최대를 넣어줌
            return;
        
    }
    
    for(int l=a;l<26;l++){
        if(!check[l]){
            check[l] = true;
            counting(l, num + 1);       // l에 관해서 num을 증가시키면서 다 해봄
            check[l] = false;
        }
    }
    // 아직 k개를 배우지 않은 경우 하나하나 해본다.
    
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    
    // anta와 tica 포함
    if(k < 5){
        cout << "0" << '\n';
        return 0;
    }
    // 아닌 경우 전부 가능
    else if(k == 26){
        cout << n << '\n';
        return 0;
    }
    
    k -= 5;
    for(int i=0;i<n;i++){
        cin >> st[i];
        
        st[i] = st[i].substr(4, st[i].length());
        // anta
        
        for(int j=0;j<4;j++){
            st[i].pop_back();
        }
        // tica
    }
    
    check['a'-'a'] = true;
    check['c'-'a'] = true;
    check['i'-'a'] = true;
    check['n'-'a'] = true;
    check['t'-'a'] = true;
    // a, c, i, n, t를 무조건 포함해준다.

    counting(0,0);
    // a를 0, num도 0부터 해줌
    cout << ans;
    
    
    return 0;
}


// anta와 tica는 무조건 포함이므로, a, c, i, n, t는 무조건 포함되기에 k가 5미만이라면 불가능하다.
// 접두사 anta와 접미사로 tica가 무조건 포함되므로, 입력받을 때 제거해 주어야 한다.
// 재귀를 사용해야 하며 a,c,i,n,t는 포함되어있다고 마킹 하고 시작해야 한다.

