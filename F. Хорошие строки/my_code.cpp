#include<iostream>
#include<string>

using namespace std;

// solution
string removeDuplicates(const string& str) {
    string ans = "";

    for (const char it : str) {

        if (!ans.empty() && abs(ans.back() - it) == abs('A' - 'a')) {
            ans.pop_back();
        }
        else {
            ans.push_back(it);
        }

    }
    return ans;
}


int main() {
    // input
    string str;
    cin >> str;

    // output
    cout << removeDuplicates(str);
}
