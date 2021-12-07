

#include <string>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    int x = 5;
    int y = 5;
    
    int num = 0;
    int check[11][11][11][11];
    
    for(int i=0;i<dirs.length();i++){
        
        // -5,-5 ~ 5,5 가 범위이므로, 0,0 - 10,10 으로 생각해서 해준다.
        
        if(dirs[i] == 'L'){     // 왼쪽
            if(x > 0){
                if(check[x][y][x-1][y] != 1){
                    // x가 0보다 크고, 왼쪽으로 갈 경우가 1이 아닐때
                    check[x][y][x-1][y] = 1;
                    check[x-1][y][x][y] = 1;
                    num++;
                }
                x--;
                // x를 줄여준다.
            }
        }
        else if(dirs[i] == 'R'){        // 오른쪽
           if(x < 10){
               if(check[x][y][x+1][y] != 1){
                   check[x][y][x+1][y] = 1;
                   check[x+1][y][x][y] = 1;
                   num++;
               }
               x++;
           }
        }
        else if(dirs[i] == 'U'){        // 위
            if(y < 10){
                if(check[x][y][x][y+1] != 1){
                    check[x][y][x][y+1] = 1;
                    check[x][y+1][x][y] = 1;
                    num++;
                }
                y++;
            }
        }
        else if(dirs[i] == 'D'){        // 아래
            if(y > 0){
                if(check[x][y][x][y-1] != 1){
                    check[x][y][x][y-1] = 1;
                    check[x][y-1][x][y] = 1;
                    num++;
                }
                y--;
            }
        }
        
        
    }
    
    
    
    return num;
}

// 방문함을 체크해주기 위해서 [][][][] 네개의 배열을 사용해 준다.
// 길 자체 방문하면 중복이므로, 양방향으로 체크해주어야 한다.

// 깊게 생각해보면 할 만한 적당한 문제..













