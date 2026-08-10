# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <vector>
# include <iostream>
# include <sstream>
# include <map>
# include <fstream>

class BitcoinExchange
{
	std::map<std::string, float>	_dataBase;
	std::map<std::string, float>	_inputTxt;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		void	filltheMap(void);
		void	checkDate(std::string &_date);
		void	checkVal(std::string &_val);
		void	proccedsTheExchange(std::map<std::string, float> &_inputTxt, const char *_inputfile);
};

void	BitcoinExchange::checkVal(std::string &_val)
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

void	BitcoinExchange::checkDate(std::string &_date)
{
	std::string a = "XXXX-XX-XX";
	std::stringstream s();
	if (_date.size() != 10)
		throw (std::runtime_error("Input must be in \"Date | Price\" format."));
	for (std::string::iterator it = _date.begin(), _it = a.begin();
		it != _date.end() || _it != a.end();
		it++, _it++)
	{
		if ((*_it == 'X' && !std::isdigit(*it)) || (*_it != 'X' && *_it != *it))
		{
			std::cout << "|" << _date << "|\n";
			throw (std::runtime_error("invalid date format"));
		}
	}
}

void	BitcoinExchange::proccedsTheExchange(std::map<std::string, float> &_inputTxt, const char *_inputfile)
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
		check_format(line);
		std::stringstream	p(line);
		(1) && (std::getline(p, date, '|'), std::getline(p, coins, '|'));
		std::cout << date << '\n';
		date = date.substr(0, date.size() - 1);
		coins = coins.substr(1, coins.size() - 1);
		try
		{
			(checkDate(date), checkVal(coins, value));
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		typename std::map<T1. T2>::iterator a =  _dataBase.find(date);
		if (a == _dataBase.end())
		{
			std::cout << "not found \n";
		}

		// _inputTxt[date] = strtod(value);
	}
}

void	BitcoinExchange::filltheMap(void)
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
		this->_dataBase[date] = std::stod(val);
	}
}


BitcoinExchange::BitcoinExchange(){
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &obj){

}

BitcoinExchange::~BitcoinExchange(){

}
# endif