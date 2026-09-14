# include "PmergeMe.hpp"

double getTime() {
    struct timeval tv;
    if (gettimeofday(&tv, NULL) == -1) {
        std::cerr << "gettimeofday failed" << std::endl;
        return 0.0;
    }
    return (tv.tv_sec * 1000000.0 + tv.tv_usec);
}

void	PmergeMe::sort(void) {
	double vectTime;
	double duqueTime;
	cout << "Before: ";
	for (deque<int>::iterator it = seq.begin(); it != seq.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	double start = getTime();
	FordJohnsonDeque(this->seq);
	double end = getTime();
	duqueTime = end - start;
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
	start = getTime();
	FordJohnsonVector(seqVector);
	end = getTime();
	vectTime = end - start;
	cout << "after: ";
	for (vector<int>::iterator it = this->seqVector.begin(); it != this->seqVector.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	cout << "Time to process a range of " << seq.size() << " elements with std::deque : " << std::fixed << std::setprecision(5) << duqueTime << " us" << endl;
	cout << "Time to process a range of " << seq.size() << " elements with std::vector : "  << std::fixed << std::setprecision(5) << vectTime << " us" << endl;
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

    int prev = 1;
    int prevPrev = 0;

    order.push_back(1);

    while (order.size() < size)
    {
        int jacob = prev + 2 * prevPrev;
        for (int i = jacob; i > prev; --i) {
			if (static_cast<size_t>(i) <= size)
            	order.push_back(i);
        }
        prevPrev = prev;
        prev = jacob;
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
            if (static_cast<size_t>(i) <= size)
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
	winners.insert(winners.begin(), losers[0]);
	deque<int> jacobbb = insertingOrder(losers.size());
    for (size_t i = 0; i < jacobbb.size(); i++)  {
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
    vector<int>  jacobbb;
    winners.insert(winners.begin(), losers[0]);
    jacobbb = insertingOrderVector(losers.size());
    for (size_t i = 0; i < jacobbb.size(); i++) {
        if (static_cast<size_t>(jacobbb[i]) >= losers.size())
            continue;
        vector<int>::iterator itt = std::lower_bound(winners.begin(), winners.end(), losers[jacobbb[i]]);
		winners.insert(itt, losers[jacobbb[i]]);
    }
}

void	mergeSortVector(vector<pair<int, int> > &pairs, int low, int mid, int high) {
	int	lowPartLen = mid - low + 1, highPartlen = high - mid;
	vector<pair<int, int> > lowPart(lowPartLen), highPart(highPartlen);
	
	for (int i = low, j = 0; j < lowPartLen ; i++, j++)
		lowPart[j] = pairs[i];
	for (int i = mid + 1, j = 0; j < highPartlen; i++, j++)
		highPart[j] = pairs[i];
	int lIndex = 0, hIndex = 0, index = low;
	while (lIndex < lowPartLen && hIndex < highPartlen) {
		if (lowPart[lIndex].second > highPart[hIndex].second) {
			pairs[index] = highPart[hIndex];
			hIndex++;
		}
		else {
			pairs[index] = lowPart[lIndex];
			lIndex++;
		}
		index++; 
	}
	while (lIndex < lowPartLen)
		pairs[index++] = lowPart[lIndex++];
	while (hIndex < highPartlen)
		pairs[index++] = highPart[hIndex++];	
}

void	mergeSort(deque<pair<int, int> > &pairs, int low, int mid, int high) {
	int	lowPartLen = mid - low + 1, highPartlen = high - mid;
	deque<pair<int, int> > lowPart(lowPartLen), highPart(highPartlen);
	
	for (int i = low, j = 0; j < lowPartLen ; i++, j++)
		lowPart[j] = pairs[i];
	for (int i = mid + 1, j = 0; j < highPartlen; i++, j++)
		highPart[j] = pairs[i];
	int lIndex = 0, hIndex = 0, index = low;
	while (lIndex < lowPartLen && hIndex < highPartlen) {
		if (lowPart[lIndex].second > highPart[hIndex].second) {
			pairs[index] = highPart[hIndex];
			hIndex++;
		}
		else {
			pairs[index] = lowPart[lIndex];
			lIndex++;
		}
		index++; 
	}
	while (lIndex < lowPartLen)
		pairs[index++] = lowPart[lIndex++];
	while (hIndex < highPartlen)
		pairs[index++] = highPart[hIndex++];	
}

void	DevidPairs(deque<pair<int, int> > &pairs, int low, int high) {
	if (low < high) {
		int mid = low + (high - low) / 2;
		DevidPairs(pairs, low, mid);
		DevidPairs(pairs, mid + 1, high);
		mergeSort(pairs, low, mid, high);
	}
}

void	DevidPairsVector(vector<pair<int, int> > &pairs, int low, int high) {
	if (low < high) {
		int mid = low + (high - low) / 2;
		DevidPairsVector(pairs, low, mid);
		DevidPairsVector(pairs, mid + 1, high);
		mergeSortVector(pairs, low, mid, high);
	}
}

void PmergeMe::FordJohnsonDeque(deque<int> &sequence)
{
	deque<pair <int, int> > pairs;
	deque<int>	mainChain, pendingChain;

	for (size_t index = 0; index < sequence.size() - 1; index += 2)
		pairs.push_back(make_pair(sequence[index], sequence[index + 1]));
	for (deque<pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		if (it->first > it->second)
			swap(it->first, it->second);
	DevidPairs(pairs, 0, pairs.size() - 1);
	for (deque<pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
		mainChain.push_back(it->second);
		pendingChain.push_back(it->first);
	}
	if (sequence.size() % 2 != 0)
		pendingChain.push_back(sequence.back());
	insertLosersDeque(mainChain, pendingChain);
	sequence.swap(mainChain);
}

void PmergeMe::FordJohnsonVector(vector<int> &sequence)
{
	vector<pair <int, int> > pairs;
	vector<int>	mainChain, pendingChain;

	for (size_t index = 0; index < sequence.size() - 1; index += 2)
		pairs.push_back(make_pair(sequence[index], sequence[index + 1]));
	for (vector<pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		if (it->first > it->second)
			swap(it->first, it->second);
	DevidPairsVector(pairs, 0, pairs.size() - 1);
	for (vector<pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
		mainChain.push_back(it->second);
		pendingChain.push_back(it->first);
	}
	if (sequence.size() % 2 != 0)
		pendingChain.push_back(sequence.back());
	insertLosersVector(mainChain, pendingChain);
	sequence.swap(mainChain);
}

int	check(const std::string &val) {
	for (std::string::const_iterator it = val.begin(); it != val.end(); it++) {
		if (!isdigit(*it))
			return (1);
	}
	return (0);
}

PmergeMe::PmergeMe(char **input, size_t size) 
{
    for (size_t _index = 1; _index < size; _index++) {
		if (check(input[_index])) {
			throw(std::runtime_error("Error : invalid input => \"" + std::string(input[_index]) + "\""));
		}
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