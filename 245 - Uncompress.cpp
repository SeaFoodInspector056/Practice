#include <bits/stdc++.h>
using namespace std;

vector<string> wordList;
//包裝成function更快
void insert_word(string word)
{
    wordList.insert(wordList.begin(), word);
    cout << word;
}

void print_number(int n)
{
    string target = wordList[n - 1];
    wordList.erase(wordList.begin() + n - 1);
    wordList.insert(wordList.begin(), target);

    cout << target;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (getline(cin, line) && line != "0")
    {
        int size = line.size();

        for (int i = 0; i < size; i++)
        {
            if (isalpha(line[i]))
            {
                string word = "";
                do
                {
                    word += line[i];
                    i++;
                } while(i < size && isalpha(line[i]));
                i--;

                insert_word(word);
            }
            else if (isdigit(line[i]))
            {
                int n = 0;
                do
                {
                    n = n * 10 + (line[i] - '0');
                    i++;
                } while (i < size && isdigit(line[i]));
                i--;

                print_number(n);
            }
            else 
                cout << line[i]; 
        }  
        
        cout << '\n';
    }

    return 0;
}