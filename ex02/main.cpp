# include "Pmergeme.hpp"

int main(int _argCount, char **_argVector) {
    if (_argCount == 1) {
        std::cerr << "Error" << endl;
        return (1);
    }
    try {
        Pmergeme obj(_argVector, _argCount);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }  
}