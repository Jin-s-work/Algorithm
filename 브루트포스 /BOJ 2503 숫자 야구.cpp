
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


bool check[1001];
int num, strike, ball;
int strike_num, ball_num, ans;
string st, one, two;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    memset(check, true, sizeof(check));
    
    for(int i=123;i<1000;i++){
        st = to_string(i);
        
        if(st[0] == st[1] || st[0] == st[2] || st[1] == st[2])
            check[i] = false;
        
        if(st[0] - '0' == 0 || st[1] - '0' == 0 || st[2] - '0' == 0)
            check[i] = false;
        
        // 제일 먼저 123부터 999까지 st에 string으로 넣어준 다음
        // 각각 하나라도 같은 수가 있을 경우에 false로 해주고
        // 하나라도 0이 나올 경우에도 false로 해준다.
        
        // 왜냐하면 1-9 중 서로 다른 숫자 3개로 구성되어있어야 하며.
        // 0도 없어야 하는데, 123-999까지 완전탐색을 하는 경우에는 있기에 이들을 false로 제거해준다.
    }
    
    for(int i=0;i<n;i++){
        cin >> num >> strike >> ball;
        
        one = to_string(num);
        // one에는 처음인 질문한 세 자리수를 string으로 넣어주고,
        
        for(int j=123;j<1000;j++){
            strike_num = 0;
            ball_num = 0;
            // strike와 ball의 개수를 세준다.
            // j에 대해서
            
            if(check[j]){       // j가 하나라도 같은 수가 있거나 하나라도 0일 경우에
                two = to_string(j);
                // 여기서는 123~999 중 각 숫자를 넣어준다.
                
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        if(k == l && one[k] == two[l])
                            strike_num++;
                        // 선택한 숫자와 찾는 범위에서의
                        // 숫자의 인덱스 위치가 같을 경우에다가 숫자도 같을 경우는 스트라이크
                        
                        if(k != l && one[k] == two[l])
                            ball_num++;
                        // 선택한 숫자와 찾는 범위에서의
                        // 숫자의 인덱스 범위는 다르지만 숫자가 같을 경우는 볼이다.
                    }
                }
                
                if(strike_num != strike || ball_num != ball)
                    check[j] = false;
                // 여기서 인덱스를 오타로 쳐서 계속 틀렸었다.
                
                // strike_num과 ball_num도 각각 다를 경우 false로 해준다.
                // 즉 여기서 strike와 ball 숫자가 같은 숫자만 남게 된다.
            }
        }
        
    }
    
    for(int i=123;i<1000;i++){
        if(check[i])
            ans++;
    }
    // check가 참인 마지막 부분만 남겨 수를 세준다.
    
    cout << ans;
    
    return 0;
}


// 완전탐색의 기본적인 문제라고 하는데, 제대로 못 풀어서 참조하고 풀었다.
// 사소한 조건들을 파악하여 제대로 처리해주어야 한다.
