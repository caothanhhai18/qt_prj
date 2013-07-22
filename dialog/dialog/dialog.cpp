#include "dialog.h"
#include "ui_dialog.h"




Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    label = new QLabel(tr("Find &what:"));
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);
    caseCheckbox = new QCheckBox(tr("Match &case"));
    backwardCheckbox = new QCheckBox(tr("Search &backward"));
    findButton = new QPushButton(tr("&Find"));
    findButton->setDefault(true);
    findButton->setEnabled(false);
    closeButton = new QPushButton(tr("Close"));
    QObject::connect(lineEdit,SIGNAL(textChanged(const QString &)),this,SLOT(enablefindButton(const QString &)));
    QObject::connect(findButton,SIGNAL(clicked()),this,SLOT(findClick()));
    QObject::connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));
    QHBoxLayout * topleftLayout = new QHBoxLayout;
    topleftLayout->addWidget(label);
    topleftLayout->addWidget(lineEdit);
    QVBoxLayout * leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topleftLayout);
    leftLayout->addWidget(caseCheckbox);
    leftLayout->addWidget(backwardCheckbox);
    QVBoxLayout * rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch();
    QHBoxLayout * mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);
    setWindowTitle("FindDialog");
    setFixedHeight(sizeHint().height());


}


Dialog::~Dialog()
{
    delete ui;
}
void Dialog::findClick()
{
  QString text = lineEdit->text();
  Qt::CaseSensitivity cs = caseCheckbox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;
  if(backwardCheckbox->isChecked())
  {
      findPrevious(text,cs);
  }
  else
  {
      findNext(text,cs);
  }
}
void Dialog::enablefindButton(const QString &text)
{
  findButton->setEnabled(!text.isEmpty());
}
