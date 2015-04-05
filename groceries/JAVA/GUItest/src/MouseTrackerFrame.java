import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MouseTrackerFrame extends JFrame{
	private JPanel mouse;
	private JLabel statusBar;
	
	public MouseTrackerFrame(){
		super( "Demonstarting Mouse Events" );
		
		mouse = new JPanel();
		mouse.setBackground( Color.WHITE );
		add( mouse, BorderLayout.CENTER );
		
		statusBar = new JLabel( "Mouse outside JPanel" );
		add( statusBar, BorderLayout.SOUTH );
		
		MouseHandler handler = new MouseHandler();
		mouse.addMouseListener( handler );
		mouse.addMouseMotionListener( handler );
	}
	private class MouseHandler implements MouseListener, MouseMotionListener{
		public void mouseClicked( MouseEvent event ){
			statusBar.setText(  String.format( "Clicked at [%d, %d]" , event.getX(), event.getY()));
		}
		public void mousePressed( MouseEvent event ){
			statusBar.setText( String.format( "Pressed at [%d ,%d]", event.getX(), event.getY()) );
		}
		public void mouseReleased( MouseEvent event ){
			statusBar.setText( String.format( "Released at [%d, %d]", event.getX(), event.getY() ) );
		}
		public void mouseEntered( MouseEvent event ){
			statusBar.setText( String.format( "Mouse entered at [%d, %d]" , event.getX(), event.getY()) );
			mouse.setBackground( Color.PINK );
		}
		public void mouseExited( MouseEvent event ){
			statusBar.setText( String.format( "Mouse outside JPanel" ) );
			mouse.setBackground( Color.GRAY );
		}
		public void mouseDragged( MouseEvent event ){
			statusBar.setText( String.format( "Dragged at [%d, %d]", event.getX(), event.getY() ) );
		}
		public void mouseMoved( MouseEvent event ){
			statusBar.setText( String.format( "Moved at [%d, %d]", event.getX(), event.getY() ) );
		}
	}
}
