#include "RTXweekend.h"

RTXweekend::RTXweekend(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);
	setGeometry(300, 150, 800, 450);
	imagewidget_ = new ImageWidget();
	setCentralWidget(imagewidget_);
}
