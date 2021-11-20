
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
    
    
    string s, t;
    while(cin >> s >> t){
        int idx = 0;
        bool check = false;
        
        for(int i=0;i<t.length();i++){
            if(s[idx] == t[i])
                idx++;
            // idx를 0부터 시작해서 t의 언젠가와 같다면, idx를 증가시키면서 찾아주면 된다. (간단...)
            // 그렇게 계속 이어나가다 s의 길이와 같아지면 true로 하고 끝
            // 안나오면 계속 false이기에 false
            if(idx == s.length()){
                check = true;
                break;
            }
        }
        
        if(check)
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
    
    
    
    
    return 0;

}


// 귀찮게 .find()로 할 필요도 없고, 대문자 소문자로도 안바꾸어도 되나...?
// 열심히 했더니 아니군

// 대문자와 소문자 바꿀 필요 없이 다 같아야 한다.

// 알고보면 간단하게 풀 수 있는 경우가 많아 많이 풀어보자..!
