import javax.swing.JOptionPane;

public class Addition {
	public static void main( String[] args ){
		String firstNumber = JOptionPane.showInputDialog("Enter first integer");
		String secondNumber = JOptionPane.showInputDialog( "Enter second integer" );
		int num1, num2;
		num1 = Integer.parseInt( firstNumber );
		num2 = Integer.parseInt( secondNumber );
		int sum = num1 + num2;
		JOptionPane.showMessageDialog( null, "the sum is " + sum, "sum of tow integers", JOptionPane.PLAIN_MESSAGE );
	}
}
