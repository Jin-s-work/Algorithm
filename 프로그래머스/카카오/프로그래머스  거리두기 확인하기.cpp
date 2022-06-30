#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool check;

void DFS(vector<string>&v, int x, int y, int X, int Y, int num){
    if(num == 2)        // 거리가 2이면 끝냄
        return;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // 범위 내에 있고, X가 아닐 경우
        if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && v[nx][ny] != 'X'){
            if(nx == X && ny == Y)   // X,Y는 원래의 인덱스를 담고 있어서
                continue;            // 넘어간 것이 다시 같아지는 경우 continue
            if(v[nx][ny] == 'P'){
                check = false;      // P일 경우 check를 false로 해주고 return한다.
                return;
            }
            DFS(v, nx, ny, X, Y, num + 1);  // num을 증가시키면서 파고들기
        }   // 끝날때 까지 true면 가능한 것이다.
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    // O : 빈 테이블    X : 파티션
    // 거리 2 넘어야 한다. 하지만 파티션일 경우에는 괜찮음

    for(auto v : places){
        bool flag = true;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){       // 5개로 고정이 되있으므로 그냥 5로
                if(v[i][j] == 'P'){     // P일 경우
                    check = true;       // check를 true로 하고
                    DFS(v, i, j, i, j, 0);  // 0과 각자의 인덱스로 들어감
                    if(!check)      // check가 false일 경우 안된다.
                        flag = false;
                }
            }
        }       // 모든 경우를 DFS 해보았을 때 false가 안나오면 되는 것
    if(flag)            // flag가 true일 경우 된다는 것
        answer.push_back(1);
    else
        answer.push_back(0);
        
    }
        // DFS가 P의 위치에서 모든 경우를 찾아보기에 좋은 것 같다.
    
    return answer;
}















