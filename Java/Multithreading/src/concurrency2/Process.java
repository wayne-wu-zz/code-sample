package concurrency2;

public class Process implements Runnable {

	private int id; 
	private Main app;
	
	
	public Process(int id, Main app){ 
		this.id = id;
		this.app = app;
	}
	
	public synchronized void increment(){ 
		app.shared_data++;
	}
	
	
	public void run(){
		try {
			Thread.sleep(1000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		int before = app.shared_data; // the first may read the same data
		
		increment();
		
		int after = app.shared_data;
		
		System.out.printf("Process %d: %d -> %d \n", id, before, after);
	}
	
}
