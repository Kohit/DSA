import java.util.Scanner;

public class QuickSort {
	public static void qsort( int[] a, int lo, int hi, int N ){
		if ( hi <= lo ) return;
		int j = partition( a, lo, hi );
		for ( int i = 0; i < N; i++ )
			System.out.print( a[i] + " " );
		System.out.println();
		qsort( a, lo, j - 1, N );
		qsort( a, j + 1, hi, N );
	}
	public static int partition( int[] a, int lo, int hi ){
		int i = lo, j = hi + 1;
		int v = a[lo];
		while( true ){
			while( a[ ++i ] < v ) if ( i == hi ) break;
			while( v < a[ --j ] ) if ( j == lo ) break;
			if ( i >= j ) break;
			int t = a[j]; a[j] = a[i]; a[i] = t;
		}
		int t = a[lo]; a[lo] = a[j]; a[j] = t;
		return j;
	}
	public static void qsort3way( int[] a, int lo, int hi, int N ){
		if ( hi <= lo ) return;
		int lt = lo, i = lo + 1, gt = hi;
		int v = a[lo];
		while( i <= gt ){
			if ( a[i] < v ){
				int t = a[i];a[i] = a[lt]; a[lt] = t;
				lt++; i++;
			}
			else if ( a[i] > v ){
				int t = a[i]; a[i] = a[gt]; a[gt] = t;
				gt--;
			}
			else
				i++;
		}
		for ( int k = 0; k < N; k++ )
			System.out.print( a[k] + " " );
		System.out.println();
		qsort3way( a, lo, lt - 1, N );
		qsort3way( a, gt + 1, hi, N );
	}
	public static void main( String[] args ){
		Scanner input = new Scanner( System.in );
		int N = input.nextInt();
		int[] a = new int[ 100005 ];
		for ( int i = 0; i < N; i++ )
			a[i] = input.nextInt();
		qsort3way( a, 0, N - 1, N );
	}
}
