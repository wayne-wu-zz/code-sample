package threading2;

//Using the synchronized keyword to deal with shared data 

public class Main {

	public int shared_data;
	
	public Main(){ 
		shared_data = 0;
	}
	
	public static void main(String[] args){
		doWork();
	}
	
	public static void doWork(){
		
		Main app = new Main();
		Thread t1 = new Thread(new Process(1, app));
		Thread t2 = new Thread(new Process(2, app));
		
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
