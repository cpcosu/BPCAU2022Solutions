import java.util.Scanner;
import java.lang.Math;

public class sol {

	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		
		int numberOfBuckets = in.nextInt(), numberOfCandies = in.nextInt();

		int[] candyArray = new int[numberOfCandies];

		for(int i = 0; i < numberOfCandies; i++){
			candyArray[i] = in.nextInt();
		}

		in.close();

		int lowest = 1;
		int highest = candyArray[0];

		for(int i = 1; i < numberOfCandies; i++){
			if(candyArray[i] > highest){
				highest = candyArray[i];
			}
		}

		// Binary search to awnser

		while(lowest != highest){
			// Middle is max amount per bucket for this iteration
			int middle = (lowest + highest) / 2;

			int totalNumberBuckets = 0;

			for(int i = 0; i < numberOfCandies; i++){
				double numBuckets = ((double) candyArray[i]) / ((double) middle);
				totalNumberBuckets += (int) (Math.ceil(numBuckets));
			}

			if(totalNumberBuckets > numberOfBuckets){
				lowest = middle + 1;
			}else{
				highest = middle;
			}
		}

		System.out.println(lowest);

	}
}