import java.util.*;

public class HeapSort {
	public static void swim( int[] a, int k, int N ){
		while( k > 1 && a[k / 2] < a[k] ){
			int t = a[k]; a[k] = a[k / 2]; a[k / 2] = t;
			k = k / 2;
		}
	}
	public static void sink( int[] a, int k, int N ){ // sink the a[k] if it smaller than its sons
		while ( 2 * k <= N ){
			int j = 2 * k;
			if ( j < N && a[j] < a[j + 1] ) j++;   // find the biggest son of k
			if ( a[k] >= a[j] ) break;
			int t = a[k]; a[k] = a[j]; a[j] = t;   // exchange (a[k], a[j]) ( a[j] > a[k] )
			k = j;   // continue to find a[k]'s final position
		}
	}
	public static void heapSort( int[] a ){
		int N = a.length - 1;
		for ( int k = N / 2; k >= 1; k-- ){ // construct the sub heap
			sink( a, k, N );
		}
		while( N > 1 ){ // broke the heap
			int t = a[1]; a[1] = a[N]; a[N] = t; 
			// a[1] always the biggest among (1, N), so change it to the position N
			N--;  // N is stable, but N - 1 not, so let N be N - 1
			sink( a, 1, N ); 
			// to make sure a[1] is the biggest among ( 1, N ), notice: N would change
			for ( int i = 1; i < a.length; i++ )
				System.out.print( a[i] + " " );
			System.out.println();
		}
	}
	public static void main( String[] args ){
		Scanner input = new Scanner( System.in );
		int N = input.nextInt();
		int[] a = new int[N + 1];
		for ( int i = 1; i <= N; i++ )
			a[i] = input.nextInt();
		heapSort( a );
		input.close();
	}
}

// priority queue
/*
 * key[] pq; int N = 0;
 * 
 * insert (key v):
 * pq[++N] = v;  // let pq[0] be empty 
 * swim(N).
 * 
 * deleteMax:
 * key max = pq[1];
 * exch( 1, N-- );
 * pq[N + 1] = null;  // prevent out of bound
 * sink(1);  // restore heap's order
 * return max;
 * 
 * */