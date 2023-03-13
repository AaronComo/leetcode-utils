#ifndef _HEADER_
#define _HEADER_
#include "header.hpp"
#endif

class Utils {
private:
    string _prefix;
    string _suffix;
    string _comma;
    string _str;

    inline void prefix() {
        _str.append(_prefix);
    }

    inline void suffix() {
        _str.append(_suffix);
    }

    inline void comma() {
        _str.append(_comma);
    }

    inline void clear() {
        _str.clear();
    }

public:
    Utils() {
        _prefix = "[";
        _suffix = "]";
        _comma = ", ";
        _str.clear();
    }

    vector<string> input() {
        string input;
        cin >> input;
        input = input.substr(1, input.length() - 2);
        vector<string> data;
        int i = -1, j;
        do {
            input = input.substr(i + 1);
            j = input.find(",");
            data.push_back(input.substr(0, j));
            i = j;
        } while (i != -1);
        return data;
    }

    void input(vector<int>& v) {
        vector<string> data = input();
        for (int i = 0; i < data.size(); i++) {
            v.push_back(stoi(data[i]));
        }
    }
    
    // default type
    void toString(const string& str) {
        _str.append(str);
    }

    // int
    void toString(const int& v) {
        _str.append(to_string(v));
    }

    // container
    template<typename T>
    string toString(const T& v) {
        prefix();
        for (auto it = v.begin(); it != v.end(); ++it) {
            toString(*it);
            if (it != v.end() - 1)
                comma();
        }
        suffix();
        return _str;
    }

    template<typename T>
    void printVertical(const T& v) {
        clear();
        string s = toString(v);
        int i = -0, j = 0;
        do {
            i = s.find(_comma + _prefix);
            if (i != -1) {
                cout << s.substr(j, i + 1) << endl;
                s.erase(0, i + 1);
            }
            else {
                cout << s << endl;
            }
        } while (i != -1);
    }

    template<typename T>
    void print(const T& v) {
        clear();
        cout << toString(v) << endl;
    }
};

// int main(int argc, char* argv[]) {
//     vector<int> a(4,5);
//     vector< vector<int> > b(3, a);
//     vector<int> c,d;
//     for (int i = 1; i < 6; i++)
//         c.push_back((i));
//     b.push_back(c);
//     for (int i = 4; i < 6; i++)
//         d.push_back((i));
//     b.push_back(d);
//     Utils util = Utils();
//     cout << util.toString(b) << endl;
//     util.print(b);
//     util.printVertical(b);
//     return 0;
// }
