# ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <iostream>
# include <algorithm>

using std::deque;
using std::pair;
using std::make_pair;
using std::cout;
using std::endl;

typedef struct s_block {
    deque<int>  block;
    int         bigget;
} t_block;

class Pmergeme
{
    deque<int>                             seq;
    deque<int>                             biggerElements;
    int                                    left;
    deque<pair<int, int> >                 pairs;
    deque<deque<pair<int, int>>::iterator> order;
    public:
        Pmergeme();
        Pmergeme(char **input, size_t size);
        Pmergeme(const Pmergeme& other);
        Pmergeme& operator=(const Pmergeme& other);
        ~Pmergeme();
        void    sort(char **input, size_t size);
        void    swapPairs(int index, int pair, size_t pairSize);
        void    insert(int index, int size, deque<int> &temp);
        void    makepairs(void);
        void    getBigelem(void);
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
    for (deque<pair<int, int>>::iterator it = pairs.begin(); it != pairs.end(); it++) {
        biggerElements.push_back(it->second);
        order.push_back(it);
    }
    deque<t_block> blocks;
    for (deque<int>::iterator it = biggerElements.begin(); it != biggerElements.end(); it++)

}

void    Pmergeme::makepairs(void) {
    for (size_t i = 0; i + 1 < seq.size(); i+=2)
        pairs.push_back(std::make_pair(std::min(seq[i], seq[i + 1]), std::max(seq[i], seq[i + 1])));
    for (auto &a : pairs)
        cout << a.first << " " << a.second << endl;
    getBigelem();
}

Pmergeme::Pmergeme(char **input, size_t size)
{
    if (size % 2 == 0) {
        left = strtod(input[size - 1], NULL);
        cout << left << endl;
        if (left <= 0 || left > 2147483647)
            throw (std::runtime_error("Error"));
        size--;
    }
    for (size_t _index = 1; _index < size; _index++) {
        long ll = strtod(input[_index], NULL);
        if (ll <= 0 || ll > 2147483647)
            throw (std::runtime_error("Error"));
        else
            seq.push_back(ll);
    }
    cout << seq.size() << endl;
    makepairs();
    // swapPairs(0, 1, 2);
}

Pmergeme::Pmergeme(const Pmergeme& other){
    this->seq = other.seq;
}

Pmergeme& Pmergeme::operator=(const Pmergeme &obj){
    *this = obj;
    return (*this);
}

Pmergeme::~Pmergeme(){

}

# endif