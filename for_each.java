 class For_Each	 
{ 
	public static void main(String[] arg) 
	{ 
		{ 
			int[] marks = { 100, 300, 200, 500, 400 }; 
			
			int highest_marks = maximum(marks); 
			System.out.println("The highest score is " + highest_marks); 
		} 
	} 
	public static int maximum(int[] numbers) 
	{ 
		int maxSoFar = numbers[0]; 
		
		// for each loop 
		for (int num : numbers) 
		{ 
			if (num > maxSoFar) 
			{ 
				maxSoFar = num; 
			} 
		} 
	return maxSoFar; 
	} 
} 
