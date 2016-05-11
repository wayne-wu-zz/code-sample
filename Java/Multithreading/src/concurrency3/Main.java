package concurrency3;

//Concurrency.BlockingQueue: Producer/Consumer example

public class Main {
	
	public static void main(String[] args){
		
		Worker app = new Worker();
		
		Thread t1 = new Thread(new Runnable(){
			public void run(){
				try {
					app.producer();
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		});
		
		Thread t2 = new Thread(new Runnable(){
			public void run(){ 
				try {
					app.consumer();
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
