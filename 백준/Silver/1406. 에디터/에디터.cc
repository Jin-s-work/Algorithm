
#include<iostream>
#include<unordered_map>
#include<string>
#include<list>

using namespace std;

int main(int argc, char** argv)
{
	
    string st = "";
    string ans = "";
    cin >> st;

    list<char> link(st.begin(), st.end());
    auto cursor = link.end();
    // 리스트에서 커서 위치를 가리키는 바놉ㄱ자
    // 리스트의 마지막 문자 다음 위치

    int m;
    cin >> m;

    // 명령어의 개수 : 500000
    for(int i=0;i<m;i++){
        char command, plus;
        cin >> command;

        if(command == 'L'){
            if(cursor != link.begin())
                cursor--;
                // 커서를 왼쪽으로 한칸 이동
        }
        else if(command == 'D'){
            if(cursor != link.end())
                cursor++;
        }
        else if(command == 'B'){
            if(cursor != link.begin()){
                cursor--;
                cursor = link.erase(cursor);
            }
        }
        else if(command == 'P'){
            cin >> plus;
            link.insert(cursor, plus);
        }

        // 문장이 처음에는 문장의 맨 뒤에 위치하고 있다.
        // L : 커서를 왼쪽으로 한 칸 옮김
        // D : 커서를 오른족으로 한칸 옮김
        // B : 커서 왼쪽에 있는 문자를 삭제함
        // P $ : $라는 문자를 커서 왼쪽에 추가함
    }

    for(cursor = link.begin();cursor != link.end(); cursor++){
        cout << *cursor;
    }


	
	return 0;
}