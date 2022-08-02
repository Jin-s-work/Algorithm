
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


char st[11][11];
vector<int>v;
int num;

bool check(int num){
    int sum = 0;
    for(int i=num;i>=0;i--){
        sum += v[i];            // 벡터 이므로 num - 0으로 확인을 해야 순서대로 되는 것이다.
        
        if(st[i][num] == '+' && sum <= 0)
            return false;
        if(st[i][num] == '-' && sum >= 0)
            return false;
        if(st[i][num] == '0' && sum != 0)
            return false;
    }
    // 각각 부호와 다르면 false를 해주고
    // 다르지 않다면 마지막에 true를 해준다.
    return true;
}

void DFS(int num){
    if(num == n){           // 마지막에 num이 n이 되면 모든 수를 출력하고 끝내줌
        for(int i=0;i<v.size();i++){
            cout << v[i] << " ";
        }
        exit(0);
    }
    
    for(int i=-10;i<=10;i++){       // -10 부터 10까지
        v.push_back(i);
        
        if(check(num))      // check(num)의 경우를 만족하면 다음 num+1로의 DFS를 해준다.
            DFS(num + 1);
        // num번째 숫자가 모든 조건을 만족하면 num+1로 간다.
        
        v.pop_back();
        // 아니면 그냥 pop
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    string s;
    cin >> s;
    
    int num = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            st[i][j] = s[num++];
        }   // num을 증가시켜 주면서 st[i][j]에 각각 넣어준다.
            // 즉 char가 아닌 string으로 모두를 받아서 하나씩 for문으로 넣어주는 것
    }
    
    DFS(0);
    // 0부터 시작한다.
    
    
    return 0;
}


// n개 주어지고 둘째는 1-n합 만큼 문자열 수
// 규현이가 종이에 수를 n개 쓰고 가능한 모든 구간의 합을 구한 것을 행렬로 표현

// S[i][j]는 A[i]부터 A[j]까지 합이 0보다 크면 +, 0이면 0, 0보다 작으면 -이다.

// -+0+ +++ -- +

// -+0+
//  +++
//   --
//    +

// -2 5 -3 1 은 위를 만족한다.
// n번째 숫자는 s[n][n]의 부호를 만족하면서, n번째 숫자 + n-1번재 숫자는 s[n][n-1]의 부호를 만족
// n번째 숫자부터 x번째 숫자까지 합이 모두 각각 s[n][x]의 부호를 만족하면 n번째 숫자 사용 가능하다.

// n번재 숫자를 DFS로 n번째마다 가능한 모든 경우를 탐색한다.


