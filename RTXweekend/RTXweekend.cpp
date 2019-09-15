#include "RTXweekend.h"

RTXweekend::RTXweekend(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);
	setGeometry(300, 150, 960, 580);
	imagewidget_ = new ImageWidget();
	setCentralWidget(imagewidget_);

	CreateActions();
}

void RTXweekend::CreateActions()
{
	bool constat = true;
	action_gen_ = new QAction(tr("Generate"), this);
	action_gen_->setStatusTip(tr("generate a new image"));
	constat = constat && connect(action_gen_, SIGNAL(triggered()), imagewidget_, SLOT(genImage()));

	action_save_ = new QAction(tr("Save"), this);
	action_save_->setStatusTip(tr("Show origin image"));
	constat = constat && connect(action_save_, SIGNAL(triggered()), imagewidget_, SLOT(saveImage()));

	toolbar_ = addToolBar(tr("Menu"));
	toolbar_->addAction(action_gen_);
	toolbar_->addAction(action_save_);

	statusBar()->showMessage(tr("Ready"));
}
