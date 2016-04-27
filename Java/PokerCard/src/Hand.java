
import java.util.ArrayList;
import java.util.Iterator;

public class Hand {
	/* Object representing a player's hand */
	
	protected ArrayList<Card> cards;
	protected static final int MAX_NUM_CARDS = 5;
	
	public Hand(){
		cards = new ArrayList<Card>();
	}
	
	public void addCard(Card c){
		if(cards.size()<=MAX_NUM_CARDS) cards.add(c);
	}
	
	public void removeCard(Card c){
		cards.remove(c);
	}
	
	public void removeAllCard(){
		cards.clear();
	}
	
	public int getCardCount(){
		return cards.size();
	}
	
	public Card getCard(int index){
		if(isValid(index)) return cards.get(index);
		else return null;
	}
	
	private boolean isValid(int index){
		return (index >= 0 || index < cards.size());
	}
	
	public String toString(){		
		/* Display all cards */
		Iterator<Card> iterator = cards.iterator();
		String text = "";
		while(iterator.hasNext()){
			Card temp = iterator.next();
			text += (temp.toString()+",") ;
		}
		return text;
	}
	
}
