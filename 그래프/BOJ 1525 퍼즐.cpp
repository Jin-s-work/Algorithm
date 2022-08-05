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

// control i처
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

string start, last;
set<string>check;


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    last = "123456780";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int a;
            cin >> a;
            char c = a + '0';
            start = start + c;
            // 숫자들을 받아서 문자열로 변환한후 start에 더해 문자들을 받아준다.
        }
    }
    // 예를 들어 예제1은 103425786 으로 받는다.
    
    queue<pair<string, int>> q;
    q.push({start, 0});
    check.insert(start);
    // check의 set에 start를 넣어준다. set은 중복을 제거해주므로 중복은 나타나지 않는다.
    
    while(!q.empty()){
        string str = q.front().first;
        int num = q.front().second;
        q.pop();
        
        if(str == last){
            cout << num << '\n';
            return 0;
        }
        
        int zero = str.find('0');
        int x = zero / 3;
        int y = zero % 3;
        // 처음에 숫자들을 문자들로 9개 받아주기에 일단 먼저 0의 인덱스를 찾고
        // zero / 3 의 경우에는 3으로 나눈 몫을 뜻하며 이는 x축 값을 나타내고
        // zero % 3 의 경우에는 3으로 나눈 나머지를 뜻하며 이는 y축 값을 뜻한다.
        // 0이 만약 2행 2열에 있을 경우 다섯번째이므로 인덱스는 4이다 이 경우 x는 1 y는 1로 x축, y축이다.
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
                continue;
            
            string next = str;
            swap(next[x * 3 + y], next[nx * 3 + ny]);
            // next의 x축, y축에 대한 인덱스를 가진 숫자와 다음으로 움직인 곳에 대하여 바꾼다.
            
            if(check.find(next) == check.end()){
                check.insert(next);
                q.push({next, num + 1});
            }
            // 아직 next가 check에 없을 경우에 next를 넣어주고 queue에도 next, num+1을 넣어준다.
        }
        
    }
    
    cout << "-1" << '\n';
    
    
    return 0;
    
}

// BFS로 풀 수 있긴 했지만 안보고 set을 생각해내고 하는 부분은 절대 쉽지 않았을 것이다...
// 골드 2도 버겨운 실력...

