Elementary rules of a simple blackjack game:

1. Card Values:
- Number cards (2-10): Worth their face value.
- Face cards (Jack, Queen, King): Worth 10.
- Ace: Can be worth 1 or 11, depending on what benefits the hand.  

2. Sequence of game
    2.1 Start of the game
        - Player places a bet (10)
        - Dealer deals 2 cards to the player and himself, of which both the player's cards are known, and one of the dealer's cards is known.

    2.2 Player's choice
        - The player could:
            2.2.1 Hit: Taking another card
            2.2.2 Stand: Keep their current cards
            2.2.3 Double down: Double the bet and taking EXACTLY one more card.
            2.2.4 Split: Split the hand into 2 seperate hands, placing a matching bet on the second hand. COND: 2 of the same initial cards.
                2.2.4.1 Special: Split aces would only receive 1 more card in each hand, with no hitting allowed.
            2.2.5 Early Surrender: Surrender after the first 2 cards and lose half the bet.
            2.2.6 Insurance: COND: If the dealer has an ace, player could buy insurance (up to half the initial bet) against a potential blackjack of the dealer. Insurance pays 2:1 if dealer hits a blackjack.

    2.3 Dealer's choice
        - Dealer checks for blackjack, player surrender is allowed.
        - Dealer reveals his second card, and:
            2.3.1 Hit: COND: 2 cards total 16 or less
            2.3.2 Stand: COND: 2 cards total at least 17

    2.4 Special cases:
        2.4.1 Late surrender: Player surrenders and lose half the bet, COND: the dealer has ace or 10 up, checks the hole card and there is NO blackjack.

3. Game outcomes
    3.1 Wins
        3.1.1 Win (Natural): If player's hand totals more than the dealer's hand, pays 1:1.
        3.1.2 Win (Blackjack): If player hits a blackjack in the first 2 cards (ace and 10), pays 3:2. 
        3.1.3 Win (Dealer bust): Dealer draws more than 21 while the player has less than 21.
        3.1.4 Win (Doubled down): Pays 2:1.
        3.1.5 Win (Blackjack, split hand): Pays 1:1.
    
    3.2 Ties
        3.2.1 Tie/Push: If the player's hand and the dealer's hand are equal, bets are returned.
        3.2.2 Tie/Push (Blackjack): If both the player and dealer hits a blackjack, bets are returned.
    
    3.3 Losses
        3.3.1 Loss (Player bust): If player busts, loses whole bet.
        3.3.2 Loss (Natural): Player totals less than that of the dealers, with no blackjacks, loses whole bet.
        3.3.3 Loss (Dealer blackjack): Loses whole bet.
        3.3.4 Loss (Surrender): Loses half the bet.
        
    3.4 Special cases:
        3.4.1 Insurance win: If dealer blackjacks, pays 2:1 with respect to insurance amount.
        3.4.2 Insurance loss: Loses insured amount.

Structure, from small to big:

1.1 class Deck:
    - cards

    - draw()
    - reset()

    1.2 class Shoe: (the shoe can be multiple decks)
        - n_decks
        - cards

        - draw() (take card and remove)


2. Players:
    2.1 class Hand:
        - cards_in_hand (all we need to store is this, all other info is derived.)
        - is_split

        - total()
        - add_card()
        - is_blackjack()
        - is_potential_blackjack()
        - is_soft()
        - is_bust()
        - can_split()
        - clear()
        - split()


    2.2 class Bet:
        - bet_amount
        - insurance

        - double_down()
        - is_doubled()
        - surrender()
        - add_insurance()

    2.3 class Player:
        - hands (if split then have multiple hands)
        - bets (if split then have multiple bets)
        - bankroll

        - placebet() Bet
        - buy_insurance() Bet
        - new_card() card from Shoe
        - settle (money) Bet
        - split

    2.4 class Dealer:
        - hand

        - peak_for_blackjack
        - play() (deal)
        - up_card()

3. Game:

    3.1 class Game:
        - shoe
        - player
        - dealer
        
        - start_round()
        - resolve_insurance()
        - player_turn()
        - dealer_turn()
        - settle_bet
        - handle_split()
