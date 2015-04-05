/*
 * Ass2.java
 *
 *  Created on: 2015Äê3ÔÂ19ÈÕ
 *      Author: FongYoung Vane
 */

package ass2;

public class Ass2 {
	static int N[] = { 1, 2, 3, 4, 5 };
	public static void main( String args[] ){
		useFor();
		useWhile();
		useDWhile();
		Factorial();
	}
	public static void useFor(){
		System.out.println( "use 'for' loop" );
		System.out.println( "N\t10*N\t100*N\t1000*N" );
		for ( int i : N ){
			for ( int j = 0; j++ < 4; i *= 10 )
				System.out.printf( "%d\t", i );
			System.out.println();
		}
	}
	public static void useWhile(){
		System.out.println( "use 'while' loop" );
		System.out.println( "N\t10*N\t100*N\t1000*N" );
		int i = 0;
		while( i < N.length ){
			int num = N[i++];
			for ( int j = 0; j++ < 4; num *= 10 )
				System.out.printf( "%d\t", num );
			System.out.println();
		}
	}
	public static void useDWhile(){
		System.out.println( "use 'do-while' loop" );
		System.out.println( "N\t10*N\t100*N\t1000*N" );
		int i = 0;
		do{
			int num = N[i++];
			for ( int j = 0; j++ < 4; num *= 10 )
				System.out.printf( "%d\t", num );
			System.out.println();
		}while( i < N.length );
	}
	public static void Factorial(){
		System.out.println( "Factorial from 1! ~ 10!" );
		for ( int i = 1; i <= 10; i++ ){
			int fac = 1;
			for ( int j = 2; j <= i; j++ )
				fac *= j;
			System.out.println( i + "! = " + fac );
		}
	}
}
