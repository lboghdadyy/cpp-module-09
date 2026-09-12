# include "PmergeMe.hpp"

void	PmergeMe::sort(void) {

	cout << "Before: ";
	for (deque<int>::iterator it = seq.begin(); it != seq.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	FordJohnsonDeque(seq);
	cout << "aftre: ";
	for (deque<int>::iterator it = seq.begin(); it != seq.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	cout << "Before: ";
	for (vector<int>::iterator it = this->seqVector.begin(); it != this->seqVector.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	FordJohnsonVector(seqVector);
	cout << "after: ";
	for (vector<int>::iterator it = this->seqVector.begin(); it != this->seqVector.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

PmergeMe::PmergeMe(){
}

void swap(int &first, int &second) {
    int temp = first;
    first = second;
    second = temp;
}

deque<pair<int, int> >   PmergeMe::makepairsDeque(deque<int> seq, int *strug) {
    deque<pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < seq.size(); i+=2) {
        int big = seq[i], small = seq[i + 1];
        if (big < small)
            swap(big, small);
        pair<int, int> p = make_pair(small, big);
        pairs.push_back(p);
    }
    if (seq.size() % 2 != 0) {
        *strug = *(--seq.end());
    }
    return (pairs);
}

vector<pair<int, int> >   PmergeMe::makepairsVector(vector<int> seq, int *strug) {
    vector<pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < seq.size(); i+=2) {
        int big = seq[i], small = seq[i + 1];
        if (big < small)
            swap(big, small);
        pair<int, int> p = make_pair(small, big);
        pairs.push_back(p);
    }
    if (seq.size() % 2 != 0) {
        *strug = *(--seq.end());
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
        for (int i = jacob; i > j1; --i) {
            order.push_back(i);
        }
        j2 = j1;
        j1 = jacob;
    }
    return (order);
}


vector<int> insertingOrderVector(size_t size) {
	vector<int> order;
    int j1 = 1;
    int j2 = 0;
    order.push_back(1);
    while (order.size() < size)
    {
        int jacob = j1 + 2 * j2;
        for (int i = jacob; i > j1; --i) {
            order.push_back(i);
        }
        j2 = j1;
        j1 = jacob;
    }
    return (order);
}

void    PmergeMe::insertLosersDeque(deque<int> &winners, deque<int> losers) {
	if (losers.empty())
		return ;
    deque<int>::iterator it = std::lower_bound(winners.begin(), winners.end(), losers[0]);
    deque<int>  jacobbb;
    winners.insert(it, losers[0]);
    if (losers.size() == 1) {
        return ;
    }
    jacobbb = insertingOrder(losers.size());
    for (size_t i = 0; i < jacobbb.size(); i++) {
        if (static_cast<size_t>(jacobbb[i]) >= losers.size())
            continue;
        deque<int>::iterator itt = std::lower_bound(winners.begin(), winners.end(), losers[jacobbb[i]]);
		if (itt != winners.end())
        	winners.insert(itt, losers[jacobbb[i]]);        
    }
}

void    PmergeMe::insertLosersVector(vector<int> &winners, vector<int> losers) {
	if (losers.empty())
		return ;
    vector<int>::iterator it = std::lower_bound(winners.begin(), winners.end(), losers[0]);
    vector<int>  jacobbb;
    winners.insert(it, losers[0]);
    if (losers.size() == 1) {
        return ;
    }
    jacobbb = insertingOrderVector(losers.size());
    for (size_t i = 0; i < jacobbb.size(); i++) {
        if (static_cast<size_t>(jacobbb[i]) >= losers.size())
            continue;
        vector<int>::iterator itt = std::lower_bound(winners.begin(), winners.end(), losers[jacobbb[i]]);
		if (itt != winners.end())
        	winners.insert(itt, losers[jacobbb[i]]);        
    }
}

void PmergeMe::                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           FordJohnsonDeque(deque<int> &sequence)
{
	int struggeler = -1;
    if (sequence.size() <= 1)
		return ;
	deque<pair<int, int> > pairs;
    deque<int> winners;
    deque<int> losers;
    pairs = makepairsDeque(sequence, &struggeler);
    for (deque<pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
		losers.push_back(it->first);
        winners.push_back(it->second);
    }
    if (struggeler != -1) {
        losers.push_back(struggeler);
    }
    FordJohnsonDeque(winners);
    insertLosersDeque(winners, losers);
    sequence.swap(winners);
}

void PmergeMe::FordJohnsonVector(vector<int> &sequence)
{
	int struggeler = -1;
    if (sequence.size() <= 1)
        return ;
    vector<pair<int, int> > pairs;
    vector<int> winners;
    vector<int> losers;
    pairs = makepairsVector(sequence, &struggeler);
    for (vector<pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
		losers.push_back(it->first);
        winners.push_back(it->second);
    }
    if (struggeler != -1) {
        losers.push_back(struggeler);
    }
    FordJohnsonVector(winners);
    insertLosersVector(winners, losers);
    sequence.swap(winners);
}


PmergeMe::PmergeMe(char **input, size_t size) 
{
    for (size_t _index = 1; _index < size; _index++) {
        long ll = strtod(input[_index], NULL);
        if (ll <= 0 || ll > 2147483647)
            throw (std::runtime_error("Error"));
        else {
            seq.push_back(ll);
			seqVector.push_back(ll);
		}
    }       
}

PmergeMe::PmergeMe(const PmergeMe& other){
    this->seq = other.seq;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &obj){
    this->seq = obj.seq;
    return (*this);
}

PmergeMe::~PmergeMe(){

}