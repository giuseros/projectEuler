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
	int highestCard;

	Point(PointName n, int h, int v): name(n), highestCard(h), cards({v}){}
	Point(PointName n, int h, Suit s):name(n), highestCard(h), suit(s){}
	Point(PointName n, int h, int v1, int v2): name(n), highestCard(h), cards({v1,v2}){}
};

bool operator>(Point p1, Point p2)
{
	if (p1.name > p2.name) return true;
	if (p1.name==p2.name){
		if (p1.cards[0] == p2.cards[0]){
			return p1.highestCard > p2.highestCard;
		}else{
			return (p1.cards[0] > p2.cards[0]);
		}
	}
	return false;
}

bool cardComparator(Card const& c1, Card const& c2)
{
	return c1.val > c2.val;
}

bool allCardsConsecutive(vector<Card> hand)
{
	for (int i = 0;i<4;i++){
		if (hand[i].val != hand[i+1].val + 1){
			return false;
		}
	}
	return true;
}

Point getPoint(vector<Card> hand, bool debug=0){
	sort(begin(hand), end(hand), cardComparator);

	auto hCard = hand[0].val;
	map<int,int> values;
	map<Suit, int> suits;

	for ( auto c : hand){
		values[c.val]++;
		suits[c.suit]++;
	}

	auto numDifferentValues = values.size();
	auto numDifferentSeeds = suits.size();
	if (numDifferentSeeds == 1 && hand[0].val == 14 && allCardsConsecutive(hand)){
		for (auto s : suits){ return Point(ROYAL_FLUSH, hCard, s.first); }
	} else if (numDifferentSeeds == 1 && allCardsConsecutive(hand)){
		for (auto s : suits){ return Point(STRAIGHT_FLUSH, hCard, s.first); }
	} else if (numDifferentValues == 2){
		int cardPair(0), cardTris(0);
		for (auto v : values){
			if (v.second == 4){
				return Point(POKER, hCard, v.first);
			} else if (v.second == 3){
				cardTris = v.first;
			} else {
				cardPair = v.first;
			}
		}
		return Point(FULL_HOUSE, hCard, cardPair, cardTris);
	} else if (numDifferentSeeds == 1){
		for (auto s : suits){ return Point(FLUSH, hCard, s.first); }
	} else if (allCardsConsecutive(hand)){
		return Point(STRAIGHT, hCard, hand[0].val);
	} else if (numDifferentValues == 3){
		int firstPair(0), secondPair(0);
		for (auto v : values){
			if (v.second == 3){
				return Point(TRIS, hCard, v.first);
			} else if (v.second==2 && firstPair==0){
				firstPair = v.first;
			} else if (v.second ==2){
				secondPair = v.first;
			}
		}
		return Point(TWO_PAIR, hCard, firstPair, secondPair);
	} else if (numDifferentValues == 4){
		for (auto v: values){ if (v.second ==2) return Point(PAIR, hCard, v.first); }
	} else {
		return Point(HIGH_CARD, hCard, hand[0].val);
	}
}

bool cmp(vector<Card>  hand1,
         vector<Card>  hand2,
		 bool debug=0)
{
	auto point1 = getPoint(hand1, debug);
	auto point2 = getPoint(hand2, debug);

    return point1 > point2;
}

int main()
{
    int count(0);
    fstream f;

    // Does not like relative paths
    f.open("/local/projects/projectEuler/p054_poker.txt");
    for (int i = 0; i < 1000;i++){
        string valueAndSuit;
        vector<Card> hand1;
        for (int j = 0; j < 5; j++){
            f>>valueAndSuit;
            hand1.emplace_back(valueAndSuit);
        }

        vector<Card> hand2;
        for (int j = 0; j < 5; j++){
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
