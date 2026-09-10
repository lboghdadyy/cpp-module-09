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

typedef struct s_block {
    deque<int>      vals;
    int             biggest;
    bool            has;
    s_block(int i, int i1, bool h) {
        if (!h) {
            biggest = i;
            vals.push_back(i);
            has = false;
            return ;
        }
        if (i > i1) {
            biggest = i;
            vals.push_back(i1);
            vals.push_back(i);
        }
        else {
            biggest = i1;
            vals.push_back(i);
            vals.push_back(i1);
        }
    }
} t_block;

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
        deque<pair<int, int>>    makepairs(deque<int> seq);
        void    insertLosers(deque<int> &winners, deque<int> losers);
};

// void    Pmergeme::insert(int index, int size, deque<int> &temp) {
//     for (int _i = index; _i - index < size; _i++)
//         temp.push_back(seq[_i]);
// }

// void    Pmergeme::swapPairs(int index, int pair, size_t pairSize) {
//     // index = 1
//     // pair = 2
//     // pairsize = 4
//     cout << "before : " << endl;
//     for (auto &a : seq)
//         cout << " [" << a << "] ";
//     cout << endl;
//     size_t size = seq.size();
//     deque<int> temp;
//     for (size_t i = index; i < size; i += pairSize) {
//         if (i + pair < size && seq[i] > seq[i + pair]) {
//             insert(i + 1, pair, temp);
//             insert((i - pair) + 1, pair, temp);
//         }
//         else
//         {
//             insert((i - pair) + 1, pair, temp);
//             if (i + pair < size)
//                 insert(i + 1, pair, temp);
//         }
//     }
//     seq = temp;
//     cout << "after : " << endl;
//     for (auto &a : temp)
//         cout << " [" << a << "] ";
//     cout << endl;
//     if (pairSize * 2 <= seq.size())
//         swapPairs(index + pair, pair * 2, pairSize * 2);
// }

// void Pmergeme::sort(char **input, size_t size) {
// }

Pmergeme::Pmergeme(){
}



void    Pmergeme::getBigelem(void) {
    // for (deque<pair<int, int>>::iterator it = pairs.begin(); it != pairs.end(); it++) {
    //     biggerElements.push_back(it->second);
    //     order.push_back(it);
    // }
    // deque<t_block> blocks;
    // for (deque<int>::iterator it = biggerElements.begin(); it != biggerElements.end(); it++){}
}

void swap(int &first, int &second) {
    int temp = first;
    first = second;
    second = temp;
}

deque<pair<int, int>>   Pmergeme::makepairs(deque<int> seq) {
    deque<pair<int, int>> pairs;
    for (size_t i = 0; i + 1 < seq.size(); i+=2) {
        int big = seq[i], small = seq[i + 1];
        if (big < small)
            swap(big, small);
        pair<int, int> p = make_pair(seq[i], seq[i + 1]);
        pairs.push_back(p);
    }
    // cout << "phase 1" << endl;
    if (seq.size() % 2 != 0) {
        strugler = true;
        strugler_vall = *(--seq.end());
    }
    // cout << "phase 2" << endl;
    return (pairs);
}

// void    Pmergeme::extractChains(deque<pair<int, int>> pairs, deque<int>& main, deque<int>& pending) {
//     // for (auto &a : pairs)
//     //     cout << "big : " << a.first << ' ' << "smaller : " << a.second << endl;
    

    

// }


deque<int> insertingOrder(size_t size) {
    deque<int> order;

    size_t j1 = 1;
    size_t j2 = 1;

    order.push_back(1);

    while (order.size() < size)
    {
        size_t jacob = j1 + (2 * j2);
        cout << j1 + (2 * j2) << endl;
        for (size_t i = jacob; i > j1 && i <= size; --i)
        {
            order.push_back(i);
            
        }
        j2 = j1;
        j1 = jacob;
    }
    for (auto &q : order)
        cout << q << ' ';
    cout << endl;
    return (order);
}

void    Pmergeme::insertLosers(deque<int> &winners, deque<int> losers) {
    deque<int>::iterator it = std::lower_bound(winners.begin(), winners.end(), losers[0]);
    deque<int>  jacobbb;
    winners.insert(it, losers[0]);
    if (losers.size() == 1) {
        return ;
    }
    jacobbb = insertingOrder(losers.size());
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
    // cout << "started" << endl;
    cout << "seq = " << seq.size() << endl;
    if (seq.size() <= 1)
        return ;
    deque<pair<int, int>> pairs;
    deque<int> winners;
    deque<int> losers;
    // cout << "make pairs" << endl;
    pairs = makepairs(seq);
    for (deque<pair<int, int>>::iterator it = pairs.begin(); it != pairs.end(); it++) {
        winners.push_back(it->first);
        losers.push_back(it->second);
    }
    if (this->strugler) {
        losers.push_back(strugler_vall);
        strugler = false;
    }
    // cout << "pairs = " << pairs.size() << endl;
    // cout << "wi nners = " << winners.size() << endl;
    // cout << "losers = " << losers.size() << endl;
    // cout << "fordjhonson" << endl;
    FordJohnson(winners);
    // cout << "insert losers" << endl;
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
    // for (auto &a : seq)
    // {
        //     cout << a.vals[0];
        //     if (a.has)
        //         cout << ", " << a.vals[1] << endl;
        //     else
        //         cout << endl;
        // }
        
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