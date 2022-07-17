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
#include <sstream>

// control i
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


void find(string s, string t){
    
    if(s == t){
        cout << 1 << '\n';
        exit(0);
    }
    
    if(s.length() > t.length())
        return;
    // 길이 넘으면 리턴으로 멈추기
    
    if(t[t.length() - 1] == 'A'){
        string tmp = t;
        tmp.erase(tmp.length() - 1);
        find(s, tmp);
    }
    // 이렇게 재귀적으로 찾아 밑에랑 안겹치게 한다.
    
    if(t[0] == 'B'){
        string tmp = t;
        reverse(tmp.begin(), tmp.end());
        tmp.erase(tmp.length() - 1);
        find(s, tmp);
    }
    
    
    // 처음에 if 와 else if 로 묶어 실수했다. (근데 처음에는 그냥 if 두개로 시작하긴 했었음)
    // 둘다 만족하는 경우 어떠한 것에 의해 변경되었는지 알 수 없기 때문이다.
    // 처음에는 while문을 통하여 계속 돌게 하였으나, 하고자 했던 재귀 함수를 해보는 게 나을 거라 판단
    
    // 확실히 많이 풀면 익숙해져서 풀 수 있을 듯 더 양치기 하자
    
    
}



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    string s, t;
    cin >> s >> t;
    
    // 거꾸로 가야 한다.
    
    find(s, t);
    
    cout << 0 << '\n';
    
    
    
    return 0;

}

