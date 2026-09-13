# ifndef PmergeMe_HPP
# define PmergeMe_HPP

# include <vector>
# include <deque>
# include <iostream>
# include <algorithm>
# include <sys/time.h>
# include <iomanip>

using std::deque;
using std::pair;
using std::make_pair;
using std::cout;
using std::endl;
using std::vector;

class PmergeMe
{
    deque<int>  seq;
	vector<int>	seqVector;
    public:
        PmergeMe();
        PmergeMe(char **input, size_t size);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
		void	sort(void);
        void 	FordJohnsonVector(vector<int> &sequence);
		void	FordJohnsonDeque(deque<int> &sequence);
        deque<pair<int, int> >    makepairsDeque(deque<int> seq, int *strug);
        vector<pair<int, int> >    makepairsVector(vector<int> seq, int *strug);
        void    insertLosersDeque(deque<int> &winners, deque<int> losers);
        void    insertLosersVector(vector<int> &winners, vector<int> losers);
};

# endif