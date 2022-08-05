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

bool check[201][201][201];
vector<int>v;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    int A, B, C;
    cin >> A >> B >> C;
    
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, C});
    
    while(!q.empty()){
        int a = q.front().first.first;
        int b = q.front().first.second;
        int c = q.front().second;
        q.pop();
        
        if(check[a][b][c])
            continue;
        check[a][b][c] = true;
        // 이걸로 중복을 판단해주면서 BFS
        
        if(a == 0)
            v.push_back(c);
        // 처음에 a가 0일 때 c도 가능하므로 v에 넣어줌
        
        // 현재 a에 있는 양 + 현재 b에 있는 양 > B (최대 용량) 인 경우
        // B는 최대용량만큼 가득차게 되고, A에는 현재 a + 현재 b - 최대 용량 만큼 남는다.
        // 아닐 경우에는 A에서 전부 옮겨지므로 A에는 0이 남고, B는 A에 있던 만큼 a + b 가 된다.
        // c는 변화가 없다.
        // A에서 B로
        if(a + b > B)
            q.push({{a + b - B, B}, c});
        else
            q.push({{0, a + b}, c});
        
        
        // A에서 C로
        if(a + c > C)
            q.push({{a + c - C, b}, C});
        else
            q.push({{0, b}, a + c});
        
        // B에서 A로
        if(a + b > A)
            q.push({{A, a + b - A}, c});
        else
            q.push({{a + b, 0}, c});
        
        // B에서 C로
        if(b + c > C)
            q.push({{a, b + c - C}, C});
        else
            q.push({{0, b}, a + c});
        
        // C에서 A로
        if(a + c > A)
            q.push({{A, b}, a + c - A});
        else
            q.push({{a + c, b}, 0});
        
        // C에서 B로
        if(b + c > B)
            q.push({{a, B}, b + c - B});
        else
            q.push({{a, b + c}, 0});
        
        // 대문자의 A,B,C가 들어간 경우에는 한계치만큼 넣어 꽉 차있는 것이다.
    }
    
    sort(v.begin(), v.end());
    
    for(auto k : v){
        cout << k << " ";
    }
    cout << '\n';
    
    
    
    return 0;
    
}
