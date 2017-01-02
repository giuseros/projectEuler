#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

enum PointName{
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

        if (v=='T') val = 10;
        else if (v == 'J') val = 11;
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

struct Point
{
	PointName name;
	vector<int> cards;
	Suit suit;

	Point(PointName n, int v): name(n), cards({v}){}
	Point(PointName n, Suit s):name(n), suit(s){}
	Point(PointName n, int v1, int v2): name(n), cards({v1,v2}){}
};

bool operator>(Point p1, Point p2)
{
	if (p1.name > p2.name) return true;
	if (p1.name==p2.name){

	}
	return false;
}

bool cardComparator(Card const& c1, Card const& c2)
{
	return c1.val < c2.val;
}

bool allCardsConsecutive(vector<Card> hand)
{
	for (int i = 0;i<4;i++){
		if (hand[i].val != hand[i+1].val){
			return false;
		}
	}
	return true;
}

Point getPoint(vector<Card> hand){
	sort(begin(hand), end(hand), cardComparator);
	map<int,int> values;
	map<Suit, int> suits;

	for ( auto c : hand){
		values[c.val]++;
		suits[c.suit]++;
	}

	auto numDifferentValues = values.size();
	auto numDifferentSeeds = suits.size();
	if (numDifferentSeeds == 1 && hand[0].val == 14 && allCardsConsecutive(hand)){

		for (auto s : suits){ return Point(ROYAL_FLUSH, s.first); }
	} else if (numDifferentSeeds == 1 && allCardsConsecutive(hand)){

		for (auto s : suits){ return Point(STRAIGHT_FLUSH, s.first); }
	} else if (numDifferentValues == 2){
		int cardPair(0), cardTris(0);
		for (auto v : values){
			if (v.second == 4){
				return Point(POKER, v.first);
			} else if (v.second == 3){
				cardTris = v.first;
			} else {
				cardPair = v.first;
			}
		}
		return Point(FULL_HOUSE, cardPair, cardTris);
	} else if (numDifferentSeeds == 1){
		for (auto s : suits){ return Point(FLUSH, s.first); }
	} else if (allCardsConsecutive(hand)){
		return Point(STRAIGHT, hand[0].val);
	} else if (numDifferentValues == 3){
		int firstPair(0), secondPair(0);
		for (auto v : values){
			if (v.second == 3){
				return Point(TRIS, v.first);
			} else if (v.second==2 && firstPair==0){
				firstPair = v.first;
			} else if (v.second ==2){
				secondPair = v.first;
			}
		}
		return Point(TWO_PAIR, firstPair, secondPair);
	} else if (numDifferentValues == 4){
		for (auto v: values){
			if (v.second ==2){
				return Point(PAIR, v.first);
			}
		}
	} else {
		return Point(HIGH_CARD, hand[0].val);
	}


}

bool cmp(vector<Card>  hand1,
         vector<Card>  hand2)
{
	auto point1 = getPoint(hand1);
	auto point2 = getPoint(hand2);

    return point1 > point2;
}

int main()
{
    int count(0);
    fstream f;

    // Does not like relative paths
    f.open("/local/projects/projectEuler/test.txt");
    for (int i = 0; i < 1;i++){
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
    f.close();
    cout<<count<<endl;
}
