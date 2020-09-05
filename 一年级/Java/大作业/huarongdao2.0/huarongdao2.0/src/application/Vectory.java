package application;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class Vectory extends Application {
	Stage stage = new Stage();
	@Override
	public void start(Stage primaryStage){
		try {
			Text t1 = new Text("曹操顺利逃跑！");
			t1.setFont(Font.font("Verdana",20));
			t1.setFill(Color.BLACK);
			
			Text t2 = new Text("试下其他模式吧");
			t2.setFont(Font.font("Verdana",20));
			t2.setFill(Color.BLACK);
			
			VBox hbox = new VBox();
			hbox.getChildren().add(t1);
			hbox.getChildren().add(t2);
			hbox.setAlignment(Pos.CENTER);
			
			primaryStage.setTitle("华容道");
			primaryStage.setResizable(false);
	        primaryStage.setScene(new Scene(hbox, 300, 200));
	        primaryStage.show();
			
			// TODO Auto-generated method stub
		}catch(Exception e) {
			e.printStackTrace();
		}

	}
	
	public void  showWindow() throws Exception {
		start(stage);
	}

}
