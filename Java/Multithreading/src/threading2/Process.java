package threading2;

public class Process implements Runnable{
	
	private int process_id;
	private Main app; //reference to the main app to access the shared data
	
	public Process(int id, Main app){ 
		super();
		this.process_id = id;
		this.app = app;
	}
	
	public synchronized void increment(){
		
		//modifies the shared data
		
		app.shared_data++;
		
	}
	
	public void run(){ 
		
		for(int i = 0; i< 5; i++){
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			increment();
			
			System.out.printf("Process %d: Data: %d\n", process_id, app.shared_data);
		}
	}
	
	

}
