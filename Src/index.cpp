#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::string;
using std::stringstream;
using std::vector;

void getfirst() {}
void getsecond() {}
void getthird() {}
void getmatrix() {}

int main()
{

    string first_input = " ";
    getline(cin, first_input, '\n');
    char space_char = ' ';
    vector<string> words{};

    stringstream sstream(first_input);
    string word;
    while (getline(sstream, word, space_char))
    {
        word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
        words.push_back(word);
    }
    // words[0] = number of companies.
    // words[1] = number of projects.
    // we get input in string style but we need to integer number to work with that nums.
    // so we should convert string to integer by this method:

    stringstream convert_m_toint(words[0]);
    stringstream convert_n_toint(words[1]);
    int m = 0, n = 0;
    convert_m_toint >> m;
    convert_n_toint >> n;
    // Now x is integer in this case!!

    //------------------------------------------------------------------------------//

    // Get each Project Price (ai);
    int ai[n], bi[n];
    string second_input = " ";
    getline(cin, second_input, '\n');

    vector<string> words2{};

    stringstream sstream2(second_input);
    string word2;
    while (getline(sstream2, word2, space_char))
    {
        word2.erase(remove_if(word2.begin(), word2.end(), ispunct), word2.end());
        words2.push_back(word2);
    }

    for (int i = 0; i < n; i++)
    {
        stringstream convert_ai_toint(words2[i]);
        convert_ai_toint >> ai[i];
    }

    //------------------------------------------------------------------------------//

    // Get each Project Price (bi);
    string third_input = " ";
    getline(cin, third_input, '\n');

    vector<string> words3{};

    stringstream sstream3(third_input);
    string word3;
    while (getline(sstream3, word3, space_char))
    {
        word3.erase(remove_if(word3.begin(), word3.end(), ispunct), word3.end());
        words3.push_back(word3);
    }

    for (int i = 0; i < m; i++)
    {
        stringstream convert_bi_toint(words3[i]);
        convert_bi_toint >> bi[i];
    }
    //------------------------------------------------------------------------------//
    // Set Matrix:
    int matrix1[100][100];
    int profit = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix1[i][j];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (matrix1[i][j])
                if ((bi[i] - ai[j]) > 0)
                    profit += (bi[i] - ai[j]);

    cout << profit;

    return EXIT_SUCCESS;
}