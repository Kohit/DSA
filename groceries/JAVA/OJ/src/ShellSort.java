import java.util.Scanner;

public class ShellSort {
	public static void sort( int[] a, int N, int[] range, int step ){
		for ( int k = 0; k < step; k++ ){
			for ( int i = range[k]; i < N; i++ )
				for ( int j = i; j >= range[k] && a[j] < a[j - range[k]]; j -= range[k] ){
					int t = a[j]; a[j] = a[j - range[k]]; a[j - range[k]] = t;
				}
			for ( int i = 0; i < N; i++ )
				System.out.print( a[i] + " " );
			System.out.println();
		}
	}
	public static void main( String[] args ){
		Scanner input = new Scanner( System.in );
		int N = input.nextInt();
		int step = input.nextInt();
		int[] range = new int[21];
		for ( int i = 0; i < step; i++ )
			range[i] = input.nextInt();
		int[] a = new int[ 100005 ];
		for ( int i = 0; i < N; i++ )
			a[i] = input.nextInt();
		sort( a, N, range, step );
	}
}
