#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int e, n, m, p, q, d, phi;

void findP(int b);

int findD(int a, int b);

int gcd(int a, int b);

string decodeInt(string a);

int rem(int a, int b);

string decryptChar(string a);

int main() {

    string message, decoded;

    cin >> e >> n >> m;

    findP(n);
    phi = (p - 1) * (q - 1);
    if (gcd(e, phi) != 1) {
        cout << "Public key is not valid!";
        return 1;
    }
    d = findD(e, phi);

    cout << p << " " << q << " " << phi << " " << d << endl;
    cin.ignore(256, '\n');
    getline(cin, message);

    decoded = decodeInt(message);
    cout << decoded << endl;
    cout << decryptChar(decoded);
}

void findP(int b) {
    while (b % 2 == 0) {
        b = b / 2;
    }

    for (int i = 3; i <= sqrt(b); i = i + 2) {
        while (b % i == 0) {
            b = b / i;
            p = i;
        }
    }

    if (b > 2)
        q = b;
}

int findD(int a, int b) {
    int k = 1;
    while ((k * b + 1) % a != 0) {
        k++;
    }
    d = (k * b + 1) / a;
    return d;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

string decodeInt(string a) {
    string final;
    int temp = 1;
    vector<int> arr;
    istringstream values(a);

    int add;
    while(values >> add) {
        arr.push_back(add);
    }

    for (int i = 0; i < arr.size(); i++) {
        int _d = d;
        int hold = arr[i];
        while (_d != 0) {
            if (_d % 2 == 1) {
                temp = (temp * hold) % n;
                _d--;
            } else {
                hold = (hold * hold) % n;
                _d /= 2;
            }
        }
        final = final + to_string(temp) + " ";
        temp = 1;
    }

    return final;
}

int rem(int a, int b) {
    int reduced;
    if (a > b) {
        reduced = a % b;
    } else if (a == b) {
        reduced = 1;
    } else {
        reduced = a;
    }
    return reduced;
}

string decryptChar(string a) {

    stringstream s(a);
    istringstream ss(a);
    int input;
    string final = "";
    string chars[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S",
                        "T", "U", "V", "W", "X", "Y", "Z"};
    while (ss >> input) {
        if (input >= 7 && input <= 32) {
            final += chars[input - 7];
        } else if (input == 33) {
            final += " ";
        } else if (input == 34) {
            final += "\"";
        } else if (input == 35) {
            final += ",";
        } else if (input == 36) {
            final += ".";
        } else if (input == 37) {
            final += "\'";
        }
    }
    return final;
}