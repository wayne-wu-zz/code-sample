package concurrency5;

import java.util.Random;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Processor {

	private Account account1 = new Account(); 
	private Account account2 = new Account();
	
	private Lock lock1 = new ReentrantLock();
	private Lock lock2 = new ReentrantLock();
	
	private void acquireLocks(Lock lock1, Lock lock2){
		while(true){
			// Acquire locks
			boolean gotFirstLock = false;
			boolean gotSecondLock = false;
			
			try{
				gotFirstLock = lock1.tryLock();
				gotSecondLock = lock2.tryLock();
			}
			finally{
				if(gotFirstLock && gotSecondLock)
					return;
				if(gotFirstLock)
					lock1.unlock();
				if(gotSecondLock)
					lock2.unlock();
			}
			
			//Locks not acquired
			try {
				Thread.sleep(1);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
	}
	
	public void threading1() throws InterruptedException{
		
		Random random = new Random();
		for(int i = 0; i <10000; i++){

			//*CHANGED*
			//lock1.lock(); 
			//lock2.lock();
			
			acquireLocks(lock1, lock2);
			
			try{
				Account.transfer(account1, account2, random.nextInt(100));
			}finally{
				lock1.unlock(); 
				lock2.unlock();
			}
		}		
	}
	
	public void threading2() throws InterruptedException{ 
		
		Random random = new Random(); 
		for(int i = 0; i <10000; i++){
			//lock1.lock(); //if you do lock2.lock() first you get deadlock
			//lock2.lock(); //first solution: always lock in the same order
			
			acquireLocks(lock1, lock2);
			
			try{
				Account.transfer(account2, account1, random.nextInt(100));
			}finally{
				lock1.unlock(); 
				lock2.unlock();
			}
		}
	}
	
	public void finished(){ 
		System.out.println("Account 1: " + account1.getBalance());
		System.out.println("Account 2: " + account2.getBalance());
		System.out.println("Total: " + (account1.getBalance() + account2.getBalance()));
		
	
	}
	
}
