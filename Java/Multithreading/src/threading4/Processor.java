package threading4;

import java.util.LinkedList;
import java.util.Random;

public class Processor {

	private LinkedList<Integer> list = new LinkedList<Integer>();
	private final int LIMIT = 10;
	private Object lock = new Object();
	
	public void producer() throws InterruptedException{ 
		//add value to list
		Random random = new Random(); 
		while(true){ 
			synchronized(lock){
				while(list.size() == LIMIT)
					lock.wait();
				list.add(random.nextInt(10));
				lock.notify(); //Wake up the other Thread
			}
		}	
	}
	
	public void consumer() throws InterruptedException{ 
		//remove value from list
		Random random = new Random();
		
		while(true){
			synchronized(lock){
				while(list.size() == 0)
					lock.wait();
				System.out.print("Size: " + list.size());
				int num = list.removeFirst();
				System.out.println(" Value: " + num);
				lock.notify();
			}
			
			Thread.sleep(random.nextInt(1000));
		}
	}
	
	
}
