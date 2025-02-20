#include <iostream>
#include <algorithm>
using namespace std;

std::string serial[51];

bool userSort(std::string_view a, std::string_view b) {
    if (a.size() != b.size()) return a.size() < b.size();
    else {
        int sumA{}; int sumB{};
        for (int i = 0; i < a.size(); ++i) {
            if ('0' <= a[i] && a[i] <= '9') sumA += a[i] - '0';
        }
        for (int i = 0; i < b.size(); ++i) {
            if ('0' <= b[i] && b[i] <= '9') sumB += b[i] - '0';
        }
        if (sumA != sumB) return sumA < sumB;
        return a < b;
    }
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    for (int i = 0; i < N; ++i)
        std::cin >> serial[i];

    std::sort(serial, serial + N, userSort);

    for (int i = 0; i < N; ++i)
        std::cout << serial[i] << '\n';


    return 0;
}



