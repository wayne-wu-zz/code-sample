package functional_interface;

@FunctionalInterface //good practice to include the decorator
public interface Converter<To, From> {

	To convert(From input); 
	
}
