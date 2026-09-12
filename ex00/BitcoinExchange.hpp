# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <map>
# include <fstream>
# include <algorithm>
# include <climits>

using std::string;
using std::cout;
using std::stringstream;


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
		void	checkDate(string &_date);
		void	checkVal(string &_val);
		void	proccedsTheExchange(const char *_inputfile);
};


# endif