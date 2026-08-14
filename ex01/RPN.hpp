# ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <algorithm>

# define NUMBER 42
# define OPERATOR 43

using std::stack;
using std::stringstream;
using std::string;
using std::cout;
using std::cerr;
using std::endl;

class RPN
{
	private:
		stack<int>	myStack;
		long		total;
	public:
		RPN();
		RPN(const RPN& other);
		RPN(const char *input);
		RPN& operator=(const RPN& other);
		~RPN();
		void	calculateExpression(const char *input);
};

RPN::RPN(){
}

RPN::RPN(const RPN& other){
	this->myStack = other.myStack;
}

RPN& RPN::operator=(const RPN &obj){
	*this = obj;
	return (*this);
}

RPN::~RPN(){
}

void	RPN::calculateExpression(const char *input)
{
	stringstream	ss(input);
	string			word;
	long			res = 0;
	long			top = 0;

	while (ss >> word) {
		if (word.size() == 1 && isdigit(word[0]))
			this->myStack.push(atoi(word.c_str()));
		else if (word.size() == 1) {
			if (myStack.size() < 2)
				throw (std::runtime_error("Error"));
			res = myStack.top();
			myStack.pop();
			top = myStack.top();
			myStack.pop();
			switch (word[0]) {
				case '*':
					res *= top;
					break;
				case '+':
					res += top;
					break;
				case '-':
					top -= res;
					res = top;
					break;
				case '/':
					top /= res;
					res = top;
					break;
				default:
					throw (std::runtime_error("Error"));
					break;
			}
			myStack.push(res);
		}
		else
			throw (std::runtime_error("Error"));
	}
	if (myStack.empty())
		throw (std::runtime_error("Error"));
	cout << myStack.top() << endl;
}

RPN::RPN(const char *input) {
	calculateExpression(input);
}

# endif