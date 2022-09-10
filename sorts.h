#ifndef SORTS_H
#define SORTS_H

#include <functional>
#include <iostream>
#include <vector>
#include <utility>
#include <cstddef>

// Pretty printing for vectors of Printable objects (have ostream operator<< defined)
// Be careful: modifications risk failing tests
template <class Printable>
std::ostream& operator<<(std::ostream& os, const std::vector<Printable>& container) {
    os << "[";
    bool first = false;
    for (const Printable& t : container) {
        if (first) {
            os << ", ";
        }
        if (typeid(t) == typeid(std::string)) {
            os << "\"" << t << "\"";
        } else {
            os << t;
        }
        first = true;
    }
    os << "]";
    return os;
}

// Selection sort (example of implementation expectations)
template <class Comparable>
void selection_sort(std::vector<Comparable>& container) {
    // print the initial container
    std::cout << container << std::endl;
    
    if (container.empty()) {
        return;
    }

    for (size_t index = 0; index < container.size()-1; index++) {
        // do 1 pass of selection sort: find the min and swap it to the front
        size_t index_min = index;
        for (size_t i = index+1; i < container.size(); i++) {
            if (container[i] < container[index_min]) {
                index_min = i;
            }
        }
        Comparable t = container[index];
        container[index] = container[index_min];
        container[index_min] = t;
        
        // print the container after each pass
        std::cout << container << std::endl;
    }
}

// TODO(student): implement 4 sorts from: insertion, shell, heap, merge, quick, bucket, radix
size_t power(size_t n, size_t pwr){
	size_t val = 1;
	for(size_t i = 0; i < pwr; i++){
		val = val * n;
	}
	return val;
}

template <class Comparable>
void insertion_sort(std::vector<Comparable>& container) {
    std::cout << container << std::endl;
    Comparable key;
	size_t i, j;
    if (container.empty() || container.size() == 1) {
        return;
    }
    for(i = 1; i < container.size(); i++) {
        key = container[i];
		for(j = i; j > 0 && container[j - 1] > key; j--){
			container[j] = container[j - 1];
		}
		container[j] = key;
        std::cout << container << std::endl;
    }
}

template <class Comparable>
void shell_sort(std::vector<Comparable>& container){
    std::cout << container << std::endl;
    Comparable key;
	size_t i, j, k, cont = container.size(), max_pwr = 0;
    if (container.empty() || container.size() == 1) {
        return;
    }
	while((cont / 2) > 0){
		cont /= 2;
		max_pwr++;
	}
    for(i = max_pwr; i > 0; i--){
        for(j = power(2, i) - 1; j < container.size(); j++){
			key = container[j];
			for(k = j; k >= (power(2, i) - 1) && key < container[k - (power(2, i) - 1)]; k -= (power(2, i) - 1)){
				container[k] = container[k - (power(2, i) - 1)];
			}
			container[k] = key;
		}
        std::cout << container << std::endl;
    }
}

template <class Comparable>
void merge(std::vector<Comparable>& orig, std::vector<Comparable>& tmp, int l_index, int r_index, int r_end){
	int l_end = r_index - 1;
	int i = l_index;
	int n = r_end - l_index + 1;
	while(l_index <= l_end && r_index <= r_end){
		if(orig[l_index] <= orig[r_index]){
			tmp[i] = orig[l_index];
			i++;
			l_index++;
		}
		else{
			tmp[i] = orig[r_index];
			i++;
			r_index++;
		}
	}
	while(l_index <= l_end){
		tmp[i] = orig[l_index];
		i++;
		l_index++;
	}
	while(r_index <= r_end){
		tmp[i] = orig[r_index];
		i++;
		r_index++;
	}
	for(int j = 0; j < n; j++, r_end--){
		orig[r_end] = tmp[r_end];
	}
}

template <class Comparable>
void mergeSort(std::vector<Comparable>& orig, std::vector<Comparable>& tmp, int l, int r){
	if(l < r){
		int cent = (l + r) / 2;
		mergeSort(orig, tmp, l, cent);
		mergeSort(orig, tmp, cent + 1, r);
		merge(orig, tmp, l, cent + 1, r);
		std::cout << orig << std::endl;
	}
}

template <class Comparable>
void merge_sort(std::vector<Comparable>& container){
    std::cout << container << std::endl;
    if (container.empty() || container.size() == 1){
        return;
    }
	std::vector<Comparable> tmpVect(container.size());
	mergeSort(container, tmpVect, 0, container.size() - 1 );
}


void bucket_sort(std::vector<unsigned int>& container) {
    std::cout << container << std::endl;
    if (container.empty() || container.size() == 1) {
        return;
    }
	int i, j, k;
	int bucket_num = container[0];
	for(int i = 1; i < container.size(); i++){
		if(container[i] > bucket_num){
			bucket_num = container[i];
		}
	}
	bucket_num += 1;
	std::vector<unsigned int> counting(bucket_num, 0);
	for(i = 0; i < container.size(); i++){
		counting[container[i]] += 1;
	}
	container.clear();
	std::cout << counting << std::endl;
	for(j = 0; j < bucket_num; j++){
		for(k = 0; k < counting[j]; k++){
			container.push_back(j);
		}
		if(counting[j] > 0){
			std::cout << container << std::endl;
		}
	}
}

template <class Comparable>
void heap_sort(std::vector<Comparable>& container){}

template <class Comparable>
void quick_sort(std::vector<Comparable>& container){}

template <class Comparable>
void radix_sort(std::vector<Comparable>& container){}

void radix_sort(std::vector<std::string>& array){}





#endif  // SORTS_H