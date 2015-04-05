/*
 * Ass1.java
 *
 *  Created on: 2015Äê3ÔÂ19ÈÕ
 *      Author: FongYoung Vane
 */

package ass1;
import java.util.Scanner;

public class Ass1 {	
		public static void main( String args[] ){
			Scanner in = new Scanner( System.in );
			System.out.println( "ass 1-1, max number" );
			System.out.println( "enter 3 numbers:" );
			bigger( in.nextInt(), in.nextInt(), in.nextInt() );
			System.out.println( "ass 1-2, score level" );
			System.out.println( "enter the level, A ~ D" );
			score( in.next().charAt( 0 ) );
			System.out.println( "ass 1-3, sale" );
			System.out.println( "enter your sale" );
			sale( in.nextInt() );
			in.close();
		}
		public static void bigger( int a, int b, int c ) {
			int max = a >= b ? a : b;
			if ( max >= c )
				System.out.printf( "%d\n", max );
			else
				System.out.printf( "%d\n", c );
		}
		public static void score( char level ){
			switch( level ){
			case 'A': System.out.println( "90 ~ 100" ); break;
			case 'B': System.out.println( "80 ~ 89" ); break;
			case 'C': System.out.println( "60 ~ 79" ); break;
			case 'D': System.out.println( "< 60" ); break;
			default: System.out.println( "unknow command" );
			}
		}
		public static void sale( int count ){
			if ( count <= 5000 )
				System.out.println( count * 0.08 );
			else if ( count <= 10000 )
				System.out.println( count * 0.1 );
			else if ( count > 10000 )
				System.out.println( count * 0.12 );
		}
}
