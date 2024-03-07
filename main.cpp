#include <iostream>
#include <vector>

using namespace std;

// IT REPRESENTS [a, e, i, o, u]
const vector<int> ASCII_VOWELS = {97, 101, 105, 111, 117};

void replace_last_letter_with_first(string &input)
{
    char last_letter = input[input.length() - 1];
    char first_letter = input[0];

    input[input.length() - 1] = first_letter;
    input[0] = last_letter;
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

string reverse_string(string input)
{
    string result;

    for (int i = input.size() - 1; i >= 0; i--)
    {
        result.push_back(input[i]);
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
    string s2_reversed = reverse_string(s2);

    cout << "s2 after reversing = " << s2_reversed << endl;
}
