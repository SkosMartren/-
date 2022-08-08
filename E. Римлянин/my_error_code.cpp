#include <iostream>
#include <map>
#include <iterator>
#include <algorithm> // count
#include <string> // find

using namespace std;

int convertToArabic(const string& romanNumber) {

    map <char, size_t> Roman_to_Arabic = { {'I',1} ,{'V' , 5 },{'X' , 10}, {'L' , 50},{ 'C' , 100}, {'D' , 500}, {'M' , 1000} };
    size_t ans = Roman_to_Arabic[romanNumber[0]];

    for (size_t i = 1; i < romanNumber.size(); ++i) {


        // CD = D - C, CM = M - C, XL = L - X etc --> ex: ans = XLX = 50 = X + LX = X + XL + X = X + L -2*X + X = L
        if (romanNumber[i - 1] == 'I' && (romanNumber[i] == 'V' || romanNumber[i] == 'X')) {
            ans += Roman_to_Arabic[romanNumber[i]] - Roman_to_Arabic[romanNumber[i - 1]] * 2;
        }

        else  if (romanNumber[i - 1] == 'X' && (romanNumber[i] == 'L' || romanNumber[i] == 'C')) {
            ans += Roman_to_Arabic[romanNumber[i]] - Roman_to_Arabic[romanNumber[i - 1]] * 2;
        }

        else  if (romanNumber[i - 1] == 'C' && (romanNumber[i] == 'D' || romanNumber[i] == 'M')) {
            ans += Roman_to_Arabic[romanNumber[i]] - Roman_to_Arabic[romanNumber[i - 1]] * 2;
        }

        else  if (Roman_to_Arabic[romanNumber[i - 1]] < Roman_to_Arabic[romanNumber[i]]) {
            return -1;
        }

        else {
            ans += Roman_to_Arabic[romanNumber[i]];
        }
    }
    return ans;
}


int main() {
    // input

    string str;

    cin >> str;


    // solution


     // Цифры 'V', 'L' и 'D' нельзя использовать более одного раза во всей записи числа.
    for (const char bad_char : {'V', 'L', 'D'}) {
        if (count(str.cbegin(), str.cend(), bad_char) > 1) {
            cout << -1;
            return 0;
        }
    }

    // Цифры 'I', 'X', 'C' и 'M' нельзя использовать более трех раз подряд
    for (const string& bad_sequence_numbers : { "IIII", "XXXX", "CCCC","MMMM", "IXL", "IXC", "XCD", "XCM","XIIX" }) {
        if (str.find(bad_sequence_numbers) != string::npos) {
            cout << -1;
            return 0;
        }
    }

    cout << convertToArabic(str);
    return 0;
}
