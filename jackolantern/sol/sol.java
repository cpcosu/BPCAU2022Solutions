import java.util.Scanner;

public class sol {

	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		
		int heightOfEyes = in.nextInt(), numberOfTeeth = in.nextInt();
		int totalWidth = heightOfEyes*4+2;

		for(int i = 0; i < heightOfEyes - 1; i++){
			int spaceOnOutside = heightOfEyes - 1 - i;
			String eyeString = " ".repeat(spaceOnOutside) + "/" + " ".repeat(i*2) + "\\" + " ".repeat(spaceOnOutside);
			System.out.println(eyeString + "  " + eyeString);
		}
		String eyeString = "/" + "_".repeat(heightOfEyes*2 - 2) + "\\";
		System.out.println(eyeString + "  " + eyeString);

		System.out.println(" ".repeat(totalWidth));

		String edgeSpace = " ".repeat((totalWidth - numberOfTeeth*2) / 2);
		System.out.println(edgeSpace + "\\/".repeat(numberOfTeeth) + edgeSpace);
		System.out.println(edgeSpace + "/\\".repeat(numberOfTeeth) + edgeSpace);
    in.close();
	}
}