#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;
int wordToNum(string const& w)
{
    int acc = 0;
    for (auto c : w){
        acc += (c-'A'+1);
    }
    return acc;
}

bool isflint(double n)
{
    return (floor(n)==n);
}

bool checkTriangular(int x)
{
    //n*(n-1)/2 = x ----> n^2 - n - 2*x = 0 ---> n = (1+/- sqrt(1+8x))/2
    double n1 = (1+sqrt(1+8*x));
    double n2 = (1-sqrt(1+8*x));
    if ((n1 > 0 && isflint(n1)) || 
        (n2 > 0 && isflint(n2))){
        return true;
    }
    return false;
}

vector<int> parseWords(string const& line)
{
    vector<int> words2num;
    string word;
    int state(0);
    for (auto c : line){
        if (c==','){
            continue;
        }
        if (c=='\"' && state==0){
            state = 1;
            continue; 
        } 
        if (c=='\"' && state == 1){
            state = 0;
            words2num.push_back(wordToNum(word));
            word.clear();
            continue;
        }
        word.push_back(c);
    }
    return words2num;
}

int main()
{
    ifstream f;
    f.open("p042_words.txt");
    string line;
    f >> line;
    f.close();
    auto numeric_words = parseWords(line);
    int ans = 0;
    for ( auto w : numeric_words){
        if (checkTriangular(w)) ans++;
    }
    cout<<ans<<endl;
}
