package concurrency4;

import java.util.Scanner;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Processor {
	
	private int count = 0;
	private Lock lock = new ReentrantLock();
	private Condition cond = lock.newCondition();
	
	private void increment(){ 
		for(int i = 0; i<10000; i++)
			count++;
	}
	
	public void threading1() throws InterruptedException{
		lock.lock();
		
		System.out.println("Thread 1: Waiting...");
		cond.await(); //same as wait()
		System.out.println("Thread 1: Woke up");
		
		//Must use try-finally for lock.unlock
		try{
			increment();
		}finally{
			lock.unlock();
		}
		
	}
	
	public void threading2() throws InterruptedException{ 
		
		Thread.sleep(500);
		lock.lock();
		
		System.out.println("Thread 2: Please signal");
		new Scanner(System.in).nextLine();
		cond.signal(); //same as notify()
		System.out.println("Thread 2: Signaled");
		
		try{
			increment();
		}finally{
			lock.unlock();
		}
	}
	
	public void finished(){ 
		System.out.println("Count: "+ count);
	}
	
}
