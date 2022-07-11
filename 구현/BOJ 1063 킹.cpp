#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;

int map[8][8];
// r, l, b, t, rt, lt, rb, lb
int dx[8] = {0, 0, +1, -1, -1, -1, +1, +1};
int dy[8] = {+1, -1, 0, 0, +1, -1, +1, -1};
char inputKy, inputSy;
int inputKx, inputSx, n;
vector<string> moves;
int main() {
    scanf("%c%d %c%d %d", &inputKy, &inputKx, &inputSy, &inputSx, &n);
    int kx = 8- inputKx; int ky = inputKy - 'A';
    int sx = 8 - inputSx; int sy = inputSy - 'A';

    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        moves.push_back(str);
    }
    //이동시키기
    for (int m = 0; m < n; m++) {
        string move = moves[m];
        int i = 0;
        if (move == "R") {

        }
        else if (move == "L") {
            i += 1;
        }
        else if (move == "B") {
            i += 2;
        }
        else if (move == "T") {
            i += 3;
        }
        else if (move == "RT") {
            i += 4;
        }
        else if (move == "LT") {
            i += 5;
        }
        else if (move == "RB") {
            i += 6;
        }
        else {
            i += 7;
        }
        int nx = kx + dx[i];
        int ny = ky + dy[i];
        
        //king을 옮겨보고나서 못 옮길 상황이면 건너뛰기
        if (nx < 0 || nx > 7 || ny < 0 || ny > 7 ) {
            continue;
        }
        //king을 옮긴 뒤 보니까 돌이랑 같이 있다면?
        if (nx == sx && ny == sy) {
            int nsx = sx + dx[i];
            int nsy = sy + dy[i];
            //돌을 옮겻더니 밖으로 나간다면 건너뛰기
            if (nsx < 0 || nsx >7 || nsy < 0 || nsy >7) {
                continue;
            }
            else {
                //돌 옮기기
                sx = nsx; sy = nsy;
            }
        }
        //king과 돌 모두 건너뛰어지지 않았다면 king 옮기기
        kx = nx; ky = ny;
    }
    printf("%c%d\n", 'A' + ky, 8 - kx);
    printf("%c%d", 'A' + sy, 8 - sx);
    return 0;
    
   // 내께 도저히 안되서 다른 사람걸로 일단 냄
}



//    이건 왜 안돼지....
//    내가 처음 푼 풀이 ,,, 왜 안돼는지는 모르겠다...

//
//string st1, st2;
//cin >> st1 >> st2 >> n;
//
//
//int kingx = st1[0] - 'A' + 1;
//int kingy = st1[1] - 48;
//int stonex = st2[0] - 'A' + 1;
//int stoney = st2[1] - 48;
//
//for(int i=0;i<n;i++){
//    string move;
//    cin >> move;
//
//    if(move == "R"){        // 오른쪽
//        if(kingx == 8 || (kingx == 7 && stonex == 8))
//            continue;
//
//        if(kingx + 1 == stonex && kingy == stoney){
//            stonex++;
//        }
//        kingx++;
//    }
//    else if(move == "L"){       // 왼쪽
//        if(kingx == 1 || (kingx == 2 && stonex == 1))
//            continue;
//
//        if(kingx - 1 == stonex && kingy == stoney)
//            stonex--;
//        kingx--;
//    }
//    else if(move == "T"){       // 위로
//        if(kingy == 8 || (kingy == 7 && stoney == 8))
//            continue;
//
//        if(kingy + 1 == stoney && kingx == stonex)
//            stoney++;
//        kingy++;
//    }
//    else if(move == "B"){
//        if(kingy == 1 || (kingy == 2 && stoney == 1))
//            continue;
//
//        if(kingy - 1 == stoney && kingx == stonex)
//            stoney--;
//        kingy--;
//    }
//    else if(move == "RT"){  // 오른쪽 위
//        if((kingx == 8 || kingy == 8) || ((kingx == 7 || kingy == 7) && (stonex == kingx + 1 && stoney == kingy + 1)))
//            continue;
//
//        if(kingx + 1 == stonex && kingy + 1 == stoney){
//            stonex++;
//            stoney++;
//        }
//        kingx++;
//        kingy++;
//    }
//    else if(move == "LT"){  // 왼쪽 위
//        if((kingx == 1 || kingy == 8) || ((kingx == 2 || kingy == 7) && (stonex == kingx - 1 && stoney == kingy + 1)))
//            continue;
//
//        if(kingx - 1 == stonex && kingy + 1 == stoney){
//            stonex--;
//            stoney++;
//        }
//        kingx--;
//        kingy++;
//    }
//
//    else if(move == "RB"){  // 오른쪽 아래
//        if((kingx == 8 || kingy == 1) || ((kingx == 7 || kingy == 2) && (stonex == kingx + 1 && stoney == kingy - 1)))
//            continue;
//
//        if(kingx + 1 == stonex && kingy - 1 == stoney){
//            stonex++;
//            stoney--;
//        }
//        kingx++;
//        kingy--;
//    }
//
//    else if(move == "LB"){  // 왼쪽 아래
//        if((kingx == 1 || kingy == 1) || ((kingx == 2 || kingy == 2) && (stonex == kingx - 1 && stoney == kingy - 1)))
//            continue;
//
//        if(kingx - 1 == stonex && kingy - 1 == stoney){
//            stonex--;
//            stoney--;
//        }
//        kingx--;
//        kingy--;
//    }
//
//
//
//}
//
//string ans1, ans2;
//
//ans1 += (char)(kingx + 'A' - 1);
//ans1 += (char)(kingy + '0');
//ans2 += (char)(stonex + 'A' - 1);
//ans2 += (char)(stoney + '0');
//
//cout << ans1 << '\n' << ans2 << '\n';

