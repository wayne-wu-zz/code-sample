package concurrency2;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicInteger;


//Using ExecutorService with shared data

public class Main {

	public volatile int shared_data;
	
	public Main(){ 
		this.shared_data = 0;
	}
	
	public static void main(String[] args){
		
		Main app = new Main(); 
		
		ExecutorService execute = Executors.newFixedThreadPool(2);
		
		for(int i = 1; i<6; i++){
			execute.submit(new Process(i, app));
		}
		
		execute.shutdown();
		
		try {
			execute.awaitTermination(10, TimeUnit.HOURS);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		System.out.println("DONE");
		System.out.println(app.shared_data);
		
	}
}
