#include<iostream>
#include<algorithm> // max
#include<vector> // insert
#include<iterator>
#include<numeric> // accumulate

using namespace std;

// solution
int max_sum_length_k(const vector<size_t>& good_numbers, int n, int k) {

    int res = accumulate(good_numbers.begin(), good_numbers.begin() + k, 0);

    int curr_sum = res;
    for (size_t i = k; i < n; ++i) {
        curr_sum += good_numbers[i] - good_numbers[i - k];
        res = max(res, curr_sum);
    }

    return res;
}

int main() {

    // input
    size_t n, k;
    cin >> n >> k;
    vector<size_t> numbers(n);
    for (auto& now : numbers) {
        cin >> now;
    }

    // solution
    vector<size_t> good_numbers = { numbers.begin(),numbers.begin() + k };
    good_numbers.insert(good_numbers.begin(), numbers.end() - k, numbers.end());

    // output
    cout << max_sum_length_k(good_numbers, 2 * k, k);

    return 0;
}
