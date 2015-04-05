import java.awt.*;
import javax.swing.*;

public class Painter {
	public static void main( String[] args ){
		JFrame Painter = new JFrame( "Painter - Simple Edition" );
		PaintPanel paintPanel = new PaintPanel();
		paintPanel.setBackground( Color.WHITE );
		Painter.add( paintPanel, BorderLayout.CENTER );
		Painter.add( new JLabel( "Drag the mouse to draw" ), BorderLayout.SOUTH );
		
		Painter.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
		Painter.setSize(1280 , 720);
		Painter.setVisible(true);
	}
}
