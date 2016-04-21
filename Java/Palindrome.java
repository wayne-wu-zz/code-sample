//Author: Wayne Wu

public class Palindrome {

	public static boolean isPalindrome(String input){
		input = input.toLowerCase().replaceAll("[^a-z0-9]", ""); 
		return (input.equals(flip(input)));	
	}
	
	private static String flip(String word){
		return flip(word, 0, word.length()-1);
	}
	
	private static String flip(String word, int start, int end){
		/* flip string given starting index and end index */
		char[] cstring = word.toCharArray();
		flip(cstring, start, end);
		return new String(cstring);
	}
	
	private static void flip(char[] cstring, int start, int end){
		/* flip char array */
		while(start<end){
			char temp = cstring[start];
			cstring[start++] = cstring[end];
			cstring[end--] = temp;
		}
	}
	
	public static void main (String[] args) throws java.lang.Exception
	{
		System.out.println(isPalindrome("Race Car"));
	}
	
}