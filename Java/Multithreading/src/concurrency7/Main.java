package concurrency7;

import java.util.Random;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

//Concurrency.Callable and Futures
//Use Callable if you want to return variables


public class Main {

	public static void main(String[] args){
		
		ExecutorService executor = Executors.newCachedThreadPool();
		
		Future<Integer> future = executor.submit(new Callable<Integer>(){
			
			public Integer call() throws Exception {
				
				System.out.println("Starting process...");
				
				Random rand = new Random();
				int duration = rand.nextInt(2000);
				
				//throw new exception if duration is divisible by 3
				if(duration%3==0){
					throw new ThreadException("Divisible by 3: " + duration);
				}
				
				
				Thread.sleep(duration);
				
				System.out.println("Completed.");
				
				return duration;
			}
			
		});
		
		executor.shutdown();
		
		try {
			/*future.get() automatically waits until the executor is terminated
			 *therefore no need for executor.awaitTermination...
			 */
			System.out.println("Duration: "+ future.get());
		} catch (InterruptedException e) {
			e.printStackTrace();
		} catch (ExecutionException e) {
			System.out.println(e.getMessage());
		}
	}
	
}
