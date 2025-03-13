//2309 - 일곱 난쟁이 (Bronze1/ 브루트포스, 정렬)
#include <iostream>
#include <vector>
#include <algorithm>  //sort() 함수를 사용하기 위해 포함 

using namespace std;

const int CNT = 9; //난쟁이의 수를 9로 고정 

void select(vector<int>& arr) { //9개 중 2개의 숫자를 찾고 제거하는 select 함수 
    int sum = 0;
    for (int i = 0; i < CNT; i++) {
        sum += arr[i];
    }

    for (int i = 0; i < CNT - 1; i++) {  //첫 번째 숫자선택
        for (int j = i + 1; j < CNT; j++) {  //두 번째 숫자 선택 (i 이후의 값만)
            if (sum - (arr[i] + arr[j]) == 100) { //sum(9개 숫자의 총합)-(arr[i]+arr[j]) == 100 인 경우 --> 나머지 7개 숫자의 합!
                //vector.erase() : 삭제한 이후의 요소들을 앞으로 한 칸씩 이동시킴(i,j는 x번째 자리임.)
                arr.erase(arr.begin() + j); //j부터 삭제
                arr.erase(arr.begin() + i); //i부터 삭제
                return;  //select() 함수를 종료하는 역할 (return 0;은 main 함수에서만)
            }
        }
    }
}

int main() {
    vector<int> arr(CNT);
    for (int i = 0; i < CNT; i++) { //9개의 숫자를 입력받음
        cin >> arr[i];
    }

    //(sort(시작,끝)), arr.begin() : 벡터의 첫 번째 원소의 위치, arr.end() : 벧터의 마비맏 원소 다음 위치
    select(arr);
    sort(arr.begin(), arr.end()); //오름차순 입력

    //for-each 문법을 사용하여 벡터 arr의 모든 원소를 출력
    for (auto it : arr) {
        cout << it << endl;
    }

    return 0;
}

