import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class BlackJack {

	private static final int CARDS_PER_PLAYER = 2;
	private static final int MAX_PLAYERS = 10;
	private static final int DEFAULT_COMP = 2;
	
	private static final int ADD = 1;
	private static final int HOLD = 2;
	
	public BlackJackHand player;
	public ArrayList<BlackJackHand> players;
	private Deck deck; 
	
	public BlackJack(){
		players = new ArrayList<BlackJackHand>();
		player = new BlackJackHand();
		players.add(player);
		deck = new Deck(); 
	}
	
	public void generatePlayers(){
		generatePlayers(DEFAULT_COMP); 
	}
	
	public void generatePlayers(int computers){ 
		for(int i = 0; i < computers; i++)
			players.add(new BlackJackHand());
	}
	
	public void deal(int num){
		deck.shuffle();
		for(int i = 0; i< num; i++){
			Iterator<BlackJackHand> iterator = players.iterator();
			BlackJackHand temp;
			while(iterator.hasNext()){
				temp = iterator.next();
				temp.addCard(deck.dealCard());
			}
		}
	}
	
	public void deal(BlackJackHand player){
		deal(player, 1);
	}
	
	public void deal(BlackJackHand player, int num){
		for(int i = 0; i< num; i++)
			player.addCard(deck.dealCard());
	}
	
	public void retrieveCards(){
		/* Retrieve all cards from the players */
		
		Iterator<BlackJackHand> iterator = players.iterator();
		BlackJackHand temp; 
		while(iterator.hasNext()){
			temp = iterator.next();
			deck.retrieve(temp.cards);
			temp.removeAllCard();
		}
	}
	
	public void game(){
		
		deal(2);
		while(!player.isOver()){
			System.out.println(player);
			Scanner ui = new Scanner(System.in);
			System.out.println("1. Add 2. Hold");
			int selection = ui.nextInt();
			if(selection == ADD) player.addCard(deck.dealCard());
			else if(selection == HOLD) break;
		}
		
		if(player.isOver()) System.out.println("Over! (" + player + ")");
		else System.out.println("You have: " + player.getPoints() + "Points");
		
		//TODO: Add comp players
		
		retrieveCards();
	}
	
	public static void main(String[] args){
		
	}
	
	
}
