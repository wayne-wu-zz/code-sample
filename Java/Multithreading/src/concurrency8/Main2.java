package concurrency8;

import java.util.Random;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;

public class Main2 {

	public static void main(String[] args) {
		
		Random rand = new Random();
		
		System.out.println("START");
		
		ExecutorService executor = Executors.newCachedThreadPool();
		
		Future<?> future = executor.submit(new Callable<Void>(){
			
			public Void call() throws Exception {
				for(int i = 0; i<1E7; i++){
					if(Thread.currentThread().isInterrupted()){
						System.out.println("Interrupted!");
						break;
					}
					Math.sin(rand.nextDouble());
				}
				return null;
			}			
		});
		
		executor.shutdown(); 
		
		try {
			Thread.sleep(400);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		future.cancel(true);
		//executor.shutdownNow() works as well
		
		try {
			executor.awaitTermination(10, TimeUnit.HOURS);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		System.out.println("DONE");
	}

}
