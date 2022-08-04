#include <iostream>
#include <unordered_map>

using namespace std;

int main() {

    // input
    size_t n;
    cin >> n;

    // solution
    unordered_map<size_t, size_t> remainder_division_in_count_rem_div;
    for (size_t i = 0; i < n; ++i) {
        size_t a_i;
        cin >> a_i;
        remainder_division_in_count_rem_div[a_i % 200] += 1;
    }

    size_t ans = 0;
    for (const auto& [key, a_i] : remainder_division_in_count_rem_div) {
        ans += a_i * (a_i - 1) / 2;
    }

    // output
    cout << ans;


    return 0;
}
