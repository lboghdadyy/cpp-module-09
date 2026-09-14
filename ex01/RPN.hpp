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
		stack<float>	myStack;
		long		total;
	public:
		RPN();
		RPN(const RPN& other);
		RPN(const char *input);
		RPN& operator=(const RPN& other);
		~RPN();
		void	calculateExpression(const char *input);
};

# endif