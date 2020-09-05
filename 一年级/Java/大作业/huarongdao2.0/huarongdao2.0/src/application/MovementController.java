package application;

import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;
import javafx.scene.text.Text;

public class MovementController {

	private double[] recordLocation = new double[53];
	
	private Rectangle[] rectangles = new Rectangle[10];
	
	private Text[] texts = new Text[10];//
	
	public void setRecordLocation(double[] recordLocation) {
		this.recordLocation = recordLocation;
	}
	
	public void startAll() {
		setRectanglesAndTexts();
		moveRectangles();
	}
	
	public void setRectanglesAndTexts() {
		int serialNumber;
		for(serialNumber = 1; serialNumber <= 50; serialNumber+=5) {
			rectangles[serialNumber/5] = new Rectangle(recordLocation[serialNumber], recordLocation[serialNumber+1], recordLocation[serialNumber+2], recordLocation[serialNumber+3]);
			switch ((int)recordLocation[serialNumber+4]) {
			case 1:
				rectangles[serialNumber/5].setFill(javafx.scene.paint.Color.BLUE);
				texts[serialNumber/5] = new Text("ÕÅ·É");
				texts[serialNumber/5].xProperty().bind(rectangles[serialNumber/5].xProperty().add(20));
				texts[serialNumber/5].yProperty().bind(rectangles[serialNumber/5].yProperty().add(110));
				texts[serialNumber/5].setFont(Font.font("Courier", 30));
				texts[serialNumber/5].setFill(javafx.scene.paint.Color.WHITE);
				break;
			case 2:
				rectangles[serialNumber/5].setFill(javafx.scene.paint.Color.BLUE);
				texts[serialNumber/5] = new Text("»ÆÖÒ");
				texts[serialNumber/5].xProperty().bind(rectangles[serialNumber/5].xProperty().add(20));
				texts[serialNumber/5].yProperty().bind(rectangles[serialNumber/5].yProperty().add(110));
				texts[serialNumber/5].setFont(Font.font("Courier", 30));
				texts[serialNumber/5].setFill(javafx.scene.paint.Color.WHITE);
				break;
			case 3:
				rectangles[serialNumber/5].setFill(javafx.scene.paint.Color.BLUE);
				texts[serialNumber/5] = new Text("¹ØÓð");
				texts[serialNumber/5].xProperty().bind(rectangles[serialNumber/5].xProperty().add(20));
				texts[serialNumber/5].yProperty().bind(rectangles[serialNumber/5].yProperty().add(50));
				texts[serialNumber/5].setFont(Font.font("Courier", 30));
				texts[serialNumber/5].setFill(javafx.scene.paint.Color.WHITE);
				break;
			case 4:
				rectangles[serialNumber/5].setFill(javafx.scene.paint.Color.BLUE);
				texts[serialNumber/5] = new Text("ÕÔÔÆ");
				texts[serialNumber/5].xProperty().bind(rectangles[serialNumber/5].xProperty().add(20));
				texts[serialNumber/5].yProperty().bind(rectangles[serialNumber/5].yProperty().add(110));
				texts[serialNumber/5].setFont(Font.font("Courier", 30));
				texts[serialNumber/5].setFill(javafx.scene.paint.Color.WHITE);
				break;
			case 5:
				rectangles[serialNumber/5].setFill(javafx.scene.paint.Color.BLUE);
				texts[serialNumber/5] = new Text("Âí³¬");
				texts[serialNumber/5].xProperty().bind(rectangles[serialNumber/5].xProperty().add(20));
				texts[serialNumber/5].yProperty().bind(rectangles[serialNumber/5].yProperty().add(110));
				texts[serialNumber/5].setFont(Font.font("Courier", 30));
				texts[serialNumber/5].setFill(javafx.scene.paint.Color.WHITE);
				break;
			case 6:
				rectangles[serialNumber/5].setFill(javafx.scene.paint.Color.RED);
				texts[serialNumber/5] = new Text("²Ü²Ù");
				texts[serialNumber/5].xProperty().bind(rectangles[serialNumber/5].xProperty().add(20));
				texts[serialNumber/5].yProperty().bind(rectangles[serialNumber/5].yProperty().add(110));
				texts[serialNumber/5].setFont(Font.font("Courier", 30));
				texts[serialNumber/5].setFill(javafx.scene.paint.Color.WHITE);
				break;
			case 7:
				rectangles[serialNumber/5].setFill(javafx.scene.paint.Color.GREEN);
				texts[serialNumber/5] = new Text("×ä");
				texts[serialNumber/5].xProperty().bind(rectangles[serialNumber/5].xProperty().add(40));
				texts[serialNumber/5].yProperty().bind(rectangles[serialNumber/5].yProperty().add(50));
				texts[serialNumber/5].setFont(Font.font("Courier", 30));
				texts[serialNumber/5].setFill(javafx.scene.paint.Color.WHITE);
				break;
			default:
				break;
			}
			rectangles[serialNumber/5].setStroke(javafx.scene.paint.Color.BLACK);
		}
	}
	
