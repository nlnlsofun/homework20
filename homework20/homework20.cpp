#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(string num1, string num2) {
    int len1 = num1.size(), len2 = num2.size();
    if (len1 > len2) {
        num2 = string(len1 - len2, '0') + num2;
    }
    else {
        num1 = string(len2 - len1, '0') + num1;
    }

    int carry = 0;
    string result = "";
    for (int i = num1.size() - 1; i >= 0; i--) {
        int sum = num1[i] - '0' + num2[i] - '0' + carry;
        result += to_string(sum % 10);
        carry = sum / 10;
    }
    if (carry > 0) {
        result += to_string(carry);
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string num1, num2;
        cin >> num1 >> num2;
        cout << add(num1, num2) << endl;
    }
    return 0;
}
