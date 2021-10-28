
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


int arr[3];
// 0은 A, 1은 B, 2는 C
bool dp[51][51][51][3][3] = {0,};
// a, b, c, 2일전, 1일전
char ch[51];
string st;


bool check(int a, int b, int c, int two, int one){
    
    if(a == arr[0] && b == arr[1] && c == arr[2])
        return true;
    // a의 수, b의 수, c의 수가 다 맞을 경우
    // 다 같을 경우 true
    
    if(dp[a][b][c][two][one])
        return false;               // true일 경우 false를 리턴해준다.
    dp[a][b][c][two][one] = true;
    // 아닐 경우 true로 해준다.
    
    if(a + 1 <= arr[0]){        // 아직 a에 1을 더해도 arr[0] 이하일 경우
        ch[a + b + c] = 'A';
        if(check(a + 1, b, c, one, 0))  // a의 값을 하나 늘려주고, 전날, 0으로 확인한다.
            return true;
    }
    if(b + 1 <= arr[1]){
        ch[a + b + c] = 'B';
        if(one != 1 && check(a, b + 1, c, one, 1))  // 전날이 1이 아니고,
            return true;        // b를 늘리고, 전날, 1로 확인한다.
    }
    if(c + 1 <= arr[2]){
        ch[a + b + c] = 'C';
        if(two != 2 && one != 2 && check(a, b, c + 1, one, 2))  // 전날과 전전날이 2가 아니고
            return true;        // c를 늘리고, 전날, 2로 확인한다.
    }
    
    
    return false;
    // 기본적으로는 false를 해준다.
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> st;
    
    for(int i=0;i<st.size();i++){
        if(st[i] == 'A')
            arr[0]++;
        else if(st[i] == 'B')
            arr[1]++;
        else
            arr[2]++;
    }
    // A, B, C일 경우 각각 증가시켜줌
    
    if(check(0, 0, 0, -1, -1))          // true일 경우 즉 될 경우 출력 해준다.
        for(int i=0;i<st.size();i++)
            cout << ch[i];
    else                                // false일 경우 -1을 출력해준다.
        cout << "-1";
    
    cout << '\n';
    
    return 0;
}


// A는 매일 출근이 가능하고,
// B는 출근한 다음날은 쉬고,  (BB 불가능)
// C는 출근한 다음날과 다다음날은 쉰다. (CC, CBC 불가능)


// 사실 보고 풀긴했는데 잘은 아직 모르겟다.....
// 어려워....
