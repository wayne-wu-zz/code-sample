import java.util.ArrayList;
import java.util.Random;

public class Deck {
	
	/* Object representing one deck of cards */ 
	
	private static final int TOTAL = 52;
	private ArrayList<Card> cards;
	
	public Deck(){
		//create a new deck of card
		cards = new ArrayList<Card>();	
		for(int i = 1; i<=13; i++){
			cards.add(new Card(i, 0));
			cards.add(new Card(i, 1)); 
			cards.add(new Card(i, 2));
			cards.add(new Card(i, 3));
		}
	}
	
	public void shuffle(){
		//shuffle the list of card
		Random rand = new Random();
		for(int i = 0; i<cards.size(); i++){
			swap(i, rand.nextInt(cards.size()));
		}
	}
	
	private void swap(int i, int j){
		Card temp = cards.get(i);
		cards.set(i, cards.get(j));
		cards.set(j, temp);
	}
	
	public int cardsLeft(){
		return cards.size();
	}
	
	// Get either the first card of the deck, or a specified position
	public Card getCard(){
		if(cardsLeft()>0) return cards.get(0);
		else return null;
	}
	
	public Card getCard(int index){
		if(cardsLeft()>0) return cards.get(index);
		else return null;
	}
		
	public Card dealCard(){
		Card card = getCard();
		cards.remove(0);
		return card;
	}
	
	public Card dealCardAtRandom(){
		Random rand = new Random();
		int index = rand.nextInt(cardsLeft());
		Card card = getCard(rand.nextInt(cardsLeft()));
		cards.remove(index);
		return card;	
	}
	
	public void retrieve(Card card){
		cards.add(card);
	}
	
	public void retrieve(ArrayList<Card> retrieved_cards){
		cards.addAll(retrieved_cards);
	}
}
