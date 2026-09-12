# include "PmergeMe.hpp"

int main(int _argCount, char **_argVector) {
    if (_argCount == 1) {
        std::cerr << "Error" << endl;
        return (1);
    }
    try {
        PmergeMe obj(_argVector, _argCount);
		obj.sort();

    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }  
}