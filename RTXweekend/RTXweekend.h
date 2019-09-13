#pragma once

#include <QtWidgets/QMainWindow>
#include "GeneratedFiles/ui_RTXweekend.h"
#include "ImageWidget.h"

class RTXweekend : public QMainWindow
{
	Q_OBJECT

public:
	RTXweekend(QWidget *parent = Q_NULLPTR);

private:
	Ui::RTXweekendClass ui;
	ImageWidget		*imagewidget_;
};
