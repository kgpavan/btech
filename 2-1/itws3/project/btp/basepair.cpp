/****************************************************************************
** Form implementation generated from reading ui file 'basepair.ui'
**
** Created by: The User Interface Compiler ($Id: qt/main.cpp   3.3.6   edited Aug 31 2005 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "basepair.h"

#include <qvariant.h>
#include <qlistbox.h>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qtextedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "basepair.ui.h"

/*
 *  Constructs a MainForm as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
MainForm::MainForm( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "MainForm" );
    setPaletteBackgroundColor( QColor( 255, 255, 255 ) );
    QPalette pal;
    QColorGroup cg;
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 230, 230, 230) );
    cg.setColor( QColorGroup::Light, QColor( 250, 250, 250) );
    cg.setColor( QColorGroup::Midlight, QColor( 253, 253, 253) );
    cg.setColor( QColorGroup::Dark, QColor( 143, 143, 143) );
    cg.setColor( QColorGroup::Mid, QColor( 191, 191, 191) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, QColor( 250, 250, 250) );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 76, 89, 166) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 0, 0, 192) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 128, 0, 128) );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, QColor( 230, 230, 230) );
    cg.setColor( QColorGroup::Light, QColor( 250, 250, 250) );
    cg.setColor( QColorGroup::Midlight, QColor( 253, 253, 253) );
    cg.setColor( QColorGroup::Dark, QColor( 143, 143, 143) );
    cg.setColor( QColorGroup::Mid, QColor( 191, 191, 191) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, QColor( 250, 250, 250) );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 76, 89, 166) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 0, 0, 192) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 128, 0, 128) );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, QColor( 230, 230, 230) );
    cg.setColor( QColorGroup::Light, QColor( 250, 250, 250) );
    cg.setColor( QColorGroup::Midlight, QColor( 253, 253, 253) );
    cg.setColor( QColorGroup::Dark, QColor( 143, 143, 143) );
    cg.setColor( QColorGroup::Mid, QColor( 191, 191, 191) );
    cg.setColor( QColorGroup::Text, QColor( 191, 191, 191) );
    cg.setColor( QColorGroup::BrightText, QColor( 250, 250, 250) );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 63, 75, 138) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 0, 0, 192) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 128, 0, 128) );
    pal.setDisabled( cg );
    setPalette( pal );
    setFocusPolicy( QWidget::ClickFocus );
    setAcceptDrops( FALSE );

    ListBox = new QListBox( this, "ListBox" );
    ListBox->setGeometry( QRect( 250, 60, 180, 220 ) );

    Xaxis = new QComboBox( FALSE, this, "Xaxis" );
    Xaxis->setGeometry( QRect( 70, 330, 101, 31 ) );
    Xaxis->setPaletteBackgroundColor( QColor( 255, 255, 255 ) );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, white );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, black );
    cg.setColor( QColorGroup::LinkVisited, black );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, white );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 0, 0, 192) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 128, 0, 128) );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, white );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
    cg.setColor( QColorGroup::Text, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 0, 0, 192) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 128, 0, 128) );
    pal.setDisabled( cg );
    Xaxis->setPalette( pal );

    InputHeight = new QLineEdit( this, "InputHeight" );
    InputHeight->setGeometry( QRect( 40, 130, 60, 30 ) );

    InfoText = new QLabel( this, "InfoText" );
    InfoText->setGeometry( QRect( 490, 580, 531, 31 ) );
    InfoText->setPaletteForegroundColor( QColor( 0, 0, 255 ) );

    Reset = new QPushButton( this, "Reset" );
    Reset->setGeometry( QRect( 40, 190, 70, 30 ) );
    Reset->setPaletteForegroundColor( QColor( 85, 255, 255 ) );
    Reset->setPaletteBackgroundColor( QColor( 0, 0, 255 ) );

    Browse = new QPushButton( this, "Browse" );
    Browse->setGeometry( QRect( 70, 50, 110, 30 ) );
    Browse->setPaletteForegroundColor( QColor( 0, 255, 255 ) );
    Browse->setPaletteBackgroundColor( QColor( 0, 0, 255 ) );

    Reset2 = new QPushButton( this, "Reset2" );
    Reset2->setGeometry( QRect( 180, 550, 71, 31 ) );
    Reset2->setPaletteForegroundColor( QColor( 0, 255, 255 ) );
    Reset2->setPaletteBackgroundColor( QColor( 0, 0, 255 ) );

    Plot = new QPushButton( this, "Plot" );
    Plot->setGeometry( QRect( 30, 550, 70, 31 ) );
    Plot->setPaletteForegroundColor( QColor( 0, 255, 255 ) );
    Plot->setPaletteBackgroundColor( QColor( 0, 0, 255 ) );

    Cancel = new QPushButton( this, "Cancel" );
    Cancel->setGeometry( QRect( 340, 550, 70, 30 ) );
    Cancel->setPaletteForegroundColor( QColor( 85, 255, 255 ) );
    Cancel->setPaletteBackgroundColor( QColor( 0, 0, 255 ) );

    InputRadius = new QLineEdit( this, "InputRadius" );
    InputRadius->setGeometry( QRect( 140, 130, 60, 30 ) );

    Submit = new QPushButton( this, "Submit" );
    Submit->setGeometry( QRect( 140, 190, 70, 30 ) );
    Submit->setPaletteForegroundColor( QColor( 85, 255, 255 ) );
    Submit->setPaletteBackgroundColor( QColor( 0, 0, 255 ) );

    Group2 = new QButtonGroup( this, "Group2" );
    Group2->setGeometry( QRect( 460, 530, 531, 60 ) );
    Group2->setPaletteForegroundColor( QColor( 0, 0, 255 ) );

    Getinfo = new QRadioButton( Group2, "Getinfo" );
    Getinfo->setGeometry( QRect( 10, 20, 100, 51 ) );

    Zoomout = new QRadioButton( Group2, "Zoomout" );
    Zoomout->setGeometry( QRect( 370, 20, 110, 51 ) );

    Zoomin = new QRadioButton( Group2, "Zoomin" );
    Zoomin->setGeometry( QRect( 190, 20, 100, 51 ) );

    InfoBox = new QTextEdit( this, "InfoBox" );
    InfoBox->setGeometry( QRect( 590, 450, 370, 66 ) );
    InfoBox->setPaletteForegroundColor( QColor( 0, 255, 255 ) );
    InfoBox->setPaletteBackgroundColor( QColor( 0, 0, 255 ) );

    Height = new QLabel( this, "Height" );
    Height->setGeometry( QRect( 50, 100, 45, 21 ) );
    Height->setPaletteForegroundColor( QColor( 0, 85, 255 ) );
    Height->setPaletteBackgroundColor( QColor( 255, 255, 255 ) );

    Radius = new QLabel( this, "Radius" );
    Radius->setGeometry( QRect( 150, 100, 50, 21 ) );
    Radius->setPaletteForegroundColor( QColor( 0, 85, 255 ) );
    Radius->setPaletteBackgroundColor( QColor( 255, 255, 255 ) );

    Axisx = new QLabel( this, "Axisx" );
    Axisx->setGeometry( QRect( 90, 300, 42, 21 ) );
    Axisx->setPaletteForegroundColor( QColor( 0, 0, 255 ) );

    Axisy = new QLabel( this, "Axisy" );
    Axisy->setGeometry( QRect( 280, 300, 41, 21 ) );
    Axisy->setPaletteForegroundColor( QColor( 0, 0, 255 ) );

    textLabel5 = new QLabel( this, "textLabel5" );
    textLabel5->setGeometry( QRect( 350, 370, 46, 21 ) );
    textLabel5->setPaletteForegroundColor( QColor( 0, 0, 255 ) );

    Yaxis = new QComboBox( FALSE, this, "Yaxis" );
    Yaxis->setGeometry( QRect( 250, 330, 100, 31 ) );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, white );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, black );
    cg.setColor( QColorGroup::LinkVisited, black );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, white );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 0, 0, 192) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 128, 0, 128) );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, white );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
    cg.setColor( QColorGroup::Text, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 0, 0, 192) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 128, 0, 128) );
    pal.setDisabled( cg );
    Yaxis->setPalette( pal );

    Base1 = new QComboBox( FALSE, this, "Base1" );
    Base1->setGeometry( QRect( 30, 400, 90, 31 ) );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, white );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, black );
    cg.setColor( QColorGroup::LinkVisited, black );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, white );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 0, 0, 192) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 128, 0, 128) );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, white );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
    cg.setColor( QColorGroup::Text, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 0, 0, 192) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 128, 0, 128) );
    pal.setDisabled( cg );
    Base1->setPalette( pal );

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setGeometry( QRect( 50, 370, 50, 21 ) );
    textLabel3->setPaletteForegroundColor( QColor( 0, 0, 255 ) );

    textLabel7 = new QLabel( this, "textLabel7" );
    textLabel7->setGeometry( QRect( 190, 430, 75, 21 ) );
    textLabel7->setPaletteForegroundColor( QColor( 0, 0, 255 ) );

    Orientation = new QComboBox( FALSE, this, "Orientation" );
    Orientation->setGeometry( QRect( 170, 460, 100, 30 ) );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, white );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, black );
    cg.setColor( QColorGroup::LinkVisited, black );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, white );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 0, 0, 192) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 128, 0, 128) );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, white );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
    cg.setColor( QColorGroup::Text, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 0, 0, 192) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 128, 0, 128) );
    pal.setDisabled( cg );
    Orientation->setPalette( pal );

    textLabel4 = new QLabel( this, "textLabel4" );
    textLabel4->setGeometry( QRect( 40, 460, 50, 21 ) );
    textLabel4->setPaletteForegroundColor( QColor( 0, 0, 255 ) );

    textLabel6 = new QLabel( this, "textLabel6" );
    textLabel6->setGeometry( QRect( 350, 460, 50, 21 ) );
    textLabel6->setPaletteForegroundColor( QColor( 0, 0, 255 ) );

    Base2 = new QComboBox( FALSE, this, "Base2" );
    Base2->setGeometry( QRect( 330, 400, 90, 31 ) );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, white );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, black );
    cg.setColor( QColorGroup::LinkVisited, black );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, white );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 0, 0, 192) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 128, 0, 128) );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, white );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
    cg.setColor( QColorGroup::Text, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 0, 0, 192) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 128, 0, 128) );
    pal.setDisabled( cg );
    Base2->setPalette( pal );

    Edge2 = new QComboBox( FALSE, this, "Edge2" );
    Edge2->setGeometry( QRect( 330, 490, 90, 31 ) );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, white );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, black );
    cg.setColor( QColorGroup::LinkVisited, black );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, white );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 0, 0, 192) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 128, 0, 128) );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, white );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
    cg.setColor( QColorGroup::Text, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 0, 0, 192) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 128, 0, 128) );
    pal.setDisabled( cg );
    Edge2->setPalette( pal );

    Edge1 = new QComboBox( FALSE, this, "Edge1" );
    Edge1->setGeometry( QRect( 30, 490, 90, 31 ) );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, white );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, black );
    cg.setColor( QColorGroup::LinkVisited, black );
    pal.setActive( cg );
    cg.setColor( QColorGroup::Foreground, black );
    cg.setColor( QColorGroup::Button, white );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
    cg.setColor( QColorGroup::Text, black );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, black );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 0, 0, 192) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 128, 0, 128) );
    pal.setInactive( cg );
    cg.setColor( QColorGroup::Foreground, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Button, white );
    cg.setColor( QColorGroup::Light, white );
    cg.setColor( QColorGroup::Midlight, white );
    cg.setColor( QColorGroup::Dark, QColor( 127, 127, 127) );
    cg.setColor( QColorGroup::Mid, QColor( 170, 170, 170) );
    cg.setColor( QColorGroup::Text, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::BrightText, white );
    cg.setColor( QColorGroup::ButtonText, QColor( 128, 128, 128) );
    cg.setColor( QColorGroup::Base, white );
    cg.setColor( QColorGroup::Background, white );
    cg.setColor( QColorGroup::Shadow, black );
    cg.setColor( QColorGroup::Highlight, QColor( 0, 0, 128) );
    cg.setColor( QColorGroup::HighlightedText, white );
    cg.setColor( QColorGroup::Link, QColor( 0, 0, 192) );
    cg.setColor( QColorGroup::LinkVisited, QColor( 128, 0, 128) );
    pal.setDisabled( cg );
    Edge1->setPalette( pal );

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setGeometry( QRect( 300, 20, 70, 21 ) );
    textLabel1->setPaletteForegroundColor( QColor( 0, 0, 255 ) );
    languageChange();
    resize( QSize(1025, 565).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( Submit, SIGNAL( clicked() ), this, SLOT( SubmitValues() ) );
    connect( Reset, SIGNAL( clicked() ), this, SLOT( ResetValues() ) );
    connect( Reset2, SIGNAL( clicked() ), this, SLOT( Reset2_clicked() ) );
    connect( Plot, SIGNAL( clicked() ), this, SLOT( Plot_clicked() ) );
    connect( Cancel, SIGNAL( clicked() ), this, SLOT( close() ) );
    connect( Browse, SIGNAL( clicked() ), this, SLOT( BrowseFile() ) );
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
MainForm::~MainForm()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void MainForm::languageChange()
{
    setCaption( tr( "Base Pair Finder" ) );
    Xaxis->clear();
    Xaxis->insertItem( tr( "---- Select ----" ) );
    Xaxis->insertItem( tr( "Omega eta" ) );
    Xaxis->insertItem( tr( "Omega 1" ) );
    InfoText->setText( QString::null );
    Reset->setText( tr( "Reset" ) );
    Browse->setText( tr( "Upload PDB File" ) );
    Reset2->setText( tr( "Reset" ) );
    Plot->setText( tr( "Plot" ) );
    Cancel->setText( tr( "Cancel" ) );
    Submit->setText( tr( "Submit" ) );
    Group2->setTitle( tr( "Mouse Click Options" ) );
    Getinfo->setText( tr( "Get Info" ) );
    Zoomout->setText( tr( "Zoom Out" ) );
    Zoomin->setText( tr( "Zoom In" ) );
    Height->setText( tr( "Height" ) );
    Radius->setText( tr( "Radius" ) );
    Axisx->setText( tr( "X axis" ) );
    Axisy->setText( tr( "Y axis" ) );
    textLabel5->setText( tr( "Base 2" ) );
    Yaxis->clear();
    Yaxis->insertItem( tr( "----Select----" ) );
    Yaxis->insertItem( tr( "Omega Theta" ) );
    Yaxis->insertItem( tr( "Omega 2" ) );
    Base1->clear();
    Base1->insertItem( tr( "--Select--" ) );
    Base1->insertItem( tr( "A" ) );
    Base1->insertItem( tr( "T" ) );
    Base1->insertItem( tr( "U" ) );
    Base1->insertItem( tr( "G" ) );
    Base1->insertItem( tr( "C" ) );
    textLabel3->setText( tr( "Base 1" ) );
    textLabel7->setText( tr( "Orientation" ) );
    Orientation->clear();
    Orientation->insertItem( tr( "---Select---" ) );
    Orientation->insertItem( tr( "Cis" ) );
    Orientation->insertItem( tr( "Trans" ) );
    textLabel4->setText( tr( "Edge 1" ) );
    textLabel6->setText( tr( "Edge 2" ) );
    Base2->clear();
    Base2->insertItem( tr( "--Select--" ) );
    Base2->insertItem( tr( "A" ) );
    Base2->insertItem( tr( "T" ) );
    Base2->insertItem( tr( "U" ) );
    Base2->insertItem( tr( "G" ) );
    Base2->insertItem( tr( "C" ) );
    Edge2->clear();
    Edge2->insertItem( tr( "--Select--" ) );
    Edge2->insertItem( tr( "W" ) );
    Edge2->insertItem( tr( "H" ) );
    Edge2->insertItem( tr( "S" ) );
    Edge1->clear();
    Edge1->insertItem( tr( "--Select--" ) );
    Edge1->insertItem( tr( "W" ) );
    Edge1->insertItem( tr( "H" ) );
    Edge1->insertItem( tr( "S" ) );
    textLabel1->setText( tr( "PDB Files" ) );
}

