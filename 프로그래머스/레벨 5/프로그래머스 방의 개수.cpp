#include <string>
#include <vector>
#include <map>

using namespace std;

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};
vector<bool>check;

// 그냥 똑같은 곳을 한번 더 방문하면 증가시켜준 것인 줄 알았는데,
// 동시에 간선이 기존에 만들어진 적 없는 간선이어야 함도 필요했다.. 그냥 했다가는 틀릴뻔

// 거기다가 중간에서 만날 경우도 도형이 생길 수가 있어 이도 고려해야 했다.
// 여기서 고려할 부분은 이동할 경우에는 한칸씩만 이동이 가능하므로 (0.5, 0.5)와 같을 때가 오류인데
// 이 때문에 한번 이동할 경우 2칸씩 이동한다고 생각해주면 정리가 가능하다.

int solution(vector<int> arrows) {
    int answer = 0;
    
    // map으로 key, value 두개를 한 쌍으로 관리할 수가 이따.
    // 즉 해당 key값이 어떤 value를 가지고 있는지 찾을 수가 있다.
    
    map<pair<int, int>, bool> nodecheck;
    // key 값을 pair로 하여서 하나의 정점의 정보를 넣어주었는데
    // x좌표, y좌표를 쌍으로 넣어주었다.
    
    map<pair<pair<int, int>, pair<int, int>>, bool> edgecheck;
    // 간선을 관리할 경우에는 이 key 값을 2개의 pair에서 한번에 하게 하엿다.
    // 간선은 한개의 정점에서 한개로 이동 하고, 이는 각각 쌍으로 존재하기 때문이다.
    
    // 따라서 pair, bool 로 방문하였는지 check도 해주었다.
    
    int x = 0, y = 0;
    nodecheck[{x, y}] = true;
    // 처음 간선은 true
    
    for(int i=0;i<arrows.size();i++){
        int move = arrows[i];
        for(int j=0;j<2;j++){       // 소수점일 경우를 대비에 2배로 해준다.
            int nx = x + dx[move];
            int ny = y + dy[move];
            
            if(nodecheck[{nx, ny}] == true && edgecheck[{{x, y}, {nx, ny}}] == false){      // node가 true이고, 간선이 이동 된 경우가 없을때
                edgecheck[{{x, y}, {nx, ny}}] = true;
                edgecheck[{{nx, ny}, {x, y}}] = true;
                // 각각 x,y와 nx, ny를 양방향 true로 해주고
                answer++;
                x = nx;
                y = ny;
                // answer를 늘려준 뒤에 nx,ny를 다시 x,y로 한다.
                continue;
            }
            
            nodecheck[{nx, ny}] = true;
            edgecheck[{{x, y}, {nx, ny}}] = true;
            edgecheck[{{nx, ny}, {x, y}}] = true;
            x = nx;
            y = ny;
            // 다 진행하면 방문한 경우인 nx,ny를 true로
            // x,y nx,ny 를 각각 트루로 해주고 x,y로 해줌
        }
    }
    
    
    
    
    return answer;
}
