import random
from poker_cards import CARD_DECK, CARD_VALUES

class Shoe:
    def __init__(self, n_decks):
        self._n_decks = n_decks
        self.deck = CARD_DECK * n_decks

    def rand_card(self):
        random.shuffle(self.deck)
        return self.deck.pop()

    def reset(self):
        self.deck = CARD_DECK * self.n_decks

class Cardhandler:
    def __init__(self):
        self.cards_in_hand = []
        self._n_hands = 0

    def total_value(self):
        total = 0
        num_aces = self.cards_in_hand.count('A')

        for card in self.cards_in_hand:
            total += self.card_values[card]

        while total > 21 and num_aces != 0: # auto ace handling: assume 11, if bust then take as 1
            total -= 10
            num_aces -= 1

        return total

    def is_blackjack(self):
        return self.total_value == 21 and len(self.cards_in_hand) == 2
    
    def is_bust(self):
        return self.total_value() > 21
    
    def is_soft(self):
        if 'A' not in self.cards_in_hand:
            return False
        
        total_without_aces = sum(self.card_values[card] for card in self.cards_in_hand if card != 'A')
        num_aces = self.cards_in_hand.count('A')   

        if total_without_aces + 11 + (num_aces - 1) <= 21:
            return True
        
        return False

    def show_hands(self):
        return self.cards_in_hand
    
    def num_hands(self):
        return self.n_hands

    # Actions

    def hit(self, new_card, hand_index):
        self.cards_in_hand[hand_index].append(new_card)

    def stand(self):
        return -1
    
    def reset(self):
        self.cards_in_hand.clear()
        self._n_hands = 0

class Dealer(Cardhandler):
    def __init__(self):
        super().__init__()
        self._is_sufficient = False

    def up_card(self):
        if len(self.cards_in_hand) > 0:
            return self.cards_in_hand[0]
        
    def hit_threshold(self):
        total_without_aces = sum(self.card_values[card] for card in self.cards_in_hand if card != 'A')
        num_aces = self.cards_in_hand.count('A')

        # Check if we can count one Ace as 11 without busting
        if num_aces > 0 and total_without_aces + 11 + (num_aces - 1) <= 21:
            # Soft hand total
            soft_total = total_without_aces + 11 + (num_aces - 1)
            return soft_total >= 17  # True = stop hitting
        else:
            # Hard hand total
            hard_total = total_without_aces + num_aces
            return hard_total >= 17  # True = stop hitting
    
class Player(Cardhandler):
    def __init__(self):
        super().__init__()
        self._is_doubled = False
        self.bank = 0
    
    def is_doubled(self):
        return self._is_doubled
    
    def can_split(self, hand):
        if len(self.cards_in_hand[hand]) != 2:
            return False
        card1 = self.card_values[self.cards_in_hand[0]]
        card2 = self.card_values[self.cards_in_hand[1]]
        return card1 == card2
    
    def split(self, hand):
        if self.can_split(hand):
            new_hand = [self.cards_in_hand[hand].pop()]
            self._n_hands += 1
            return new_hand
        return None

    def is_doubled(self):
        return self._is_doubled
    
    def double_down():
        self._is_doubled_ = True















    
    def can_split(self):
        if len(self.cards_in_hand) != 2:
            return False
        card1 = self.card_values[self.cards_in_hand[0]]
        card2 = self.card_values[self.cards_in_hand[1]]
        return card1 == card2

    # Actions

    def add_card(self, new_card):
        self.cards_in_hand.append(new_card)

    def clear(self):
        self.cards_in_hand.clear()

    def split(self):
        if self.can_split():
            new_hand = Hand()
            new_hand.add_card(self.cards_in_hand.pop())
            new_hand.is_split = True
            self.is_split = True
            return new_hand
        return None
        
class Bet:
    def __init__(self, amount):
        self.amount = amount
        self.insurance = 0
        self._is_doubled = False
        
    # States

    def is_doubled(self):
        return self._is_doubled

    def is_surrendered(self):
        return self._is_surrendered

    # Actions

    def double_down(self):
        if not self.is_doubled:
            self.is_doubled = True
            self.amount *= 2

    def surrender(self):
        if not self._is_doubled and not self._is_surrendered:
            self.amount /= 2
            self._is_surrendered = True

    def add_insurance(self, insurance_amount):
        if insurance_amount <= self.amount / 2:
            self.insurance = insurance_amount
            return True
        return False

class Player:
    def __init__(self, bankroll):
        self.hands = []
        self.bets = []
        self.bankroll = bankroll
    
    def placebet(self):

        - buy_insurance()
        - new_card()
        - decide_action
        - settle (money)
        - split
    
