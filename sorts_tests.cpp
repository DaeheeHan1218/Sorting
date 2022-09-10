#include "sorts.h"

int main() {
    // TODO(student): write tests
    std::vector<int> vect1{81,94,11,96,12,35,17,95,28,58,41,75,15};
	std::vector<unsigned int> vect2{8,1,9,4,1,1,9,6,1,2,3,5,1,7,9,5,2,8,5,8,4,1,7,5,1,5};
	std::vector<unsigned int> vect3{18, 57, 102, 14, 126, 51, 108, 47, 65, 40, 11, 120, 16, 89, 45, 31, 88, 72, 8, 69, 56, 56, 48, 78, 22, 59, 17, 25, 113, 62, 47, 99, 65, 98, 85, 77, 64, 60, 40, 127, 50, 22, 39, 69, 85, 12, 50, 127, 102, 101, 5, 22, 98, 89, 50, 62, 109, 89, 37, 73, 74, 44, 30, 60, 75, 39, 119, 98, 93, 25, 95, 71, 51, 7, 89, 103, 127, 112, 95, 122, 97, 10, 49, 87, 42, 68, 104, 121, 63, 44, 73};
	
	std::vector<int> emptyVect;
	std::vector<unsigned int> unsignedEmpty;
	
	selection_sort(vect1);
	selection_sort(vect2);
	selection_sort(emptyVect);
	
	insertion_sort(vect1);
	insertion_sort(vect2);
	insertion_sort(emptyVect);
	
	shell_sort(vect1);
	shell_sort(vect2);
	shell_sort(emptyVect);
	
	merge_sort(vect1);
	merge_sort(vect2);
	merge_sort(emptyVect);
	
	bucket_sort(vect2);
	bucket_sort(vect3);
	bucket_sort(unsignedEmpty);
	
	heap_sort(vect1);
	quick_sort(vect1);
	radix_sort(vect1);
    return 0;
}
