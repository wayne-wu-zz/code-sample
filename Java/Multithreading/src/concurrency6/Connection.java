package concurrency6;

import java.util.concurrent.Semaphore;

//Basic singleton pattern

public class Connection {

	private static Connection instance = new Connection();
	private final int LIMIT = 20;
	private int connections = 0;
	private Semaphore sem = new Semaphore(LIMIT);
	
	private Connection(){ 
		
	}
	
	public static Connection getInstance(){ 
		return instance;
	}
	
	
	public void connect(){ 
		
		/* Allow semaphore to be released if _connect throws exception */
		
		try {
			sem.acquire();
		} catch (InterruptedException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		
		try{
			_connect();
		}
		finally{
			sem.release();
		}
	}
	
	private void _connect(){ 
		/* Stimulate connection */

		synchronized(this){
			connections++;
		}

		System.out.println("Connections: " + connections);
		
		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		synchronized(this){
			connections--;
		}

	}
	
	
}
