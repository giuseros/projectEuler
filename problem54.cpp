#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

enum Point_val{
    HIGH_CARD,
    PAIR,
    TWO_PAIR,
    TRIS,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    POKER,
    STRAIGHT_FLUSH,
    ROYAL_FLUSH,
};

enum Suit{
    HEARTS,
    SPADES,
    DIAMONDS,
    CLUBS,
};

struct Card{
    int val;
    Suit suit;

    Card(string const& valAndSuit){
        char v = valAndSuit[0];
        char s = valAndSuit[1];

        if (v == 'J') val = 11;
        else if (v == 'Q') val = 12;
        else if (v == 'K') val = 13;
        else if (v =='A') val = 14;
        else val = v - '0';

        if (s=='C') suit = CLUBS;
        else if (s=='S') suit = SPADES;
        else if (s=='H') suit = HEARTS;
        else if (s=='D') suit = DIAMONDS;
    }
};


bool cmp(vector<Card> const& hand1, 
         vector<Card> const& hand2)
{
    return true;
}

int main()
{
    int count(0);
    ifstream f("./p054_poker.txt");

    for (int i = 0; i < 1000;i++){
        string valueAndSuit;

        vector<Card> hand1;
        for (int i = 0; i < 5; i++){
            f>>valueAndSuit;
            hand1.emplace_back(valueAndSuit);
        }

        vector<Card> hand2;
        for (int i = 0; i < 5; i++){
            f>>valueAndSuit;
            hand2.emplace_back(valueAndSuit);
        }

        if (cmp(hand1, hand2)){
            count++;
        }
    }
    cout<<count<<endl;
}
