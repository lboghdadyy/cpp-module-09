# include "BitcoinExchange.hpp"

int main(int _argCount, char **_argVector)
{	
	if (_argCount != 2)
	{
		std::cout << "Usage : <Excutable> <Filename.txt>" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange obj;
		obj.proccedsTheExchange(_argVector[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}