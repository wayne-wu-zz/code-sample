package concurrency1;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit; 

//Simple Runnable using ExecutorService

public class Main {

	public static void main(String[] args){
		
		ExecutorService executor = Executors.newFixedThreadPool(3); //FactoryMethod for creating Thread Pool; 
		
		for(int i = 0; i<5; i++){
			executor.submit(new Process(i));
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
