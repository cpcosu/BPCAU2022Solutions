import java.util.Scanner;

public class sol {
  // We assume the box is axis aligned and find the best answer
  // after rotating the points by some optimal theta
  public static double solve(double theta, double[] x, double[] y) {
    double minX = 2000;
    double minY = 2000;
    double maxX = -2000;
    double maxY = -2000;
    // Cache sin/cos for more speed.
    double cos = Math.cos(theta);
    double sin = Math.sin(theta);
    // Visualize the first test case under this transform!
    // https://www.desmos.com/calculator/e4zld7hhtt
    for(int i = 0; i < x.length; i++) {
      double xi = cos * x[i] + sin * y[i];
      double yi = -sin * x[i] + cos * y[i];
      minX = Math.min(minX, xi);
      maxX = Math.max(maxX, xi);
      minY = Math.min(minY, yi);
      maxY = Math.max(maxY, yi);
    }
    double answer = 2 * ((maxX - minX) + (maxY - minY));
    return answer;
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    double[] x = new double[n];
    double[] y = new double[n];
    for(int i = 0; i < n; i++) {
      x[i] = sc.nextDouble();
      y[i] = sc.nextDouble();
    }
    double bestCircumference = 100_000;

    // Just guess as to what the correct value of theta is.
    // You need to tune the increment, too large is WA
    // and too small is TLE.
    for(double theta = 0; theta < Math.PI / 2; theta += 1. / 40000) {
      bestCircumference = Math.min(solve(theta, x, y), bestCircumference);
    }
    System.out.println(Math.round(bestCircumference));
    sc.close();
  }
}
