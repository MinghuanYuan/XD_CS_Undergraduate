package application;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

public class Third extends Application {
	Stage stage = new Stage();

	@Override
	public void start(Stage primaryStage)  {
		try {
			Pane pane = new Pane();
			pane.setStyle("-fx-background-color: grey;");
			pane.setPrefSize(400, 500);
			
			IOController ioController = new IOController();
			MovementController movementController = new MovementController();
			movementController.setRecordLocation(ioController.getgame());
			movementController.setRectanglesAndTexts();
			pane.getChildren().addAll(movementController.getRectangles());
			pane.getChildren().addAll(movementController.gettexts());
			movementController.moveRectangles();
			
			Button btn = new Button("Back");
			btn.setLayoutX(180.0);
			btn.setLayoutY(520.0);
			btn.setOnAction(e -> {changeWindowtomain();primaryStage.close();});
			pane.getChildren().add(btn);
			
			Scene scene = new Scene(pane, 400, 600);
			primaryStage.setResizable(false);
			primaryStage.setTitle("»ªÈÝµÀ");
			primaryStage.setScene(scene);
			primaryStage.show();
		} catch(Exception e) {
			e.printStackTrace();
		}// TODO Auto-generated method stub

	}
	
	public void  showWindow() throws Exception {
		start(stage);
	}
	
	private void changeWindowtomain() {
		try {
			Main main = new Main();
			main.showWindow();
		}catch(Exception e) {
			e.printStackTrace();
		}
	}

}
