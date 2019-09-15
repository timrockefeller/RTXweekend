#pragma once

#include <QtWidgets/QMainWindow>
#include "GeneratedFiles/ui_RTXweekend.h"
#include "ImageWidget.h"

class RTXweekend : public QMainWindow
{
	Q_OBJECT

public:
	RTXweekend(QWidget *parent = Q_NULLPTR);
private slots:
private:

	void CreateActions();


	Ui::RTXweekendClass ui;
	ImageWidget		*imagewidget_;


	QToolBar	*toolbar_;
	QAction		*action_gen_;
	QAction		*action_save_;
};
