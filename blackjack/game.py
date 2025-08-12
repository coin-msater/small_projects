import random

class Shoe:
    def __init__(self, n_decks):
        self.n_decks = n_decks
        self.deck = ['2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A'] * n_decks * 4
    
    def draw(self):
        card = random.choice(self.deck)
        self.deck.remove(card)
        return card

    def reset(self):
        self.deck = ['2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A'] * n_decks * 4

class Hand:
    def __init__(self):
        self.cards_in_hand = []
        self.is_split = False
        self.card_values = {'2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, '10': 10, 'J': 10, 'Q': 10, 'K': 10, 'A': 11}

    def total_value(self):
        total = 0
        num_aces = self.cards_in_hand.count('A')

        for card in self.cards_in_hand:
            total += self.card_values[card]

        while total > 21 and num_aces != 0: # auto ace handling: assume 11, if bust then take as 1
            total -= 10
            num_aces -= 1

        return total

    def add_card(self, new_card):
        self.cards_in_hand.append(new_card)

    def is_blackjack(self):
        return self.total_value == 21

    def is_potential_blackjack(self):
        return len(self.cards_in_hand) == 2 and ('A' in self.cards_in_hand or self.total_value == 10)
    
    def is_soft(self):
        if 'A' not in self.cards_in_hand:
            return False
        
        total_without_aces = sum(self.card_values[card] for card in self.cards_in_hand if card != 'A')
        num_aces = self.cards_in_hand.count('A')   

        if total_without_aces + 11 + (num_aces - 1) <= 21:
            return True
        
        return False
             
    def is_bust(self):
        return self.total_value() > 21
    
    def can_split(self):
        pass
    def clear(self):
        self.cards_in_hand.clear()

    def split(self):
        pass