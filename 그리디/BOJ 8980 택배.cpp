
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

struct input{
    int from;
    int to;
    int num;
};

input arr[10001];
int truck[10001] = {0};
int ans = 0;

bool cmp(input a, input b){
    if(a.to < b.to)         // 뒤에 오는 게 도착 번호가 더 나중이면 true
        return true;
    else if(a.to == b.to)
        if(a.from < b.from)     // 같을 경우 -> 도착지->출발지 순으로 확인한다.
            return true;        // 도착은 같고, 뒤에 오는게 더 나중에 출발하면 true
    
    // 여기에서 도착지 -> 출발지 순으로 오름차순을 해야한다.
    // (출발지 -> 도착지 순으로 하면 틀림)
    
    return false;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int c;
    cin >> n >> c;
    
    cin >> m;
    
    for(int i=0;i<m;i++){
        cin >> arr[i].from >> arr[i].to >> arr[i].num;
    }
    
    sort(arr, arr + m, cmp);
    // 입력 받아서 오름차순으로 정렬한다. (위에서 정의한 대로)
    
    for(int i=0;i<m;i++){
        int Max = 0;
        for(int j=arr[i].from;j<arr[i].to;j++){     // 그 번호에 맞는 arr에서
            Max = max(truck[j], Max);
            // 각각 장소에서의 수용량을 해서 최대를 구해본다.
        }
        // 보내는 곳에서 받는 곳까지 최대 수용량을 저장한다.
        // 박스 얼만큼 넣을 수 있는지 확인
        // truck은 즉, 해당 위치에 박스를 적재했는지 표시해준다.
        
        int cnt = min(arr[i].num, c - Max);
        // 각각 보내는 양과 한계에서 박스 넣을 수 있는 만큼을 빼준 나머지를 비교해 최소로 한다.
        // 최소의 남은 양만큼을 더해주므로, c - Max가 된다.
        ans += cnt;
        
        for(int j=arr[i].from;j<arr[i].to;j++){
            truck[j] += cnt;
        }
        // 이동되면서 최대 수용량만큼 공간을 할당해주어햐 한다.
        // 트럭의 수용량에 최소의 박스를 넣어준다.
        
    }
    
    cout << ans;
    
    return 0;
}



// pair로 할지 vector로 할지 고민하다가 구조체로 풀이하였다.
// 조건이 많아서 복잡했다.
