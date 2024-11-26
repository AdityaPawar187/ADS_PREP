#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to print the original and reversed string using a stack
void printOriginalAndReversed(const string &str) {
    stack<char> s;
    string reversed;

    // Push each character onto the stack
    for (char c : str) {
        s.push(c);
    }

    // Pop characters from the stack to form the reversed string
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    cout << "Original string: " << str << endl;
    cout << "Reversed string: " << reversed << endl;
}

// Function to check if the given string is a palindrome
bool isPalindrome(const string &str) {
    int left = 0;
    int right = str.length() - 1;

    // Compare characters from both ends
    while (left < right) {
        if (str[left] != str[right]) {
            return false; // Not a palindrome
        }
        left++;
        right--;
    }
    return true; // Palindrome
}

int main() {
    string input;

    cout << "Enter a string: ";
    getline(cin, input); // Take input including spaces

    // Part a: Print original and reversed string
    printOriginalAndReversed(input);

    // Part b: Check if the string is a palindrome
    if (isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
