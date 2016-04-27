
public class Card {
	
	/*Object for one individual card*/
	
	public final int SPADES = 0, 
					 HEARTS = 1,
					 DIAMONDS = 2,
					 CLUBS = 3;
	
	public final int ACE = 1,
					 KING = 13,
					 QUEEN = 12,
					 JACK = 11;
	
	private final int suit;
	private final int value;
	
	public Card(int theValue, int theSuit){
		value = theValue; 
		suit = theSuit;
	}
	
	public int getSuit(){
		return suit;
	}
	public int getValue(){
		return value;
	}
	
	public String getSuitAsString(){
		switch(suit){
		case 0: return "Spades"; 
		case 1: return "Hearts";
		case 2: return "Diamonds"; 
		case 3: return "Clubs";
		default: return "??";
		}
	}
	
	public String toString(){
		return getValue() + ":" + getSuitAsString();
	}
	
	
}
