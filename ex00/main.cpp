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



void	checkDate(std::string &_date)
{
	std::string a = "XXXX-XX-XX";
	for (std::string::iterator it = _date.begin(), _it = a.begin();
		it != _date.end();
		it++, _it++)
	{
		if ((*_it == 'X' && !std::isdigit(*it)) || (*_it != 'X' && *_it != *it))
			throw (std::runtime_error("invalid date format"));
	}
}

void	checkVal(std::string &_val)
{
	bool	prec = false;

	for (std::string::iterator it = _val.begin();
		it != _val.end();
		it++)
	{
		if (*it == '.' && !prec)
			prec = true;
		else if (!std::isdigit(*it))
			throw (std::runtime_error("invalid btc price"));
	}
}

template	<typename T1, typename T2>
void	filltheMap(std::map<T1, T2> &_map)
{
	std::ifstream		_file("data.csv");
	std::string			input;
	std::string			date;
	std::string			val;

	if (!_file.is_open())
		throw (std::runtime_error("cannot open data.csv"));
	while (std::getline(_file, input))
	{
		if (date.empty())
		{
			date = "not";
			continue;
		}
		std::stringstream	a(input);
		std::getline(a, date, ',');
		std::getline(a, val, ',');
		if (std::getline(a, val, ','))
			throw (std::runtime_error("Invalid format"));
		(checkDate(date), checkVal(val));
		_map[date] = std::stod(val);
	}
	(void)_map;
}

template <typename T1, typename T2>
void	fillInput(std::map<T1, T2> &_inputTxt, const char *_inputfile)
{
	std::ifstream	_inpt(_inputfile);
	std::string		line;
	std::string		date;
	std::string		coins;
	(void)_inputTxt;
	
	if (!_inpt.is_open())
	{
		std::string ex = "cannot open a file with the name ";
		ex += _inputfile;
		throw (std::runtime_error(ex.c_str()));
	}
	std::getline(_inpt, line);
	while (std::getline(_inpt, line))
	{
		std::stringstream	p(line);
		(1) && (std::getline(p, date, '|'), std::getline(p, coins, '|'));
		date = date.substr(0, date.size() - 1);
		coins = coins.substr(1, coins.size() - 1);
		std::cout << date << " " << coins << '\n';
	}
}

int main(int _argCount, char **_argVector)
{	
	std::string						_name;
	std::map<std::string, double>	_dataBase;
	std::map<std::string, int>		_inputTxt;

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