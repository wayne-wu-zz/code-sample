package concurrency8;

import java.util.Random;

//Interrupting using thread.interrupt();

public class Main1 {

	public static void main(String[] args){ 
		
		Random rand = new Random();
		
		Thread t1 = new Thread(new Runnable(){
			public void run(){
				for(int i = 0; i<1E7; i++){
					if(Thread.currentThread().isInterrupted()){
						System.out.println("Interrupted!");
						break;
					}
					Math.sin(rand.nextDouble());
				}
			}
		});
		
		System.out.println("START");
		
		t1.start(); 
		
		try {
			Thread.sleep(400);
		} catch (InterruptedException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		t1.interrupt(); 
		
		try {
			t1.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		System.out.println("DONE");
	}
	
}