	public Rectangle[] getRectangles() {
		return rectangles;
	}
	
	public Text[] gettexts() {
		return texts;
	}
	
	private void changeRecordLocation() {
		int mark;
		int serialNumber = 0;
		for(mark = 1; mark <= 50; mark+=5) {
			recordLocation[mark] = rectangles[serialNumber].getX();
			recordLocation[mark+1] = rectangles[serialNumber].getY();
			serialNumber++;
		}
		IOController.printfile(recordLocation[0], recordLocation);//
	}
	
	public void moveRectangles(){
		int serialNumber;
		for(serialNumber = 0; serialNumber<10; serialNumber++) {
			Rectangle tempr = rectangles[serialNumber];
			tempr.setOnMouseClicked(e -> {
				double rx = tempr.getX();
				double ry = tempr.getY();
				double width = tempr.getWidth();
				double height = tempr.getHeight();
				double rmx = e.getX();
				double rmy = e.getY();
				int directive = directive(rx, ry, width, height, rmx, rmy);
				int mark = (int) (rx/100+ry/25+1);
				if(width==100&&height==100) {
					int a = manage100100(mark, (int)recordLocation[51], (int)recordLocation[52], directive);
					if(a==1) {
						if((ry-100)>=0) {
							tempr.setY(ry-100);
							if(recordLocation[51] == mark-4) {
								recordLocation[51] = mark;
							}
							else {
								recordLocation[52] = mark;
							}
							changeRecordLocation();
						}
					}
					else if(a==2) {
						if((rx+100)<400) {
							tempr.setX(rx+100);
							if(recordLocation[51] == mark+1) {
								recordLocation[51] = mark;
							}
							else {
								recordLocation[52] = mark;
							}
							changeRecordLocation();
						}
					}
					else if(a==3) {
						if((ry+100)<500) {
							tempr.setY(ry+100);
							if(recordLocation[51] == mark+4) {
								recordLocation[51] = mark;
							}
							else {
								recordLocation[52] = mark;
							}
							changeRecordLocation();
						}
					}
					else if(a==4) {
						if((rx-100)>=0) {
							tempr.setX(rx-100);
							if(recordLocation[51] == mark-1) {
								recordLocation[51] = mark;
							}
							else {
								recordLocation[52] = mark;
							}
							changeRecordLocation();
						}
					}
				}
				
				if(width==100&&height==200) {
					int a = manage100200(mark, (int)recordLocation[51], (int)recordLocation[52], directive);
					if(a==1) {
						if((ry-100)>=0) {
							tempr.setY(ry-100);
							if(recordLocation[51] == mark-4) {
								recordLocation[51] = mark+4;
							}
							else {
								recordLocation[52] = mark+4;
							}
							changeRecordLocation();
						}
					}
					else if(a==2) {
						if((rx+100)<400) {
							tempr.setX(rx+100);
							recordLocation[51] = mark;
							recordLocation[52] = mark+4;
							changeRecordLocation();
						}
					}
					else if(a==3) {
						if((ry+200)<500) {
							tempr.setY(ry+100);
							if(recordLocation[51] == mark+8) {
								recordLocation[51] = mark;
							}
							else {
								recordLocation[52] = mark;
							}
							changeRecordLocation();
						}
					}
					else if(a==4) {
						if((rx-100)>=0) {
							tempr.setX(rx-100);
							recordLocation[51] = mark;
							recordLocation[52] = mark+4;
							changeRecordLocation();
						}
					}
				}
				
				if(width==200&&height==100) {
					int a = manage200100(mark, (int)recordLocation[51], (int)recordLocation[52], directive);
					if(a==1) {
						if((ry-100)>=0) {
							tempr.setY(ry-100);
							recordLocation[51] = mark;
							recordLocation[52] = mark+1;
							changeRecordLocation();
						}
					}
					else if(a==2) {
						if((rx+200)<400) {
							tempr.setX(rx+100);
							if(recordLocation[51] == mark+2) {
								recordLocation[51] = mark;
							}
							else {
								recordLocation[52] = mark;
							}
							changeRecordLocation();
						}
					}
					else if(a==3) {
						if((ry+100)<500) {
							tempr.setY(ry+100);
							recordLocation[51] = mark;
							recordLocation[52] = mark+1;
							changeRecordLocation();
						}
					}
					else if(a==4) {
						if((rx-100)>=0) {
							tempr.setX(rx-100);
							if(recordLocation[51] == mark-1) {
								recordLocation[51] = mark+1;
							}
							else {
								recordLocation[52] = mark+1;
							}
							changeRecordLocation();
						}
					}
				}
				
				if(width==200&&height==200) {
					int a = manage200200(mark, (int)recordLocation[51], (int)recordLocation[52], directive);
					if(a==1) {
						if((ry-100)>=0) {
							tempr.setY(ry-100);
							recordLocation[51] = mark+4;
							recordLocation[52] = mark+5;
							changeRecordLocation();
						}
					}
					else if(a==2) {
						if((rx+200)<400) {
							tempr.setX(rx+100);
							recordLocation[51] = mark;
							recordLocation[52] = mark+4;
							changeRecordLocation();
						}
					}
					else if(a==3) {
						if((ry+200)<500) {
							tempr.setY(ry+100);
							recordLocation[51] = mark;
							recordLocation[52] = mark+1;
							changeRecordLocation();
						}
					}
					else if(a==4) {
						if((rx-100)>=0) {
							tempr.setX(rx-100);
							recordLocation[51] = mark+5;
							recordLocation[52] = mark+1;
							changeRecordLocation();
						}
					}
					if(tempr.getX() == 100&&tempr.getY() == 300) {
						changeWindowtoVectory();
					}
				}
				
			});
		}
	}
	
