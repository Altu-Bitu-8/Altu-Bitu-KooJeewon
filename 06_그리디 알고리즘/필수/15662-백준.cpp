//����15662 (Gold5/����,�ùķ��̼�)
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;

//vector<string> li;
//vector<pair<int, int>> stack;
//vector<int> visited;

//void check_rotation(int current_num, int current_dir)
//{
//    if (current_num - 1 >= 0 && visited[current_num - 1] == 0)
//    {
//        if (li[current_num][6] != li[current_num - 1][2]) { // �´�� �ִ� ���� ���� �ٸ� ������ üũ
//            stack.push_back(make_pair(current_num - 1, current_dir * -1));
//            visited[current_num - 1] = 1;
//            check_rotation(current_num - 1, current_dir * -1);
//        }
//    }
//    if (current_num + 1 < li.size() && visited[current_num + 1] == 0){
//        if (li[current_num][2] != li[current_num + 1][6]){ // �´�� �ִ� ���� ���� �ٸ� ������ üũ
//            stack.push_back(make_pair(current_num + 1, current_dir * -1));
//            visited[current_num + 1] = 1;
//            check_rotation(current_num + 1, current_dir * -1);
//        }
//    }
//}

//int main(){
//    int t;
//    int k;
//    cin >> t; // ��Ϲ����� ���� T �Է�
//
//    li.resize(t); // ��Ϲ��� ������ŭ resize
//    for (int i = 0; i < t; ++i)
//        cin >> li[i]; // ��Ϲ��� ���� �Է�
//
//    cin >> k; // ȸ�� Ƚ�� K �Է�

	  // k�� ���鼭 ȸ���� �� �ִ����� ���� üũ
//    for (int i = 0; i < k; ++i) { 
//        int num, direction;

		  // ���� �Է� (1�̸� �ð� ����, -1�̸� �ݽð� ����)
//        cin >> num >> direction; 

//        stack.clear();
//        stack.push_back(make_pair(num - 1, direction));
//        visited.assign(t, 0); // t����ŭ 0�� �ʱ�ȭ
//        visited[num - 1] = 1;
//        check_rotation(num - 1, direction);
//
//        while (!stack.empty()){
//            pair<int, int> top = stack.back();
//            stack.pop_back();

//			  // ������ �� ��Ϲ����� �ε���
//            int tmp_num = top.first; 
//			  // ���� ����
//            int tmp_dir = top.second; 

//            if (tmp_dir == 1){ // �ð�������� ������
//                li[tmp_num] = li[tmp_num].back() + li[tmp_num].substr(0, 7);
//            } else{			 //�ݽð�������� ������
//                li[tmp_num] = li[tmp_num].substr(1) + li[tmp_num][0];
//            }
//        }
//    }

//        int cnt = 0;
//        for (int i = 0; i < t; ++i){
//            if (li[i][0] == '1'){
//                cnt++;
//            }
//        }
//
//        cout << cnt << endl;
//
//        return 0;
//    }
//}
