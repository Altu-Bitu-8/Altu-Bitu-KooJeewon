//백준14501 - Silver3(다이나믹 프로그래밍, 부루트포스 알고리즘)
/*
1) 퇴사 전까지 n일 동안, 하루에 한 개의 상담만 가능
2) 상담은 a일이 걸리고, 완료하면 b만큰의 돈을 벌 수 있음 
3) 퇴사 전에 끝낼 수 있는 상담들 둥에서 최대 수익은 ? 
--> vector<ii> li : li[i] = {상담기간, 금액}
--> vector<int> dp(n + 1, 0) : dp[i]는 i일까지 얻을 수 있는 최대금액
--> 

*/
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ii;

void dpBottomUp(vector<int>& dp, vector<ii> li, int n) {
    //i일에 상담을 시작
    //그 상담은 li[i].first일 걸림(즉, 상담은 i+li[i].first에 끝남)
    for (int i = 0; i < n; i++) {
        // 가장빠른 상담일자 잡아주기(dp[j]값 갱신
        for (int j = i + li[i].first; j <= n; j++) { 
            //이익 dp[i]에 오늘 버는 수익 li[i].second가 더 크다면 갱신해주기!
            if (dp[j] < dp[i] + li[i].second) { 
                dp[j] = dp[i] + li[i].second;
            }
        }
    }
}

void dpTopDown(vector<int>& dp, vector<ii> li, int n) {
    for (int i = n - 1; i >= 0; i--) {
        // 상담이 퇴사일을 넘기면
        if (i + li[i].first > n) { 
            dp[i] = dp[i + 1]; // 상담하지 않고 이전 값 유지
        }
        // 상담을 하는 것과 하지 않는 것 중 큰 값을 선택
        else { 
            dp[i] = max(dp[i + 1], li[i].second + dp[i + li[i].first]);
        }
    }
}

int main() {
    //입력
    int n;
    cin >> n;

    //li: 각 날짜마다 상담걸리는 시간과 수익을 저장
    //dp: 동적 계획법용 배열(각 날까지 얻을 수 있는 최대 이익을 저장)
    vector<ii> li; //상담리스트 (기간, 금액)
    vector<int> dp(n + 1, 0); //dp[i] = i일까지의 최대 금액

    
    for (int i = 0; i < n; i++) {
        int a, b;    //a: 걸리는 일 수, b: 얻는 수익 
        cin >> a >> b;
        li.push_back(make_pair(a, b));
    }

    //연산
    dpBottomUp(dp, li, n);

    //출력
    cout << dp[n] << "\n";
    return 0;
}