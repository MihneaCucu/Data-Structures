#include <iostream>
#include <fstream>
#include <cstring>
#include <stack>
using namespace std;

/*
 push
 pop
 top
 empty
 
 */

bool verifica_sirul (string sir)    // **()*
{
    stack<char> stiva;
    
    for(char caracter:sir)  //
    {
        if (caracter == '(' || caracter == '[')
        {
            stiva.push(caracter);
        }
        else if (caracter == ')' || caracter == ']')
        {
            if (stiva.empty())
            {
                return false;
            }
            
            if (caracter == ')' && stiva.top() != '(')
            {
                return false;
            }
            
            if (caracter == ']' && stiva.top() != '[')
            {
                return false;
            }
            
            stiva.pop();
        }
        else if (caracter == '*')
        {
           if (!stiva.empty())
            {
                stiva.pop();
            }
        }
    }
    return stiva.empty();
}

int main()
{
    ifstream fin("editor.in");
    ofstream fout("editor.out");
    int T;
    string sir;
    fin >> T;
    fin.ignore();
    for (int i = 1; i <= T; i++)
    {
        getline(fin, sir);
        string sir_nou;
        
        for(char caracter:sir)
            {
            if (caracter != 'E')
            {
                sir_nou.push_back(caracter);
            }
            }
        
        string sir_nnou;
        
        for(char caracter:sir_nou) // **()*
            {
            if (caracter == '*' && !sir_nnou.empty())
                sir_nnou.pop_back();
            else
                sir_nnou.push_back(caracter);
            }
        
        if (verifica_sirul(sir_nnou) == true)
            fout << ":)"<<'\n';
        else
            fout<< ":("<<'\n';
    }
    
    fin.close();
    fout.close();
    return 0;
}
