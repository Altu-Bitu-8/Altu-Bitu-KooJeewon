//1063 - 킹 (Silver4, 구현, 시뮬레이션)
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //입력
    //kla, kln : 킹의 초기 위치 (ex: kla='D', kln=5)
    //sla, sln : 돌의 초기 위치 (ex: sla='E', sln=5)
    int kln, sln, n;  //n: 이동횟수
    char kla, sla;
    cin >> kla >> kln >> sla >> sln >> n;


    //연산
    while (n--) {
        string com; //com : 이동명령 입력받음
        cin >> com;
        //mx(열 방향), my(행 방향) 좌표 변화 저장 
        int mx = 0, my = 0;

        switch (com[0]) {
        case 'R':
            mx++;
            if (com[1] == 'T') { //RT : 오른쪽 위 대각선 
                my++;
            }
            else if (com[1] == 'B') { //RB: 오른쪽 아래 대각선 
                my--;
            }
            break;
        case 'L':
            mx--;
            if (com[1] == 'T') { //LT: 왼쪽 위 대각선'
                my++;
            }
            else if (com[1] == 'B') { //LB: 왼쪽 위 대각선
                my--;
            }
            break;
        case 'B': //B: 아래로 
            my--;
            break;
        case 'T': //T: 위로
            my++;
            break;
        }

        //출력 
        if (kln + my > 8 || kln + my < 1 || kla + mx > 'H' || kla + mx < 'A') { //체스판을 벗어나는 경우 
            continue;
        }
        if (kln + my == sln && kla + mx == sla) { //킹이 이동하려는 위치가 돌과 같다면 돌도 같은 방향으로 한 칸 이동.
            if (sln + my > 8 || sln + my < 1 || sla + mx > 'H' || sla + mx < 'A') {
                continue; // 돌이 체스판을 벗어나면 이동 취소
            }
            sln += my;
            sla += mx;
        }
        //이동이 유효하면 킹의 위치 업데이트
        kln += my;
        kla += mx;

    }

    //최종 결과 출력
    cout << kla << kln << '\n' << sla << sln;

}
//https://zzaekkii.tistory.com/12 참조