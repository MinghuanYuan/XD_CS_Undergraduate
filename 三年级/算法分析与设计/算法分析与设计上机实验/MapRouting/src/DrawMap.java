
import java.awt.*;
import javax.swing.*;
import java.util.ArrayList;

class Line{
    private int x1;
    private int y1;
    private int x2;
    private int y2;

    public Line(int x1, int y1, int x2, int y2) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
    }

    public int getX1() {
        return x1;
    }

    public int getY1() {
        return y1;
    }

    public int getX2() {
        return x2;
    }

    public int getY2() {
        return y2;
    }
}

public class DrawMap{
    JFrame frame;
    PaintLines map;
    PaintLines search;
    PaintLines path;
    int width;
    int height;

    public DrawMap(int width, int height) {
        this.width = width;
        this.height = height;

        frame = new JFrame("Map");
        frame.setSize(width, height);
        frame.setResizable(false);
        frame.setVisible(true);
        
        path = new PaintLines(width, height);
        path.setColor(Color.black);
        frame.add(path);
        
        search = new PaintLines(width, height);
        search.setColor(Color.red);
        frame.add(search);
        
        map = new PaintLines(width, height);
        map.setColor(Color.green);
        frame.add(map);
        
    }

    public int transLocationX(int x){
        return (int)(0.14 * x) + 50;
    }

    public int transLocationY(int y){
        return 790 - (int)(0.18 * y);
    }

    public void addMapLine(int x1, int y1, int x2, int y2) {
        map.addLine(transLocationX(x1),
                    transLocationY(y1),
                    transLocationX(x2),
                    transLocationY(y2));
    }
    
    public void addSearchLine(int x1, int y1, int x2, int y2) {
        search.addLine(transLocationX(x1),
                    transLocationY(y1),
                    transLocationX(x2),
                    transLocationY(y2));
    }

    public void addPathLine(int x1, int y1, int x2, int y2){
        path.addLine(transLocationX(x1),
                     transLocationY(y1),
                     transLocationX(x2),
                     transLocationY(y2));
    }

}

class PaintLines extends JPanel{

    private ArrayList<Line> lines;
    Color color = Color.black;


    public PaintLines(int width, int height){
        setSize(width, height);
        setBackground(null);
        setOpaque(false);
        lines = new ArrayList<Line>();
    }

    public void addLine(int x1, int y1, int x2, int y2) {
        lines.add(new Line(x1, y1, x2, y2));
        repaint();
    }

    @Override
    public void paint(Graphics g){
        super.paint(g);
        g.setColor(color);
        for(int i = 0; i < lines.size(); ++i){
            Line line = lines.get(i);
            g.drawLine(line.getX1(), line.getY1(), line.getX2(), line.getY2());
        }
//        for(Iterator<Line> i = lines.iterator(); i.hasNext();){
//            Line line = i.next();
//            g.drawLine(line.getX1(), line.getY1(), line.getX2(), line.getY2());
//        }
    }

    public void setColor(Color color) {
        this.color = color;
    }
}

