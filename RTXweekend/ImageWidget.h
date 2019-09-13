#pragma once
#include <qwidget.h>

#include <QImage>
#include <qcolor.h>
#include <QPainter>

#include "vec3.h"
#include "ray.h"

#include "util.h"

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
	void genImage();

protected:
	void paintEvent(QPaintEvent *paintevent);

private:
	void drawPixel(QPoint p, RTXW::vec3 c) {
		ptr_image_->setPixelColor(p, QColor(int(255.99*c.r()), int(255.99*c.g()), int(255.99*c.b())));
	}
	

	QImage		*ptr_image_;

	QPoint image_offset_;
};
