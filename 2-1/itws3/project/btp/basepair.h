/****************************************************************************
** Form interface generated from reading ui file 'basepair.ui'
**
** Created by: The User Interface Compiler ($Id: qt/main.cpp   3.3.6   edited Aug 31 2005 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MAINFORM_H
#define MAINFORM_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QListBox;
class QListBoxItem;
class QComboBox;
class QLineEdit;
class QLabel;
class QPushButton;
class QButtonGroup;
class QRadioButton;
class QTextEdit;

class MainForm : public QWidget
{
    Q_OBJECT

public:
    MainForm( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~MainForm();

    QListBox* ListBox;
    QComboBox* Xaxis;
    QLineEdit* InputHeight;
    QLabel* InfoText;
    QPushButton* Reset;
    QPushButton* Browse;
    QPushButton* Reset2;
    QPushButton* Plot;
    QPushButton* Cancel;
    QLineEdit* InputRadius;
    QPushButton* Submit;
    QButtonGroup* Group2;
    QRadioButton* Getinfo;
    QRadioButton* Zoomout;
    QRadioButton* Zoomin;
    QTextEdit* InfoBox;
    QLabel* Height;
    QLabel* Radius;
    QLabel* Axisx;
    QLabel* Axisy;
    QLabel* textLabel5;
    QComboBox* Yaxis;
    QComboBox* Base1;
    QLabel* textLabel3;
    QLabel* textLabel7;
    QComboBox* Orientation;
    QLabel* textLabel4;
    QLabel* textLabel6;
    QComboBox* Base2;
    QComboBox* Edge2;
    QComboBox* Edge1;
    QLabel* textLabel1;

    virtual void init();
    virtual void Plot_graph();

public slots:
    virtual void ResetValues();
    virtual void SubmitValues();
    virtual void BrowseFile();
    virtual void Plot_clicked();
    virtual void Reset2_clicked();

protected:
    virtual void mousePressEvent( QMouseEvent * e );


protected slots:
    virtual void languageChange();

};

#endif // MAINFORM_H
