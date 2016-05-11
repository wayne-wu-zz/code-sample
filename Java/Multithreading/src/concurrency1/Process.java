package concurrency1;

public class Process implements Runnable {
	
	private int id; 
	
	public Process(int id){
		this.id = id;
	}
	
	public void run(){ 
		System.out.println("Starting: " + id);
		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println("Completed: " + id);
	}
	
}
