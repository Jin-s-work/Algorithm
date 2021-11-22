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


vector<int>v;

void get(string s){
    
    int m = s.size();
    v.resize(s.size(), 0);  // 모두 0으로 세팅
    // v를 배열로 사용하기 위해서는 사이즈를 할당해주어야 한다.
    
    int idx = 0;
    for(int i=1;i<m;i++){
        while((idx>0) && (s[i] != s[idx])){   // 인덱스가 양수이고, s의 i와 인덱스의 위치가 다를 경우
            idx = v[idx - 1];                 // 그 경우 v[idx-1]로 다시 가서 idx에 넣어준다.
            // while로 이렇게 계속 넣어주는 이유는 최대한 중간을 뛰어넘기 위함이다.
        }
        if(s[i] == s[idx]){     // 같을 경우에는
            idx++;              // 인덱스를 늘려주면서
            v[i] = idx;         // 인덱스의 값을 v에 저장해준다.
            
            // 이 부분에서 맞는 경우를 v에 저장해주면서 앞으로 나아간 뒤,
            // 그 다음 s[idx]가 같지 않은 경우 활용하여 참고하여 거기부터 idx를 다시 진행해나가면 된다.
        }
    }
    // 이러한 식으로 s의 i와 idx가 같을 경우 인덱스를 늘려주면서 그 인덱스를 v에 넣어가면서 해준다.
    // 여기서 접미사 접두사를 찾는 배열 v를 만든다.
}

bool KMP(string s, string p){
    int size_s = s.size();
    int size_p = p.size();
    int idx = 0;
    
    for(int i=0;i<size_s;i++){
        while((idx > 0) && (s[i] != p[idx])){
            idx = v[idx - 1];
        }
        
        if(s[i] == p[idx]){         // s의
            if(idx == size_p-1){         // 인덱스가 맨 마지막에 도달했을 경우 true로 하고 나옴
                return true;
                break;
            }
            else                    // 아직 m-1이 아닐 경우 계속 증가시켜줌
                idx++;
        }
    }
    
    return false;
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s, p;
    cin >> s;
    cin >> p;
    
    get(s);
    cout << KMP(s, p);
    
    
    
    return 0;

}


// 단순비교하면 O(n*m)으로 1억이 넘는다.
// 골드 이상 티어는 항상 시간도 고려해 줘야 함.
// 단순하게 하면 안되고, KMP 알고리즘을 사용하면 O(n+m)이 된다.

// KMP를 저번에 이해하고 지금 다시 보니 제대로 기억 안나는 것을 보면 제대로 자주 해야할듯..!
