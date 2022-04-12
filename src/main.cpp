#include <bits/stdc++.h>
#include "trie.cpp"
#include "utils.cpp"
using namespace std;

void test();

int main(int argc, char **argv)
{
    string filename;
    Trie T;
    vector<string> data;

    // if File provided in Arguments.
    if (argc > 1)
    {
        filename = argv[1];
        data = get_array_from_file(filename);
    }
    else
    {
        cout << "Enter File name to load data from. ( music | movies | words ) :\n";
        cin >> filename;
        cerr << "loading ...";
        data = get_array_from_file("../data/" + filename + ".txt");
        cerr << "Done.\n";
    }

    for (string word : data)
    {
        // cout << word << "\n";
        T.insert(word);
    }

    int choice;

    // If pattern in Arguments.
    if (argc > 2)
    {
        string pattern = argv[2];
        for (string w : search(data, pattern))
        {
            cout << w << "\n";
        }
        return 0;
    }

    do
    {

        cout << "------------------------\n";
        cout << "MENU\n";
        cout << "1. Exact Search.\n";
        cout << "2. Prefix Search.\n";
        cout << "3. Universal Search.\n";
        cout << "0. Exit.\n";

        cin >> choice;
        getchar(); // get the new line character

        string pattern;

        if (choice)
        {
            cout << "Enter Search Text (leave empty to list all) : ";
            getline(cin, pattern);
        }

        switch (choice)
        {
        case 1:
            if (T.search_exact(pattern))
            {
                cout << "String Exists.\n";
            }
            else
            {
                cout << "NOT Found.\n";
            }
            break;
        case 2:
            for (string w : T.search_pre(pattern))
            {
                cout << w << "\n";
            }
            break;

        case 3:
            for (string w : search(data, pattern))
            {
                cout << w << "\n";
            }
            break;

        default:
            break;
        }

        cout << "\n\npress any key to continue.";
        getchar();
        system("clear");

    } while (choice);

    // cout << "LINEAR Search.";
    // for (string w : linear_search_pre(data, "The G"))
    // {
    //     // cout << w << "\n";
    // }

    // T.search_exact("The Gold Rush (1925)");
    // linear_search_exact(data, "The Gold Rush (1925)");

    // T.draw(NULL);

    return 0;
}

void test()
{
}
