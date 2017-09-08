#include "stdafx.h"
#include <iostream>
#include "Card.h"

void Card::printCard() const
{
	char rankCode;
	switch (m_rank)
	{
	case TWO:
	{
		rankCode = '2';
		break;
	}
	case THREE:
	{
		rankCode = '3';
		break;
	}
	case FOUR:
	{
		rankCode = '4';
		break;
	}
	case FIVE:
	{
		rankCode = '5';
		break;
	}
	case SIX:
	{
		rankCode = '6';
		break;
	}
	case SEVEN:
	{
		rankCode = '7';
		break;
	}
	case EIGHT:
	{
		rankCode = '8';
		break;
	}
	case NINE:
	{
		rankCode = '9';
		break;
	}
	case TEN:
	{
		rankCode = 'T';
		break;
	}
	case JACK:
	{
		rankCode = 'J';
		break;
	}
	case QUEEN:
	{
		rankCode = 'Q';
		break;
	}
	case KING:
	{
		rankCode = 'K';
		break;
	}
	case ACE:
	{
		rankCode = 'A';
		break;
	}
	}

	char suitCode;
	switch (m_suit)
	{
	case CLUB:
	{
		suitCode = 'C';
		break;
	}
	case DIAMOND:
	{
		suitCode = 'D';
		break;
	}
	case HEART:
	{
		suitCode = 'H';
		break;
	}
	case SPADE:
	{
		suitCode = 'S';
		break;
	}
	}

	std::cout << rankCode << suitCode;
}

//blackjack values
int Card::getCardValue() const
{
	switch (m_rank)
	{
	case TWO: return 2;
	case THREE: return 3;
	case FOUR: return 4;
	case FIVE: return 5;
	case SIX: return 6;
	case SEVEN: return 7;
	case EIGHT: return 8;
	case NINE: return 9;
	case TEN:
	case JACK:
	case QUEEN:
	case KING: return 10;
	case ACE: return 11; //can also be 1; this is dealt with in playBlackjack()
	}

}

