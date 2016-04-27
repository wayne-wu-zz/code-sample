import java.util.Iterator;

public class BlackJackHand extends Hand {
	
	private int points;
	
	public int getPoints(){
		points = 0;
		Iterator<Card> iterator = cards.iterator();
		while(iterator.hasNext()){
			Card card = iterator.next();
			int temp = card.getValue();
			if(temp == card.JACK || temp == card.QUEEN|| temp == card.KING) temp = 10;
			//TODO: Deal with ACEs
			points += temp;
		}
		return points;
	}
	
	public boolean isOver(){
		return (getPoints()>21);
	}
	
	public boolean blackJack(){
		return (getPoints() == 21);
	}
	
}
