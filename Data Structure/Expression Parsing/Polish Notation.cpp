#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Variable
{
public:
    Variable(const string& name, double val)
    {
        this->name = name;
        this->val = val;
    }

    inline const string& get_name() const { return name; }
    inline double get_val() const { return val; }
private:
    string name;
    double val;
};

//----------------------------------

double operate(const string& op, istringstream& iss, vector<Variable>& v);
double perform_addition(istringstream& iss, vector<Variable>& v);
double perform_subtraction(istringstream& iss, vector<Variable>& v);
double perform_division(istringstream& iss, vector<Variable>& v);
double perform_multiplication(istringstream& iss, vector<Variable>& v);
void define_new_var(vector<Variable>& v, istringstream& iss);

bool is_number(const string& op)
{
    int char_to_int = op[0];
    if (char_to_int >= 48 && char_to_int <= 57)
        return true;

    return false;
}

void print_var_list(vector<Variable>& v)
{
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        cout << v[i].get_name() << ", " << v[i].get_val() << endl;
    }
    cout << endl;
}

int main()
{
    cout << endl << "LeRPN Programming Language" << endl;

    vector<Variable> v;

    string temp;
    while (cin)
    {
        cout << endl << "> ";

        getline(cin, temp);

        istringstream iss(temp);
        string op;
        iss >> op;

        if (op == "quit")
            break;
        else if (op == "def")
            define_new_var(v, iss);
        else if (op == "show_vars")
            print_var_list(v);
        else
            cout << endl << operate(op, iss, v) << endl;
    }
}

double perform_addition(istringstream& iss, vector<Variable>& v)
{
    string left;
    iss >> left;

    string right;
    iss >> right;

    return operate(left, iss, v) + operate(right, iss, v);
}

double perform_subtraction(istringstream& iss, vector<Variable>& v)
{
    string left;
    iss >> left;

    string right;
    iss >> right;

    return operate(left, iss, v) - operate(right, iss, v);
}

double perform_division(istringstream& iss, vector<Variable>& v)
{
    string left;
    iss >> left;

    string right;
    iss >> right;

    return operate(left, iss, v) / operate(right, iss, v);
}

double perform_multiplication(istringstream& iss, vector<Variable>& v)
{
    string left;
    iss >> left;

    string right;
    iss >> right;

    return operate(left, iss, v) * operate(right, iss, v);
}

double get_variable(const string& op, vector<Variable>& v)
{
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        if (op == v[i].get_name())
            return v[i].get_val();
    }
}

double operate(const string& op, istringstream& iss, vector<Variable>& v)
{
    double value;
    if (op == "+")
        value = perform_addition(iss, v);
    else if (op == "-")
        value = perform_subtraction(iss, v);
    else if (op == "/")
        value = perform_division(iss, v);
    else if(op == "*")
        value = perform_multiplication(iss, v);
    else if (is_number(op))
        value = atof(op.c_str());
    else
        value = get_variable(op, v);

    return value;
}

void define_new_var(vector<Variable>& v, istringstream& iss)
{
    string name;
    iss >> name;

    string temp;
    iss >> temp;

    double value = operate(temp, iss, v);

    v.push_back(Variable(name, value));
}
