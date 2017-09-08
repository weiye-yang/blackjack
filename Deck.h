#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <cstdlib>
#include <ctime>

class Deck
{
private:
	Card m_deck[Card::totalCards];
	int m_cardIndex; //the card currently on top of the deck, or rather, the number of cards that have been dealt so far

	void swapCard(Card &card1, Card &card2) const
	{
		Card temp = card1;
		card1 = card2;
		card2 = temp;
	}
public:
	Deck(): m_cardIndex(0)
	{
		int cardNo = 0;
		for (int suit = 0; suit < Card::TOTAL_SUITS; ++suit)
		{
			for (int rank = 0; rank < Card::TOTAL_RANKS; ++rank)
			{
				//cast integers into our enumerated types
				m_deck[cardNo] = { static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit) };

				++cardNo;
			}
		}
	}
	
	//get the top card from the deck and increment the card index
	const Card &dealCard() { return m_deck[m_cardIndex++]; }

	void shuffleDeck()
	{
		//seed to current time
		srand(time(0));
		rand();

		for (Card &card : m_deck)
		{
			int randomCardNo = rand() % Card::totalCards;
			swapCard(card, m_deck[randomCardNo]);
		}
	}

};

#endif // !DECK_H
