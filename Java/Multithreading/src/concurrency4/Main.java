package concurrency4;

//Concurrency -> Reentrant Lock

public class Main {

	public static void main(String[] args){
		
		Processor process = new Processor();
		
		Thread t1 = new Thread(new Runnable(){
			public void run(){ 
				try {
					process.threading1();
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		});
		
		Thread t2 = new Thread(new Runnable(){
			public void run(){ 
				try {
					process.threading2();
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
		
		process.finished();
		
	}
	
	
}
