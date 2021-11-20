
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




int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s, k;
    cin >> s >> k;
    string st;
    
    
    for(int i=0;i<s.length();i++){
        if(s[i] >= '0' && s[i] <= '9')
            continue;
        st.push_back(s[i]);
        // 문자열도 벡터처럼 push_back한다.
    }
    
    
    if(st.find(k) == string::npos)
        cout << "0" << '\n';
    else
        cout << "1" << '\n';
    
    
    return 0;

}

// 처음에는 s.find를 사용하여 인덱스가 증가할 경우 num을 증가시키면서 했는데 안됏다..
// 될거 같은디..? 그래서 그냥 숫자들을 제외하고 새로운 string에 push해주어서 k와 같을 경우 1을 출력하게 해줌
