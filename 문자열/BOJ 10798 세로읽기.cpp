
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
    
    string s[6];
    for(int i=0;i<5;i++){
        getline(cin, s[i]);      // 엔터가 나올 때까지를 받아서 s[i]에 저장한다.
    }
    
    
    for(int i=0;i<15;i++){       // 최대의 개수가 작으므로 그냥 해주고
        for(int j=0;j<5;j++){
            if(i<s[j].size())    // i가 s[5까지]의 크기보다 작을 경우 s[j][i]를 출력한다.
                cout << s[j][i];
        }
    }       // i와 j의 순서를 바꾸면 안된다. 이런 식으로 해주어야 한다.
    
    
    return 0;

}

// 문자열 아직 익숙하지는 않지만 많은 문제를 풀어보면 될듯
