
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

bool cmp(pair<ll, ll>p1, pair<ll, ll>p2){
    return p1.first - p1.second < p2.first - p2.second;
}

vector<pair<int, int>>v;
// 입력 받은 것들을 저장
vector<pair<int, int>>vec;
// 새로 넣는 것들


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    v.resize(n);
    
    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0;i<n;i++){
        int a = v[i].first;
        int b = v[i].second;
        
        while(!vec.empty() && vec.back().first + vec.back().second < a - b){
            vec.pop_back();
        }
        // vec가 없어지거나, vec의 back 점에 제일 클 경우가 들어오는 a,b의 제일 작은 점보다 작으면 pop해준다.
        
        if(vec.empty() || abs(vec.back().second - b) > a - vec.back().first)
            vec.push_back(v[i]);
        // vec가 비어있거나, 반지름들의 차의 절대값이 중심의 차보다 클 경우 가능하므로 push
        else{
            cout << "NO";
            return 0;
        }
        
    }
    
    cout << "YES";
    
    
    return 0;

}


// 이해도 잘 안가고,, 무슨 문젠지 모르겠다.. 그냥 참고해서 풀엇심..
