/*
Да се състави функция за изключване на i-я елемент, 
ако е кратен на k в списък с начален указател START.
Числото k се задава от потребителя по време на изпълнение на програмата.
*/
#include <iostream>
#include<vector>

using namespace std;


// Function to exclude elements that are multiples of k
vector<int> excludeMultiplesOfK(const vector<int>& list, int k) {
    vector<int> result;
    for (int element : list) {
        if (element % k != 0) {  
            result.push_back(element);
        }
    }
    return result;
}

int main() {
    int n, k;

    // Get the value of k from the user
    cout << "Enter the value of k: ";
    cin >> k;

    // Get the size of the list from the user
    cout << "Enter the number of elements in the list: ";
    cin >> n;

    vector<int> list(n);

    // Get the elements of the list from the user
    cout << "Enter the elements of the list: ";
    for (int i = 0; i < n; ++i) {
        cin >> list[i];
    }

    // Get the result after excluding multiples of k
    vector<int> result = excludeMultiplesOfK(list, k);

    // Print the result
    cout << "List after excluding multiples of " << k << ": ";
    for (int elem : result) {
        cout << elem << ",";
    }
    return 0;
}