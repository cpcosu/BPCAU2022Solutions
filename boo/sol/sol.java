import java.util.Scanner;

public class sol {
	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);

		int n = input.nextInt();

		String BOO = "B" + "O".repeat(n);

		System.out.println(BOO);

		input.close();
	}	
}
