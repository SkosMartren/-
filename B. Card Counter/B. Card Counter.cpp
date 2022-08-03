#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;

int maxSum(const vector<size_t>& v, int n, int k) {

    int res = 0;
    for (int i = 0; i < k; ++i){
        res += v[i];
        //cout << "not error!";
    }

    int curr_sum = res;
    for (int i = k; i < n; ++i) {
        curr_sum += v[i] - v[i - k];
        //cout << " error!";
        res = max(res, curr_sum);
        //cout << "NOT!";
    }
    
    return res;
}

int main() {

    size_t n, k;
    cin >> n >> k;
    vector<size_t> test(n);
    for (auto& now : test) {
        cin >> now;
    }

    vector<size_t> answer = { test.begin(),test.begin() + k };
    answer.insert( answer.begin(), test.end() - k, test.end());
    //copy(answer.begin(), answer.end(),ostream_iterator<size_t>(cout, " "));
    cout << maxSum(answer, 2*k,k);

    return 0;
}
