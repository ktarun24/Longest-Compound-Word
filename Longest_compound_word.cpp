
#include <bits/stdc++.h>
using namespace std;

class trie
{
public:
    trie *hash[26] = {0};
    
    int lastword = 0;
    int prefix=0;
};  


bool compare(string &s1, string &s2)
{
    return s1.size() > s2.size();
}


void insertintrie(trie **root, string word, int length, int index)
{
    if (index < length)
    {       
        if (((*root)->hash[word[index] - 97]) == 0)
        {
            ((*root)->hash[word[index] - 97]) = new trie();
        }
        ((*root)->hash[word[index] - 97])->prefix += 1;

        insertintrie(&((*root)->hash[word[index] - 97]), word, length, index + 1);
    }
    if (index == length)

    {
        (*root)->lastword = 1;
    }
}

int longest_compound_word(trie **root, string word, int index, int length, int splited)
{
    trie *curr = (*root);
    if (index < length)
    {
        if ((curr->hash[word[index] - 97]) == 0)
            return 0;
    }
    while (index < length)
    {   
        
        if (((curr->hash[word[index] - 97])->lastword == 1) && (index != length - 1))
        {
            int x = longest_compound_word(root, word, index + 1, length, 1);
            if (x == 1)
            {
                return 1;
            }
        }
        curr = (curr->hash[word[index] - 97]);
        index += 1;
        if (((curr->hash[word[index] - 97]) == 0) && (index != length))
            return 0;
    }
    if ((index == length) && (splited == 1))
        return 1;
    if ((splited == 1) && ((curr->lastword) == 1))
        return 1;
    return 0;
}

int main()
{
    freopen("input_02.txt", "r", stdin);
    freopen("output_02.txt", "w", stdout);
    
    trie *root = new trie();
    int n;
    vector<string> result;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        result.push_back(s);
        insertintrie(&root, s, s.length(), 0);
    }

    sort(result.begin(), result.end(), compare);
    int not_present=1;
    int count=0;

    for (int i = 0; i < n; i++)

    {
        if (longest_compound_word(&root, result[i], 0, result[i].length(), 0) == 1)
        {
            cout << result[i]  << endl;
            count += 1;
            if (count == 2)
            {
            not_present=0;
            break;
            }
        }
    }

    if (not_present==1)
        cout<<"No compound word found";
    
}
