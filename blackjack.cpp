// blackjack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <array>
#include <cstdlib>
#include "Card.h"
#include "Deck.h"

//learncpp Chapter 8 quiz question 4

/*
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

const int totalCards = TOTAL_RANKS*TOTAL_SUITS;

struct Card
{
	Rank rank;
	Suit suit;
};

void printCard(const Card &card)
{
	char rankCode;
	switch(card.rank)
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
	switch (card.suit)
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

void printDeck(const std::array<Card, totalCards> &deck)
{
	for (const auto &card : deck)
	{
		printCard(card);
		std::cout << "\n";
	}
}


//blackjack values
int getCardValue(const Card &card)
{
	switch (card.rank)
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

void swapCard(Card &card1, Card &card2)
{
	Card temp = card1;
	card1 = card2;
	card2 = temp;
}


void shuffleDeck(std::array<Card, Card::totalCards> &deck)
{
	//seed to current time
	srand(time(0));
	rand();

	for (Card &card : deck)
	{
		int randomCardNo = rand() % Card::totalCards;
		swapCard(card, deck[randomCardNo]);
	}
}
*/

//deal a card to the player
void dealPlayer(Deck &deck, int &score, int &aces)
{
	const Card &card = deck.dealCard();
	std::cout << "You are dealt a card from the deck. It is ";
	card.printCard(); std::cout << ".\n";

	//ace?
	if (card.isAce())
		++aces;

	//increment score by value of card
	score += card.getCardValue();

	std::cout << "Your score is now " << score << ".\n";
}

//dealer draws a card
void dealDealer(Deck &deck, int &score, int &aces)
{
	const Card &card = deck.dealCard();
	std::cout << "The dealer is dealt a card from the deck. It is ";
	card.printCard(); std::cout << ".\n";

	//ace?
	if (card.isAce())
		++aces;

	//increment score by value of card
	score += card.getCardValue();

	std::cout << "Dealer's score is now " << score << ".\n";
}


int playBlackjack(Deck deck)
{
	int playerScore(0), dealerScore(0);
	int playerAces(0), dealerAces(0);// aces are special

	//player is dealt two cards and dealer is dealt one card
	dealPlayer(deck, playerScore, playerAces);
	dealPlayer(deck, playerScore, playerAces);
	if (playerScore == 21)
	{
		std::cout << "Blackjack!";
		return 1;
	}

	dealDealer(deck, dealerScore, dealerAces);

	//player's turn.
	std::cout << "Your turn.\n";
	while (true)
	{
		char choice;
		do
		{
			std::cout << "Enter 'h' to hit or 's' to stand: ";
			std::cin >> choice;
			std::cin.ignore(255, '\n');
		} while (!(choice == 'h' || choice == 's'));
		if (choice == 's')
			break;

		dealPlayer(deck, playerScore, playerAces);

		if (playerScore > 21)
		{
			if (playerAces == 0) //if player has no more aces to "cash"
				return 0;
			else
			{
				playerAces--;
				playerScore -= 10;
				std::cout << "Your ace turns from 11 to 1.\n";
				std::cout << "Your score is now " << playerScore << ".\n";
			}
		}
		if (playerScore == 21)
			return 1;
	}

	//dealer's turn.
	std::cout << "Dealer's turn.\n";
	while (dealerScore < 17)
	{
		dealDealer(deck, dealerScore, dealerAces);

		if (dealerScore > 21 && dealerAces > 0)
		{
			dealerAces--;
			dealerScore -= 10;
			std::cout << "Dealer's ace turns from 11 to 1.\n";
			std::cout << "Dealer's score is now " << dealerScore << ".\n";
		}
	}

	//who won?
	if (dealerScore > 21 || dealerScore < playerScore)
		return 1;
	else if (dealerScore == playerScore)
		return 2;//draw
	else
		return 0;
}


int main()
{
	std::cout << "===BLACKJACK===\nBy Weiye Yang\n8th September 2017\n\n";

	//initialize deck of cards
	Deck deck;

	std::cout << "The cards are shuffled.\n";
	deck.shuffleDeck();

	//blackjack
	int result = playBlackjack(deck);
	switch (result)
	{
	case 1: std::cout << "=You win!=\n"; return 0;
	case 0: std::cout << "=Sorry, you lose.=\n"; return 0;
	case 2: std::cout << "=The game was a draw.=\n"; return 0;
	}

	return 0;
}

