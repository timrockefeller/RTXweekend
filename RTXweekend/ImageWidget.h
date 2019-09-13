#pragma once
#include <qwidget.h>

QT_BEGIN_NAMESPACE
class QImage;
class QPainter;
QT_END_NAMESPACE

class ImageWidget :
	public QWidget
{
public:
	ImageWidget();
	~ImageWidget();

protected:
	void paintEvent(QPaintEvent *paintevent);

private:
	QImage		*ptr_image_;

	QPoint image_offset_;
};

