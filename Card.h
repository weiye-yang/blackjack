#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card
{
public:
	enum Rank
	{
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		JACK,
		QUEEN,
		KING,
		ACE,
		TOTAL_RANKS
	};

	enum Suit
	{
		CLUB,
		DIAMOND,
		HEART,
		SPADE,
		TOTAL_SUITS
	};

	static const int totalCards = TOTAL_RANKS*TOTAL_SUITS;

private:
	Rank m_rank;
	Suit m_suit;

public:
	Card(Rank rank = TWO, Suit suit = CLUB) :m_rank(rank), m_suit(suit)
	{

	}

	void printCard() const;

	//blackjack values
	int getCardValue() const;
	//check for ace
	bool isAce() const { return m_rank == ACE; }

};

#endif // !CARD_H
