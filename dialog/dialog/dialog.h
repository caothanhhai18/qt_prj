#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>



namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
signals:
void findNext(const QString &str, Qt::CaseSensitivity cs);
void findPrevious(const QString &str, Qt::CaseSensitivity cs);
private slots:
void findClick();
void enablefindButton(const QString &text);

private:
    Ui::Dialog *ui;
QLabel * label;
QLineEdit * lineEdit;
QPushButton * findButton;
QPushButton * closeButton;
QCheckBox * caseCheckbox;
QCheckBox * backwardCheckbox;


};

#endif // DIALOG_H