	private void changeWindowtoVectory() {
		try {
			Vectory vectory=new Vectory();
			vectory.showWindow();
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	
	private int directive(double x, double y, double width, double height, double x1, double y1) {
		double dx = x1-x;
		double dy = y1-y;
		if(dx<=width/2&&dy<=height/2)return 1;
		else if(dx>width/2&&dy<=height/2)return 2;
		else if(dx>width/2&&dy>height/2)return 3;
		else if(dx<=width/2&&dy>height/2)return 4;
		else return 0;
	}

	private int manage100200(int mark, int one, int two, int direction) {
		if((one==mark-4||two==mark-4)&&(direction==1||direction==2))return 1;
		else if((one==mark+8||two==mark+8)&&(direction==3||direction==4))return 3;
		else if(((one==mark+1&&two==mark+5)||(one==mark+5&&two==mark+1))&&(direction==2||direction==3))return 2;
		else if(((one==mark-1&&two==mark+3)||(one==mark+3&&two==mark-1))&&(direction==1||direction==4))return 4;
		else return 0;
	}
	
	private int manage200200(int mark, int one, int two, int direction) {
		if(((one==mark-4&&two==mark-3)||(one==mark-3&&two==mark-4))&&(direction==1||direction==2))return 1;
		else if(((one==mark+2&&two==mark+6)||(one==mark+6&&two==mark+2))&&(direction==2||direction==3))return 2;
		else if(((one==mark+8&&two==mark+9)||(one==mark+9&&two==mark+8))&&(direction==3||direction==4))return 3;
		else if(((one==mark-1&&two==mark+3)||(one==mark+3&&two==mark-1))&&(direction==1||direction==4))return 4;
		else return 0;
	}
	
	private int manage100100(int mark, int one, int two, int direction) {
		if((one==mark-4||two==mark-4)&&(direction==1||direction==2))return 1;
		else if((one==mark+4||two==mark+4)&&(direction==3||direction==4))return 3;
		else if((one==mark+1||two==mark+1)&&(direction==2||direction==3))return 2;
		else if((one==mark-1||two==mark-1)&&(direction==1||direction==4))return 4;
		else return 0;
	}
	
	private int manage200100(int mark, int one, int two, int direction) {
		if((one==mark+2||two==mark+2)&&(direction==2||direction==3))return 2;
		else if((one==mark-1||two==mark-1)&&(direction==1||direction==4))return 4;
		else if(((one==mark-4&&two==mark-3)||(one==mark-3&&two==mark-4))&&(direction==1||direction==2))return 1;
		else if(((one==mark+4&&two==mark+5)||(one==mark+5&&two==mark+4))&&(direction==3||direction==4))return 3;
		else return 0;
	}
	
}
