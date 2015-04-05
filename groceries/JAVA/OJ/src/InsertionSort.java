import java.util.Scanner;

public class InsertionSort {
	public static void sort( int[] a, int N ){
		for ( int i = 1; i < N; i++ ){
			for ( int j = i; j > 0 && a[j] > a[j - 1]; j-- ){
				int t = a[j]; a[j] = a[j - 1]; a[j - 1] = t;
			}
			for ( int k = 0; k < N; k++ )
				System.out.print( a[k] + " " );
			System.out.println();
		}
	}
	public static void main( String[] args ){
		Scanner input = new Scanner( System.in );
		int N = input.nextInt();
		int[] a = new int[ 100005 ];
		for ( int i = 0; i < N; i++ )
			a[i] = input.nextInt();
		sort( a, N );
	}
}
