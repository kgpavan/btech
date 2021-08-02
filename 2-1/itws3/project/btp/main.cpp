#include<qapplication.h>
#include "basepair.h"

int main(int argc,char *argv[])
{
        QApplication app(argc,argv);
        MainForm *win=new MainForm;
        app.setMainWidget(win);
//        win->resize(600,500);
        win->show();
	win->resize(1000,650);
        return app.exec();
}

