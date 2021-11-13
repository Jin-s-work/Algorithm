
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
set<string>st;
// 중복을 제거 해주려면 set을 사용하여야 한다.

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n >> k;
    // k장을 선택
    
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    sort(v.begin(), v.end());
    // 벡터에 넣고, 정렬해준다.
    
    do{
        string s;
        
        for(int i=0;i<k;i++){
            s += to_string(v[i]);
            // k번 만큼만 넣어줌
        }
        // 매번 스트링을 만들어서, v를 각각 string으로 바꾸어서 더해준다.
        
        st.insert(s);
        // 1 1 2 2 12
        // 11 12 21 112 121 122 212
        // set은 중복이 안되므로, 넣어도 중복이면 size 개수가 안세어진다.
    
    }while(next_permutation(v.begin(), v.end()));
    // 계속 반복하며 섞으면서 해줌
    
    cout << st.size();
    // 중복이 없는 string의 개수
    
    
    return 0;
}




