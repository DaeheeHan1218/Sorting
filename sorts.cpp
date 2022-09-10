#include <iostream>
#include <vector>
#include <string>
#include "sorts.h"

using namespace std;

int main() {
    std::string sort_name, data_type;
    // sort ::= "selection" | "insertion" | "shell" | "heap" | "merge" | "quick" | "bucket" | "radix"
    // data ::= "numbers" | "strings"
    cin >> sort_name >> data_type; 
    if (sort_name != "selection" && sort_name != "insertion" && sort_name != "shell" && sort_name != "heap" && sort_name != "merge" && sort_name != "quick" && sort_name != "bucket" && sort_name != "radix") {
        cerr << "sort name must be one of: selection, insertion, shell, heap, merge, quick, bucket, radix" << endl;
        return 0;
    }
    if (data_type != "numbers" && data_type != "strings") {
        cerr << "data type must be one of: numbers, strings" << endl;
        return 0;
    }
    bool is_numbers = data_type == "numbers";
    if (!is_numbers && sort_name == "bucket") {
        cerr << "bucket sort cannot be used to sort strings" << endl;
        return 0;
    }
    std::vector<unsigned> numbers;
    std::vector<std::string> strings;
    
    unsigned number;
    std::string line;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (is_numbers) {        
        cin >> number;
    } else {
        getline(cin, line);
    }
    while (!cin.eof()) {
        if (is_numbers) {
            numbers.push_back(number);
            cin >> number;
        } else {
            strings.push_back(line);
            getline(cin, line);
        }
    }
    
    if (sort_name == "selection") {
        if (is_numbers) {
            selection_sort(numbers);
        } else {
            selection_sort(strings);
        }
    } else if (sort_name == "insertion") {
        if (is_numbers) {
            insertion_sort(numbers);
        } else {
            insertion_sort(strings);
        }
    } else if (sort_name == "shell") {
        if (is_numbers) {
            shell_sort(numbers);
        } else {
            shell_sort(strings);
        }
    } else if (sort_name == "heap") {
        if (is_numbers) {
            heap_sort(numbers);
        } else {
            heap_sort(strings);
        }
    } else if (sort_name == "merge") {
        if (is_numbers) {
            merge_sort(numbers);
        } else {
            merge_sort(strings);
        }
    } else if (sort_name == "quick") {
        if (is_numbers) {
            quick_sort(numbers);
        } else {
            quick_sort(strings);
        }
    } else if (sort_name == "bucket") {
        bucket_sort(numbers);
    } else if (sort_name == "radix") {
        if (is_numbers) {
            radix_sort(numbers);
        } else {
            radix_sort(strings);
        }
    }
    
    return 0;
}
