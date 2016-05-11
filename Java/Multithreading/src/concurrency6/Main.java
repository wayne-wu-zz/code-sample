package concurrency6;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;


//Concurrency.Semaphore Example

public class Main {

	public static void main(String[] args){
		
		ExecutorService executor = Executors.newCachedThreadPool(); //newCachedThreadPool vs newFixedThreadPool?
		Connection connector = Connection.getInstance();
		
		for(int i =0 ; i<200; i++){
			executor.submit(new Runnable(){
				public void run(){ 
					connector.connect();
				}
			});
		}
		
		executor.shutdown(); 
		try {
			executor.awaitTermination(10, TimeUnit.HOURS);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		System.out.println("DONE");
		
		
	}
	
}
