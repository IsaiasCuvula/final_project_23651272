/*
Да се състави функция на базата на динамичната структура стек, 
която прочита въведена от клавиатурата дума и определя, дали тя е палиндром, т.е. думата се чете по един и същ начин и отляво, и отдясно. 
Например: "капак" или "abba". 
*/
#include <iostream>
#include<stack>

using namespace std;

bool isPalindrome(string word){
    stack<char> charStack;
    // Push all characters of the word onto the stack
    for(char ch : word){
        charStack.push(ch);
    }

    // Pop characters from the stack and compare with the original word
    for (char ch : word){
        if(ch != charStack.top()){
            return false;
        }
        charStack.pop();
    }
    return true;
}

int main(){
    string word;

    cout<< "Enter a word: ";
    cin >> word;

    if(isPalindrome(word)){
        cout << "The word '" << word << "' is a palindrome." << endl;
    } else {
        cout << "The word '" << word << "' is not a palindrome." << endl;
    }
    return 0;
}