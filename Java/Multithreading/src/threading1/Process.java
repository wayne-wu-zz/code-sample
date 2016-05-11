package threading1;

public class Process implements Runnable {
	private int id; 
	
	public Process(int id){
		this.id = id;
	}
	
	public void run(){
		for(int i = 0; i< 5; i++){
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			System.out.printf("Process %d is Running...\n", id);
		}
	}

}
