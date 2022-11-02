import java.util.Scanner;

public class sol {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		String line = in.nextLine();
		int len = line.length();

		int b_count = 0;
		for(int i = 0; i < len; i++){
			if(line.charAt(i) == 'B') {
				b_count++;
			}
		}
		if(len % 3 == 0 && b_count * 3 == len){ // 3:
			System.out.println("):");
		}else{
			System.out.println("AHH");
		}
    	in.close();
	}
}