#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPainter>
#include<QPaintDevice>
#include<QPaintDeviceWindow>
#include<QtDebug>
#include<QMouseEvent>
#include<QVector>
#include<QFile>
#include<QString>
#include<QFileDialog>
#include<QMessageBox>
#include<QPainterPath>
#include<QLabel>
#include<QMap>
#include<QColor>
#include<QIcon>
#include"windowpaint.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void openFile(int type);
    void readConfig(int type);
    void preworkColor();
    void paintEvent(QPaintEvent *event);

private slots:
    void on_action_openFile_triggered();
    void on_action_saveFile_triggered();
    void on_action_select1_triggered();
    void on_action_select2_triggered();
    void on_action_select3_triggered();
    void on_action_select4_triggered();
    void on_action_select5_triggered();
    void on_action_select6_triggered();
    void on_action_select7_triggered();
    void on_action_moveUp_triggered();
    void on_action_moveDown_triggered();
    void on_action_moveRight_triggered();
    void on_action_moveLeft_triggered();
    void on_action_elementTypeChange_triggered();
    void on_action_elementRotateChange_triggered();
    void on_action_moveUp5_triggered();
    void on_action_moveDown5_triggered();
    void on_action_moveRight5_triggered();
    void on_action_moveLeft5_triggered();
    void on_action_show1_triggered();
    void on_action_show2_triggered();
    void on_action_show3_triggered();
    void on_action_show4_triggered();
    void on_action_show5_triggered();
    void on_action_show6_triggered();

private:
    int nowSelect = 1;
    QVector<paintObject> elementList;
    QMap<int,QColor> elementColor;
    void paintChangeRotate(QPainter *patiner,int rot);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
