# include "BitcoinExchange.hpp"

// void	checkFile(std::string &_file)
// {
// 	std::string::iterator	c;
// 	std::string				_extention;
// 	_extention = ".csv";
// 	if (_file.size() <= 4)
// 		throw (std::runtime_error("Invalid file name"));
// 	c = std::find(_file.begin(), _file.end(), '.');
// 	if (c == _file.end())
// 		throw (std::runtime_error("Invalid file name"));
// 	for (std::string::iterator	i = _extention.begin();
// 		c != _file.end();
// 		c++, i++)
// 	{
// 		if (*i != *c)
// 			throw (std::runtime_error("Invalid file name"));
// 	}
// }


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