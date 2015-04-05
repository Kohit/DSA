import java.io.*;
import java.net.*;
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class ChatServer extends JFrame{
	private JTextField enterField;
	private JTextArea displayArea;
	private ObjectOutputStream output;
	private ObjectInputStream input;
	private ServerSocket server;
	private Socket connection;
	private String nickname;
	private String user;
	private int counter = 1;
	
	public ChatServer( String name ){
		super( "Chat Server" );
		nickname = name;
		enterField = new JTextField( "enter message here" );
		enterField.setEditable( false );
		enterField.addActionListener( 
			new ActionListener(){
				public void actionPerformed( ActionEvent event ){
					sendData( event.getActionCommand() );
					enterField.setText( "" );
				}
			}
		);
		add( enterField, BorderLayout.SOUTH );
		displayArea = new JTextArea();
		add( new JScrollPane( displayArea ) );
		setSize( 800, 480 );
		setVisible( true );
	}
	
	public void runServer(){
		try{
			server = new ServerSocket( 12345, 100 );
			while ( true ){
				try{
					waitForConnection();
					getStreams();
					processConnection();
				}
				catch( EOFException e ){
					displayMessage( "\nServer terminated connection\n" );
				}
				finally{
					closeConnection();
					counter++;
				}
			}
		}
		catch( IOException e ){
			e.printStackTrace();
		}
	}
	private void waitForConnection() throws IOException {
		displayMessage( "Waiting for connection\n" );
		connection = server.accept();
		displayMessage( "Connection " + counter + " received from: " + connection.getInetAddress().getHostName() );
	}
	private void getStreams() throws IOException{
		output = new ObjectOutputStream( connection.getOutputStream() );
		output.flush();
		input = new ObjectInputStream( connection.getInputStream() );
		displayMessage( "\nGot I/O streams\n\n" );
		output.writeObject( nickname );
		output.flush();
		try{
			user =  ( String ) input.readObject();
		}catch ( ClassNotFoundException e ){
			displayMessage( "get user name failed\n" );
		}
	}
	private void processConnection() throws IOException{
		String message = "";
		setTextFieldEditable( true );
		do{
			try{
				message = ( String ) input.readObject();
				displayMessage( user + " : \n" + message + "\n\n" );
			}
			catch ( ClassNotFoundException e ) {
				displayMessage( "\nUnknown object type received\n" );
			}
		} while ( !message.equals( "logout" ) );
	}
	
	public void closeConnection(){
		displayMessage( "\nTerminating connection\n" );
		setTextFieldEditable( false );
		try{
			output.close();
			input.close();
			connection.close();
		}
		catch( IOException e ){
			e.printStackTrace();
		}
	}
	
	private void sendData( String message ){
		try{
			output.writeObject( message );
			output.flush();
			displayMessage( nickname + " : \n" + message + "\n\n" );
		}
		catch( IOException e ){
			displayArea.append( "\n Error writing object \n" );
		}
	}
	
	private void displayMessage( final String message ){
		SwingUtilities.invokeLater( 
			new Runnable(){
				public void run(){
					displayArea.append( message );
				}
			}
		);
	}
	
	private void setTextFieldEditable( final boolean editable ){
		SwingUtilities.invokeLater( 
			new Runnable(){
				public void run(){
					enterField.setEditable( editable );
				}
			}
		);
	}
	
}
