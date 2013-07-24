#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_actionNew_triggered();
    bool okToContinue();

    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;
    QString mFilename;
};

#endif // MAINWINDOW_H
