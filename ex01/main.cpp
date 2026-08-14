# include "RPN.hpp"

int main(int _argc, char **_argv) {
    if (_argc != 2) {
        cerr << "Error" << endl;
        return (1);
    }
    try {
        RPN _obj;
        _obj.calculateExpression(_argv[1]);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}