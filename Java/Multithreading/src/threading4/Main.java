package threading4;

//Low-Level Synchronization (Wait & Notify): Producer-Consumer example

public class Main {

	public static void main(String[] args){
		
		Processor process = new Processor();
		
		Thread t1 = new Thread(new Runnable(){
			public void run(){
				try {
					process.producer();
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		});
		
		Thread t2 = new Thread(new Runnable(){
			public void run(){ 
				try {
					process.consumer();
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		});
		
		t1.start();
		t2.start();
		
		try {
			t1.join();
			t2.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		System.out.println("DONE");
		
	}
	
}
