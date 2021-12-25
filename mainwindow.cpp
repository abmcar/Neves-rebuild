#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Neves");
    setWindowIcon(QIcon(":/Config/Neves.ico"));
    preworkColor();
    readConfig(1);
    resize(1280,720);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readConfig(int type)
{
    qDebug() << "open";
    openFile(type);
}

void MainWindow::preworkColor()
{
    QColor red,yellow,green,cyan,blue,violet,orange;
    red.setRed(255);
    yellow.setRed(255),yellow.setGreen(255);
    green.setGreen(255);
    cyan.setGreen(255),cyan.setBlue(255);
    blue.setBlue(255);
    violet.setRed(255),violet.setBlue(255);
    orange.setRed(255),orange.setGreen(165);
    elementColor[1] = red;
    elementColor[2] = yellow;
    elementColor[3] = green;
    elementColor[4] = cyan;
    elementColor[5] = blue;
    elementColor[6] = violet;
    elementColor[7] = orange;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
//    qDebug() << "Strart";

    QPainter painter(this);
    painter.setRenderHint(QPainter:: Antialiasing, true);
    for(int i = 0; i < elementList.size(); i++)
    {
        paintObject nowPaint = elementList[i];
        int nextX = nowPaint.mouseX;
        int nextY = nowPaint.mouseY;
        int nextT = nowPaint.type;
        int nextR = nowPaint.rota;
        int tempX,tempY;
        tempX = nextX;
        tempY = nextY;
        painter.setBrush(elementColor[i+1]);
        painter.translate(nextX,nextY);
        painter.rotate(nextR);
        nextX = nextY = 0;
//        qDebug() << nextX << nextY;
        if(nextT == 1)
        {
            NevesPaintRectangle rectangle(&painter,nextX,nextY);
            rectangle.startPaint();
        }
        if(nextT == 2)
        {
            NevesPaintTriangle triangle(&painter,nextX,nextY,200,100);
            triangle.startPaint();
        }
        if(nextT == 3)
        {
            NevesPaintTriangle triangle(&painter,nextX,nextY,282,141);
            triangle.startPaint();
        }
        if(nextT == 4)
        {
            NevesPaintTriangle triangle(&painter,nextX,nextY,400,200);
            triangle.startPaint();
        }
        if(nextT == 5)
        {
            NevesPaintParallelogram parallelogram(&painter,nextX,nextY);
            parallelogram.startPaint();
        }
        painter.rotate(-nextR);
        painter.translate(-tempX,-tempY);
    }
}

void MainWindow::on_action_openFile_triggered()
{
    QString path = QFileDialog::getOpenFileName(this,
                                                tr("Open File"),
                                                ".",
                                                tr("Text Files(*.txt)"));
    if(!path.isEmpty())
    {
        QFile file(path);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        elementList.clear();
        QTextStream in(&file);
        int totNum;
        in >> totNum;
        for(int i = 0; i < totNum; i++)
        {
            paintObject tempObject;
            in >> tempObject.type >> tempObject.mouseX >> tempObject.mouseY >> tempObject.rota;
            elementList.push_back(tempObject);
        }
        file.close();
        update();
    }
    else
    {
        QMessageBox::warning(this, tr("Path"),
                             tr("You did not select any file."));
    }
}

void MainWindow::openFile(int type)
{
    QString path;
    if(type == 1)
        path = ":/Config/finishNeves.txt";
    if(type == 2)
        path = ":/Config/clothes.txt";
    if(type == 3)
        path = ":/Config/vase.txt";
    if(type == 4)
        path = ":/Config/ufo.txt";
    if(type == 5)
        path = ":/Config/teapot.txt";
    if(type == 6)
        path = ":/Config/plane.txt";
    QFile file(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    elementList.clear();
    QTextStream in(&file);
    int totNum;
    in >> totNum;
    for(int i = 0; i < totNum; i++)
    {
        paintObject tempObject;
        in >> tempObject.type >> tempObject.mouseX >> tempObject.mouseY >> tempObject.rota;
        elementList.push_back(tempObject);
    }
    file.close();
    update();
}

void MainWindow::on_action_saveFile_triggered()
{
    QString path = QFileDialog::getSaveFileName(this,
                                                tr("Open File"),
                                                ".",
                                                tr("Text Files(*.txt)"));
    if(!path.isEmpty())
    {
        QFile file(path);
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(&file);
        out << elementList.size() << endl;
        for(int i = 0; i < elementList.size(); i++)
            out << elementList[i].type << " " << elementList[i].mouseX << " " << elementList[i].mouseY << " " << elementList[i].rota << endl;
        file.close();
    }
    else
    {
        QMessageBox::warning(this, tr("Path"),
                             tr("You did not select any file."));
    }
}

void MainWindow::on_action_select1_triggered()
{
    nowSelect = 1;
}

void MainWindow::on_action_select2_triggered()
{
    nowSelect = 2;
}

void MainWindow::on_action_select3_triggered()
{
    nowSelect = 3;
}

void MainWindow::on_action_select4_triggered()
{
    nowSelect = 4;
}

void MainWindow::on_action_select5_triggered()
{
    nowSelect = 5;
}

void MainWindow::on_action_select6_triggered()
{
    nowSelect = 6;
}

void MainWindow::on_action_select7_triggered()
{
    nowSelect = 7;
}

void MainWindow::on_action_moveUp_triggered()
{
    elementList[nowSelect-1].mouseY -= 25;
    update();
}

void MainWindow::on_action_moveDown_triggered()
{
    elementList[nowSelect-1].mouseY += 25;
    update();
}

void MainWindow::on_action_moveRight_triggered()
{
    elementList[nowSelect-1].mouseX += 25;
    update();
}

void MainWindow::on_action_moveLeft_triggered()
{
    elementList[nowSelect-1].mouseX -= 25;
    update();
}

void MainWindow::on_action_elementTypeChange_triggered()
{
    elementList[nowSelect-1].type++;
    if(elementList[nowSelect-1].type == 6)
        elementList[nowSelect-1].type = 1;
   update();
}

void MainWindow::on_action_elementRotateChange_triggered()
{
    elementList[nowSelect-1].rota += 45;
    if(elementList[nowSelect-1].rota >= 360)
        elementList[nowSelect-1].rota -= 360;
    update();
}

void MainWindow::on_action_moveUp5_triggered()
{
    elementList[nowSelect-1].mouseY -= 1;
    update();
}

void MainWindow::on_action_moveDown5_triggered()
{
    elementList[nowSelect-1].mouseY += 1;
    update();
}

void MainWindow::on_action_moveRight5_triggered()
{
    elementList[nowSelect-1].mouseX -= 1;
    update();
}

void MainWindow::on_action_moveLeft5_triggered()
{
    elementList[nowSelect-1].mouseX += 1;
    update();
}

void MainWindow::on_action_show1_triggered()
{
    readConfig(1);
}

void MainWindow::on_action_show2_triggered()
{
    readConfig(2);
}

void MainWindow::on_action_show3_triggered()
{
    readConfig(3);
}

void MainWindow::on_action_show4_triggered()
{
    readConfig(4);
}

void MainWindow::on_action_show5_triggered()
{
    readConfig(5);
}

void MainWindow::on_action_show6_triggered()
{
    readConfig(6);
}
