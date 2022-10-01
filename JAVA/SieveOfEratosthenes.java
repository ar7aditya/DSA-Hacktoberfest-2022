import java.util.Arrays;

public class SieveOfEratosthenes {
	public static void main(String[] args) {
		int n = 10;
		boolean[] primeSieve = new boolean[n + 1];
		Arrays.fill(primeSieve, true);
		primeSieve[0] = false;
		primeSieve[1] = false;
		for (int i = 2; i * i <= n; i++) {
			if (primeSieve[i] == true) {
				// This line makes all the numbers divisble by i false.
				for (int j = i * 2; j <= n; j += i) {
					primeSieve[j] = false;
				}
			}
		}
		// System.out.println(Arrays.toString(primeSieve));
		for (int k = 0; k < primeSieve.length; k++) {
			if (primeSieve[k] == true) {
				System.out.print(k + " ");
			}
		}
	}

	static boolean isPrime(int n) {
		if (n <= 1) {
			return false;
		}
		int cnt = 1;
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				cnt++;
			}
		}
		if (cnt != 1) {
			return false;
		}
		return true;
	}

}
