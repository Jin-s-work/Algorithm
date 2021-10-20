
#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstring>
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
int h;

// 1. 현재 쓰는게 꼽혀있을 경우 그냥 넘어간다.
// 2. 다 안태워져있을 경우 현재 제품을 꽂아준다.
// 3. 플러그를 뽑아야 할 경우
// - 남은 동안 멀티탭에 꽂힌 제품을 쓰지 않는 경우 그 제품의 플러그를 뽑는다.
// - 남은 동안 멀티탭에 꽂힌 제품이 모두 쓰인다면 가장 마지막으로 쓰이는 제품의 플러그를 뽑아준다.

int arr[101];
vector<int>v;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int num = 0;
    cin >> n >> k;
    
    for(int i=0;i<k;i++){
        cin >> arr[i];
    }
    
    int flag = 0;       // 지나갈지 안지나갈지 확인하는 체크
    
    for(int i=0;i<k;i++){
        flag = 0;
        for(int j=0;j<v.size();j++){
            if(arr[i] == v[j]){
                flag = 1;
                break;              // 만약 이미 멀티 탭에 있으면 flag를 1로 하고 break한다.
            }
        }
        if(!flag){
            if(v.size() < n)
                v.push_back(arr[i]);        // 다 안채웠을 경우 벡터에 넣어준다.
            else{
                num++;                  // 다 차서 플러그를 하나 빼야할때
                int Max = 0;
                int now = 0;
                bool isend = false;
                
                for(int l=0;l<n;l++){
                    for(int j=i+1;j<k;j++){
                        if(v[l] == arr[j]){
                            // i+1부터 k까지 중 v[l]과 같은 즉 플러그가 있을 경우
                            if(j > Max){        // 가장 마지막에 쓰이는 플러그를 저장해논다.
                                Max = j;        // j가 최대보다 클 경우 그를 갱신하고
                                now = l;        // 위치를 idx에 저장해논다.
                            }
                            break;      // 다 찾아봐주고 break
                        }
                        else if(j == k-1){      // 쓰이지 않는 플러그가 있으면 뽑아서
                            now = l;            // 저장해주고 끝내는 시그널을 준다.
                            isend = true;
                        }
                    }
                    if(isend)               // 뽑았으면 break
                        break;
                }
                v[now] = arr[i];            // v의 now위치에 arr[i]를 넣어준다.
            }
        }
        
    }
    
    cout << num;
    // 바꾼 횟수
    
    return 0;
}

// 1-n은 사용순서

// 사용할 순서대로 전자용품을 탐색한 후
// 먼저 이미 콘센트가 꽂혀 있으면 그냥 그대로 사용한다.

// 만약 콘센트가 꽂혀있지 않는데, 빈 콘센트가 있으면 해당 콘센트에 연결한다.

// 반대로 빈 콘센트가 존재하지 않으면, 기존의 연결된 콘센트 중 하나를 뽑는다.
// 뒤에 쓰는 일이 없을 경우 해당 콘센트를 뽑고, 만약 모두가 이후에 사용되면,
// 그 중에 가장 늦게 사용하는 콘센트를 뽑고, 새로운 제품을 연결시킨다.
