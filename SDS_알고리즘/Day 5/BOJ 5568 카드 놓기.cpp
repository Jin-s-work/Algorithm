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

// control i
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


vector<int>v;
set<string>s;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> k;
    
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    sort(v.begin(), v.end());
    // 들어온 v들을 정렬해준 다음에
    
    do{
        string st;
        for(int i=0;i<k;i++){
            st += to_string(v[i]);
            // v를 돌아가면서 st에 모두 더해준다. (순열로)
        }
        
        s.insert(st);
        // set에 넣어서 중복을 제거 해준다.
    }while(next_permutation(v.begin(), v.end()));
    
    cout << s.size();
    
    

    return 0;

}










//
//
//
//
//cin >> n >> k;
//
//priority_queue<int>pq;
//vector<int>v;
//
//for(int i=0;i<n;i++){
//    int a;
//    cin >> a;
//    v.push_back(a);
//}

//
//
