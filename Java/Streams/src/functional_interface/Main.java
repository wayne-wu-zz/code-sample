package functional_interface;

public class Main {

	public static void main(String[] args) {
		
		//simple_way();
		method_reference();
	}
	
	public static void simple_way(){ 
		Converter<Integer, String> converter = (from) -> Integer.valueOf(from);
		Integer num = converter.convert("12000");
		System.out.println(num);
		
	}
	
	public static void method_reference(){ 
		
		//"::" allows for method referencing
		
		Converter<Integer, String> converter = Integer::valueOf; //only works for functional interface
		Integer num = converter.convert("12000");
		System.out.println(num);
	}
	
}
