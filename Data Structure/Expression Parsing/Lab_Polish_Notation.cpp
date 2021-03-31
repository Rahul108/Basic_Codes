#include<bits/stdc++.h>
using namespace std;

void define_var(map<string, int> &v, istringstream& iss) {
    std::string name;
    int value;
    iss >> name >> value;
    v[name] = value;
}

int do_op(char op, int val1, int val2) {
    switch (op) {
        case '+': return val1 + val2;
        case '-': return val1 - val2;
        case '*': return val1 * val2;
        case '/': return val1 / val2;
        default:
            string error("Unknown operator: ");
            error += op;
            throw runtime_error(error);
    }
}

bool isoperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

char getop(istream &is) {
    char ch;
    while (isspace(ch = is.peek()))
        is.get(ch);
    ch = is.peek();
    return ch;
}

int eval(istream &is, map<string, int> const &v) {

    char ch = getop(is);

    if (isoperator(ch)) {
        is.get(ch);
        int val1 = eval(is, v);
        int val2 = eval(is, v);
        return do_op(ch, val1, val2);
    }
    if (isdigit(ch)) {
        int val;
        is >> val;
        return val;
    }

    string var_name;
    is >> var_name;
    map<string, int>::const_iterator p = v.find(var_name);
    if (p==v.end()) {
        string problem("Unknown variable: ");
        problem +=var_name;
        throw runtime_error(problem.c_str());
    }
    return p->second;
}


namespace std {
    ostream &operator<<(ostream &os, pair<string, int> const &v) {
        return os << v.first << ": " << v.second;
    }
}

int main() {
    cout << endl << "LePN Programming Language" << endl;

    map<string, int> v;

    string temp;
    cout << endl << "> ";
    while (getline(cin, temp)) {
        istringstream iss(temp);

        string op;
        iss >> op;

        if (op == "quit")
            break;
        else if (op == "def")
            define_var(v, iss);
        else if (op == "show_vars")
            std::copy(v.begin(), v.end(), ostream_iterator<pair<string, int> >(cout, "\n"));
        else {

            iss.unget();
            cout << endl << eval(iss, v) << endl;
        }
        cout << endl << "> ";
    }
}
