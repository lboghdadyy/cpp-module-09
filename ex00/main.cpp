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





template	<typename T1, typename T2>


void	check_format(std::string &__input)
{
	size_t pos = __input.find(" | ", 0);
	if (pos == std::string::npos)
		throw (std::runtime_error("Invalid format"));
	if (__input.find(" | ", pos + 1) != std::string::npos)
		throw (std::runtime_error("Invalid format"));
}

template <typename T1, typename T2>


int main(int _argCount, char **_argVector)
{	
	std::string						_name;
	

	if (_argCount != 2)
	{
		std::cout << "Usage : <Excutable> <Filename.txt>" << std::endl;
		return (1);
	}
	_name = _argVector[1];
	try
	{
		filltheMap(_dataBase);
		fillInput(_inputTxt, _argVector[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}