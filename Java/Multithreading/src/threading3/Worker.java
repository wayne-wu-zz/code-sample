package threading3;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Worker {

	private Random random = new Random();
	
	private Object lock1 = new Object(); //synchronized lock is based on Object type
	private Object lock2 = new Object();
	
	private List<Integer> list1 = new ArrayList<Integer>(); 
	private List<Integer> list2 = new ArrayList<Integer>();
	
	public void modify_list1(){ 

		stall();
		synchronized(lock1){
			//synchronized code block on Lock1 
			list1.add(random.nextInt(100));
		}
	}
	
	public void modify_list2(){ 
		
		stall();
		synchronized(lock2){
			//synchronized code block on Lock2
			list2.add(random.nextInt(100));
		}
	}
	
	public void process(){ 
		for(int i = 0; i<5; i++){
			modify_list1(); 
			modify_list2();
		}
	}
	
	public void stall(){ 
		try {
			Thread.sleep(100);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void main(){ 
		Thread t1 = new Thread(new Runnable(){
			public void run(){ 
				process();
			}
		});
		Thread t2 = new Thread(new Runnable(){
			public void run(){ 
				process();
			}
		});
		Thread t3 = new Thread(new Runnable(){
			public void run(){ 
				process();
			}
		});
		
		Thread t4 = new Thread(new Runnable(){ 
			public void run(){ 
				process();
			}
		}); 

		long start = System.currentTimeMillis();
		
		t1.start(); 
		t2.start(); 
		t3.start();
		t4.start();
		
		try {
			t1.join();
			t2.join();
			t3.join();
			t4.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
		
		long end = System.currentTimeMillis();
		
		System.out.println("Time Taken:" + (end-start));
		System.out.printf("List1: %d, List2: %d\n", list1.size(), list2.size());
		
	}
	
}
