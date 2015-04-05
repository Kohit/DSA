import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MouseDetailsFrame extends JFrame{
	private String details;
	private JLabel statusBar;
	
	public MouseDetailsFrame(){
		super( "Mouse Click and buttons" );
		
		statusBar = new JLabel( "Click the mouse" );
		add( statusBar, BorderLayout.SOUTH );
		addMouseListener( new MouseClickHandler() );
	}
	private class MouseClickHandler extends MouseAdapter{
		public void mouseClicked( MouseEvent event ){
			int x = event.getX();
			int y = event.getY();
			details = String.format( "Clicked %d times", event.getClickCount());
			if ( event.isMetaDown() )
				details += " with right mouse button";
			else if ( event.isAltDown() )
				details += " with center mouse button";
			else
				details += " with left mouse button";
			statusBar.setText( details );
		}
	}
}
