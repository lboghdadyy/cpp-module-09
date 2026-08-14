# include "BitcoinExchange.hpp"

bool isleapYear(long year) {
	return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

static void badInput(const string &_input)
{
    string message = "Error: bad input => ";

    message += _input;
    throw (std::out_of_range(message));
}

void	BitcoinExchange::checkVal(string &_val) {
	bool	                prec = false;
	std::string::iterator   it = _val.begin();
	double	                val;

	if (*it == '-' || '+')
		it++;
	for (std::string::iterator _it = it;
		_it != _val.end();
		_it++)
	{
		if (*_it == '.' && !prec)
			prec = true;
		else if (!std::isdigit(*_it))
			throw (std::runtime_error("invalid btc price"));
	}
	val = strtod(_val.c_str(), NULL);
	if (val < 0)
		throw (std::out_of_range("Error: not a positive number."));
	if (val > INT_MAX)
		throw (std::out_of_range("Error: too large a number."));
}


void	check_format(string &__input)
{
	size_t pos = __input.find(" | ", 0);

	if (pos == std::string::npos || __input.find(" | ", pos + 1) != std::string::npos)
        badInput(__input);
}

void	BitcoinExchange::checkDate(string &_date)
{
	// vector<int>         months = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	string              a = "XXXX-XX-XX";
	std::stringstream   ss(_date);
	vector<long>        __date;

	if (_date.size() != 10)
		badInput(_date);
	for (std::string::iterator it = _date.begin(), _it = a.begin();
		it != _date.end() || _it != a.end();
		it++, _it++) {
		if ((*_it == 'X' && !std::isdigit(*it)) || (*_it != 'X' && *_it != *it))
            badInput(_date);
	}
	string	word;
	while (getline(ss, word, '-'))
		__date.push_back(strtod(word.c_str(), NULL));
	if (__date[1] != 2 &&  (__date[1] > 12 || __date[1] < 1 || __date[2] > months[__date[1] - 1] || __date[2] < 1))
		badInput(_date);
	if (__date[1] == 2) {
		int end = 28;
		if (isleapYear(__date[0]))
			end = 29;
		if (__date[2] > end)
            badInput(_date);
	}
}

void	BitcoinExchange::proccedsTheExchange(const char *_inputfile)
{
	std::ifstream	_inpt(_inputfile);
	std::string		line;
	std::string		date;
	std::string		coins;
	
	if (!_inpt.is_open()) {
		string ex = "cannot open a file with the name ";
		ex += _inputfile;
		throw (std::runtime_error(ex.c_str()));
	}
	std::getline(_inpt, line);
	while (std::getline(_inpt, line)) {
		try {
			check_format(line);
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
			continue;
		}
		std::stringstream	p(line);
		(1) && (std::getline(p, date, '|'), std::getline(p, coins, '|'));
		date = date.substr(0, date.size() - 1);
		coins = coins.substr(1, coins.size() - 1);
		try {
			(checkDate(date), checkVal(coins));
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
			continue;
		}
		std::map<std::string, float>::iterator it = _dataBase.find(date);
		if (it == _dataBase.end()) {
			it = _dataBase.lower_bound(date);
			if (it != _dataBase.end())
				cout << date << " => " << coins << " = " << it->second * strtod(coins.c_str(), NULL) << std::endl;
		}
		else
			cout << date << " => " << coins << " = " << it->second * strtod(coins.c_str(), NULL) << std::endl;
	}
}

void	BitcoinExchange::filltheMap(void)
{
	std::ifstream		_file("data.csv");
	std::string			input;
	std::string			date;
	std::string			val;

	if (!_file.is_open())
		throw (std::runtime_error("Error: could not open file."));
	while (std::getline(_file, input)) {
		if (date.empty()) {
			date = "not";
			continue;
		}
		std::stringstream	a(input);
		std::getline(a, date, ',');
		std::getline(a, val, ',');
		if (std::getline(a, val, ','))
			throw (std::runtime_error("Invalid format"));
		(checkDate(date), checkVal(val));
		this->_dataBase[date] = std::strtod(val.c_str(), NULL);
	}
}


BitcoinExchange::BitcoinExchange() {
    int arr[] =  {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::vector<int> temp(arr, arr + 12);
    this->months = temp;
	filltheMap();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){
	this->_dataBase = other._dataBase;
    this->_inputTxt = other._inputTxt;

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &obj){
	*this = obj;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){

}