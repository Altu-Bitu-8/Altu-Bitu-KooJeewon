//1063 - ŷ (Silver4, ����, �ùķ��̼�)
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //�Է�
    //kla, kln : ŷ�� �ʱ� ��ġ (ex: kla='D', kln=5)
    //sla, sln : ���� �ʱ� ��ġ (ex: sla='E', sln=5)
    int kln, sln, n;  //n: �̵�Ƚ��
    char kla, sla;
    cin >> kla >> kln >> sla >> sln >> n;


    //����
    while (n--) {
        string com; //com : �̵���� �Է¹���
        cin >> com;
        //mx(�� ����), my(�� ����) ��ǥ ��ȭ ���� 
        int mx = 0, my = 0;

        switch (com[0]) {
        case 'R':
            mx++;
            if (com[1] == 'T') { //RT : ������ �� �밢�� 
                my++;
            }
            else if (com[1] == 'B') { //RB: ������ �Ʒ� �밢�� 
                my--;
            }
            break;
        case 'L':
            mx--;
            if (com[1] == 'T') { //LT: ���� �� �밢��'
                my++;
            }
            else if (com[1] == 'B') { //LB: ���� �� �밢��
                my--;
            }
            break;
        case 'B': //B: �Ʒ��� 
            my--;
            break;
        case 'T': //T: ����
            my++;
            break;
        }

        //��� 
        if (kln + my > 8 || kln + my < 1 || kla + mx > 'H' || kla + mx < 'A') { //ü������ ����� ��� 
            continue;
        }
        if (kln + my == sln && kla + mx == sla) { //ŷ�� �̵��Ϸ��� ��ġ�� ���� ���ٸ� ���� ���� �������� �� ĭ �̵�.
            if (sln + my > 8 || sln + my < 1 || sla + mx > 'H' || sla + mx < 'A') {
                continue; // ���� ü������ ����� �̵� ���
            }
            sln += my;
            sla += mx;
        }
        //�̵��� ��ȿ�ϸ� ŷ�� ��ġ ������Ʈ
        kln += my;
        kla += mx;

    }

    //���� ��� ���
    cout << kla << kln << '\n' << sla << sln;

}
//https://zzaekkii.tistory.com/12 ����