#include <iostream>
#include <vector>

using namespace std;

// IT REPRESENTS [a, e, i, o, u]
const vector<int> ASCII_VOWELS = {97, 101, 105, 111, 117};
const int ASCII_SPACE = 32;

void replace_last_letter_with_first(string &input)
{
    char last_letter = input[input.length() - 1];
    char first_letter = input[0];

    input[input.length() - 1] = first_letter;
    input[0] = last_letter;
}

int count_number_of_symbols(const string& input, char symbol)
{
    int counter = 0;
    for (char ch : input)
    {
        if (ch == symbol)
            counter++;
    }

    return counter;
}

int count_vowels(const string& input)
{
    int counter = 0;

    for (char ch : input)
    {
        int lower_char = (int) tolower(ch);
        for (int i : ASCII_VOWELS)
        {
            if (i == lower_char) {
                counter++;
            }
        }
    }

    return counter;
}

string reverse(string input)
{
    string result;

    for (int i = input.size() - 1; i >= 0; i--)
    {
        result.push_back(input[i]);
    }

    return result;
}

bool is_palindrome(string input)
{
    string reversed_input;

    for (int i = input.size() - 1; i >= 0; i--)
    {
        reversed_input.push_back(input[i]);
    }

    return reversed_input == input;
}

vector<string> divide_by_spaces(const string& input)
{
    vector<string> result;
    string word;
    for (int i = 0; i < input.size(); i++)
    {
        if (i + 1 == input.size()) {
            word.push_back(input[i]);
            result.push_back(word);
            break;
        }
        int ascii_char = (int) input[i];
        if (ascii_char == ASCII_SPACE)
        {
            result.push_back(word);
            word = "";
            continue;
        }
        word.push_back(input[i]);
    }

    return result;
}

int main() {
    string s1 = "Oleksii";
    replace_last_letter_with_first(s1);

    cout << "s1 after using replace_last_letter_with_first = " << s1 << endl;

    int number_of_vowels = count_vowels(s1);

    cout << "Number of vowels in s1 = " << number_of_vowels << endl;

    string s2 = "Lego";

    cout << "s2 before reversing = " << s2 << endl;
    string s2_reversed = reverse(s2);

    cout << "s2 after reversing = " << s2_reversed << endl;

    string s3 = "level";
    string is_palindrome_text = is_palindrome(s3) ? "true" : "false";

    cout << "s3 is palindrome? " << is_palindrome_text << endl;

    string s4 = "hello";

    int number_of_symbols_s4 = count_number_of_symbols(s4, 'l');

    cout << "in word: " << s4 << " number of symbols is: " << number_of_symbols_s4 << endl;

    string s5 = "hello world it's my name";
    vector<string> s5_vector = divide_by_spaces(s5);

    for (const string& str : s5_vector)
    {
        cout << "Element is: " << str << endl;
    }
}
