#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    mFilename ="";
    ui->textEdit->setPlainText("");
}

bool MainWindow::okToContinue()
{
    if(isWindowModified())
    {
        int r = QMessageBox::warning(this,tr("Warning"),tr("The document has been modified.\n"
                            "Do you want to save your changes?"),QMessageBox::Yes,
                            QMessageBox::No,QMessageBox::Cancel);
    }
}

void MainWindow::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,tr("Open File"),".",tr("*.h *.cpp"));
    if(!file.isEmpty())
    {
        QFile fileName(file);
        if (fileName.open(QFile::ReadOnly | QFile::Text ))
        {
            QTextStream in(&fileName);
            QString text = in.readAll();
            fileName.close();
            ui->textEdit->setPlainText(text);


        }

    }
}
