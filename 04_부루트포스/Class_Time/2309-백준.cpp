//2309 - �ϰ� ������ (Bronze1/ ���Ʈ����, ����)
#include <iostream>
#include <vector>
#include <algorithm>  //sort() �Լ��� ����ϱ� ���� ���� 

using namespace std;

const int CNT = 9; //�������� ���� 9�� ���� 

void select(vector<int>& arr) { //9�� �� 2���� ���ڸ� ã�� �����ϴ� select �Լ� 
    int sum = 0;
    for (int i = 0; i < CNT; i++) {
        sum += arr[i];
    }

    for (int i = 0; i < CNT - 1; i++) {  //ù ��° ���ڼ���
        for (int j = i + 1; j < CNT; j++) {  //�� ��° ���� ���� (i ������ ����)
            if (sum - (arr[i] + arr[j]) == 100) { //sum(9�� ������ ����)-(arr[i]+arr[j]) == 100 �� ��� --> ������ 7�� ������ ��!
                //vector.erase() : ������ ������ ��ҵ��� ������ �� ĭ�� �̵���Ŵ(i,j�� x��° �ڸ���.)
                arr.erase(arr.begin() + j); //j���� ����
                arr.erase(arr.begin() + i); //i���� ����
                return;  //select() �Լ��� �����ϴ� ���� (return 0;�� main �Լ�������)
            }
        }
    }
}

int main() {
    vector<int> arr(CNT);
    for (int i = 0; i < CNT; i++) { //9���� ���ڸ� �Է¹���
        cin >> arr[i];
    }

    //(sort(����,��)), arr.begin() : ������ ù ��° ������ ��ġ, arr.end() : ������ ���� ���� ���� ��ġ
    select(arr);
    sort(arr.begin(), arr.end()); //�������� �Է�

    //for-each ������ ����Ͽ� ���� arr�� ��� ���Ҹ� ���
    for (auto it : arr) {
        cout << it << endl;
    }

    return 0;
}

