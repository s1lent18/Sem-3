#include <vector>
#include <iostream>
using namespace std;

const int asize = 256;

void computeBadCharHeuristic(const string & pattern, vector <int> & badChar) 
{
    int patternLength = pattern.length();

   
    fill(badChar.begin(), badChar.end(), -1);

    
    for (int i = 0; i < patternLength; i++) 
    {
        badChar[static_cast<int>(pattern[i])] = i;
    }
}

void searchBoyerMoore(const string & text, const string & pattern) 
{
    int textLength = text.length();

    int patternLength = pattern.length();

    vector<int> badChar(asize, 0);

    computeBadCharHeuristic(pattern, badChar);

    int shift = 0;

    while (shift <= textLength - patternLength) 
    {
        int j = patternLength - 1;

        while (j >= 0 && pattern[j] == text[shift + j]) 
        {
            j--;
        }

        if (j < 0)
        {
            cout << "Pattern found at index " << shift << endl;

            if (shift + patternLength < textLength) 
            {
                shift += patternLength - badChar[text[shift + patternLength]];
            } 
            else 
            {
                shift += 1;
            }
        } 
        else
        {
            shift += max(1, j - badChar[text[shift + j]]);
        }
    }
}

int main() 
{
    string text = "ABAAABCD";
    string pattern = "ABC";
    
    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;

    searchBoyerMoore(text, pattern);

    return 0;
}