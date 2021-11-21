
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


void rev(stack<char> & s){
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    // stack이 없어질때까지 s를 출력하고, pop해줌
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    string st;
    
    getline(cin,st);
    // 그냥 cin으로 받으면 띄어쓰기 못 받으므로, getline으로 받아야 띄어쓰기도 받는다.
    
    bool check = false;
    stack<char>s;
    
    for(char c : st){
        if(c == '<'){               // <가 시작되면 stack에 있는 문자를 모두 출력하고
            rev(s);                 // < 상태이므로 true로 해준다.
            check = true;
            cout << c;              // <도 출력
        }
        else if(c == '>'){          // >가 나오면 끝났으므로, false로 해주고, >도 출력
            check = false;
            cout << c;
        }
        else if(c == ' '){          // 빈 칸이 나오면 빈칸 전까지 문자를 스택에서 빼주고
            rev(s);
            cout << c;              // 빈 칸도 출력
        }
        else if(check)              // 아직 <인 경우로 그냥 출력해준다.
            cout << c;
        else{
            s.push(c);              // 일반 문자는 그냥 stack에 push해주어서 쓴다.
        }
    }
    
    rev(s);                         // 남아있는 스택 모두 출력하기
    cout << '\n';
    
    
    return 0;

}


// 전에 자료구조를 풀었을 때 처럼 <> ()가 나오면 왠만하면 stack으로 풀면 조은듯..?
// 물론 여기서는 <>보다는 문자열을 거꾸로 하기 위하여 스택에 넣고 빼긴 했다.
