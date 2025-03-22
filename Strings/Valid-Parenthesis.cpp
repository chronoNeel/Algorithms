// Given a string s containing just the characters 
//'(', ')', '{', '}', '[', and ']', determine if the input string is valid.

// ()[]{} Valid
// ([]) Valid
// (] Not valid


#include <bits/stdc++.h>

using namespace std;


bool isValid (string s) {
    stack <char> st;
    unordered_map <char, char> brackets = {{')', '('}, {'}', '{'}, {']', '['}};

    for (auto c : s) {
        if (c == '('|| c == '[' || c == '{') st.push(c);
        else {
            if (s.empty() || st.top() != brackets[c]) return false;
            else {
                st.pop();
            }
        }
    }

    return st.empty();
}

int main()
{
    string s;
    cin >> s;
    if (isValid(s)) cout << "The string has a valid parenthesis";
    else cout << "The string does not have a valid parenthesis";
}