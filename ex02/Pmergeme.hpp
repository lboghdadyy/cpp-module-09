# ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <cstddef>
# include <deque>
# include <iostream>
# include <algorithm>
#include <utility>

using std::deque;
using std::pair;
using std::make_pair;
using std::cout;
using std::endl;

class Pmergeme
{
    deque<int>  seq;
    bool            strugler = false;
    int             strugler_vall;
    public:
        Pmergeme();
        Pmergeme(char **input, size_t size);
        Pmergeme(const Pmergeme& other);
        Pmergeme& operator=(const Pmergeme& other);
        ~Pmergeme();
        void    sort(char **input, size_t size);
        void    swapPairs(int index, int pair, size_t pairSize);
        void    insert(int index, int size, deque<int> &temp);
        void    getBigelem(void);
        void    FordJohnson(deque<int> &seq);
        void    extractChains(deque<pair<int, int>> pairs, deque<int> &winners, deque<int> &losers);
        deque<pair<int, int>>    makepairs(deque<int> seq, int &strug);
        void    insertLosers(deque<int> &winners, deque<int> losers);
};

Pmergeme::Pmergeme(){
}


void swap(int &first, int &second) {
    int temp = first;
    first = second;
    second = temp;
}

deque<pair<int, int>>   Pmergeme::makepairs(deque<int> seq, int &strug) {
    deque<pair<int, int>> pairs;
    for (size_t i = 0; i + 1 < seq.size(); i+=2) {
        int big = seq[i], small = seq[i + 1];
        if (big < small)
            swap(big, small);
        pair<int, int> p = make_pair(small, big);
        pairs.push_back(p);
    }
    if (seq.size() % 2 != 0) {
        strug = *(--seq.end());
    }
    return (pairs);
}

deque<int> insertingOrder(size_t size) {
    deque<int> order;

    int j1 = 1;
    int j2 = 0;

    order.push_back(1);

    while (order.size() < size)
    {
        int jacob = j1 + 2 * j2;
		cout << jacob << endl;
        for (int i = jacob; i > j1; --i) {
            order.push_back(i);
        }
        j2 = j1;
        j1 = jacob;
    }
    cout << endl;
    return (order);
}

void    Pmergeme::insertLosers(deque<int> &winners, deque<int> losers) {
	if (losers.empty())
		return ;
    deque<int>::iterator it = std::lower_bound(winners.begin(), winners.end(), losers[0]);
    deque<int>  jacobbb;
    winners.insert(it, losers[0]);
    if (losers.size() == 1) {
        return ;
    }
    jacobbb = insertingOrder(losers.size());
	for (auto &a : jacobbb)
		cout << a << " ";
    cout << "order size = " << jacobbb.size() << " losers size = " << losers.size() << endl;
    for (size_t i = 0; i < jacobbb.size(); i++) {

        if (static_cast<size_t>(jacobbb[i]) >= losers.size())
        {
            cout << "here\n";
            continue;
        }
        deque<int>::iterator itt = std::lower_bound(winners.begin(), winners.end(), losers[jacobbb[i]]);
        winners.insert(itt, losers[jacobbb[i]]);
        cout << "done " <<  losers[jacobbb[i]] << " " << static_cast<size_t>(jacobbb[i]) << endl;
        
    }
}

void Pmergeme::FordJohnson(deque<int> &seq)
{
	int struggeler = -1;
    cout << "seq = " << seq.size() << endl;
    if (seq.size() <= 1)
        return ;
    deque<pair<int, int>> pairs;
    deque<int> winners;
    deque<int> losers;
    pairs = makepairs(seq, struggeler);
    for (deque<pair<int, int>>::iterator it = pairs.begin(); it != pairs.end(); it++) {
        winners.push_back(it->second);
        losers.push_back(it->first);
    }
    if (struggeler != -1) {
        losers.push_back(strugler_vall);
    }
    FordJohnson(winners);
    insertLosers(winners, losers);
    seq.swap(winners);
}


Pmergeme::Pmergeme(char **input, size_t size) : strugler(false)
{
    for (size_t _index = 1; _index < size; _index++) {
        long ll = strtod(input[_index], NULL);
        if (ll <= 0 || ll > 2147483647)
            throw (std::runtime_error("Error"));
        else
            seq.push_back(ll);
    }
    FordJohnson(seq);
    for (auto &a : seq)
        cout << a << ' ';
    cout << endl;        
}

Pmergeme::Pmergeme(const Pmergeme& other){
    this->seq = other.seq;
}

Pmergeme& Pmergeme::operator=(const Pmergeme &obj){
    this->seq = obj.seq;
    this->strugler = false;
    return (*this);
}

Pmergeme::~Pmergeme(){

}

# endif