package threading1;

//Simple Thread execution using Runnable

public class Main {

	public static void main(String[] args){
		Thread t1 = new Thread(new Process(1));
		Thread t2 = new Thread(new Process(2));
		Thread t3 = new Thread(new Process(3));
		
		t1.start(); 
		t2.start(); 
		t3.start();
			
		//thread.join() waits until the thread's done executing
		try {
			t1.join();
			t2.join();
			t3.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		System.out.println("DONE");
		
	}
}
