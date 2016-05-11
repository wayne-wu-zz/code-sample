package threading1;

public class Process1 implements Runnable{
	
	public void run(){ 
		for(int i = 0; i< 5; i++){
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			System.out.println("Process 1 is Running");
		}
		
	}
	
	
}
