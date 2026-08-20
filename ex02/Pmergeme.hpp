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

// typedef struct s_block {
//     deque<deque<pair<int, int>>::iterator>  block;
//     int                                     bigger;
//     void                                    conBlock(const struct s_block &obj);
//     void                                    fillBigger(void);
// } t_block;

// void    t_block::conBlock(const struct s_block &obj) {
//     for (deque<deque<pair<int, int>>::iterator>::const_iterator it = obj.block.begin(); it != obj.block.end(); it++)
//         this->block.push_back(*it);
// }

// void    t_block::fillBigger(void) {
//     this->bigger = (*(this->block.end() - 1))->second;
//     cout << "this-> bigger = " << (*(this->block.end() - 1))->second  << endl;
// }


template <typename T>
class Pmergeme
{
    T       seq;
    int     leftOver;
    bool    hasIt = false;
    public:
        Pmergeme();
        Pmergeme(char **input, size_t size);
        Pmergeme(const Pmergeme& other);
        Pmergeme& operator=(const Pmergeme& other);
        ~Pmergeme();
        void    sort(char **input, size_t size);
        void    swapPairs(int index, int pair, size_t pairSize);
        void    insert(int index, int size, deque<int> &temp);
        T       makepairs(T seq);
        void    getBigelem(void);
};

template <typename T>
Pmergeme<T>::Pmergeme(){
}


template <typename T1>
T1    Pmergeme<T1>::makepairs(T1 seq) {
    for (size_t i = 0; i + 1 < seq.size(); i+=2)
        pairs.push_back(std::make_pair(std::min(seq[i], seq[i + 1]), std::max(seq[i], seq[i + 1])));
    if (seq.size() % 2 != 0) {
        
    }
}

template <typename T1>
typename T1::iterator    recSort(T1 &seq) {
    
}

template <typename T>
Pmergeme<T>::Pmergeme(char **input, size_t size)
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
    // swapPairs(0, 1, 2);
}
template <typename T>
Pmergeme<T>::Pmergeme(const Pmergeme& other){
    this->seq = other.seq;
}

template <typename T>
Pmergeme<T>& Pmergeme<T>::operator=(const Pmergeme<T> &obj){
    *this = obj;
    return (*this);
}

template <typename T>
Pmergeme<T>::~Pmergeme() {

}

# endif