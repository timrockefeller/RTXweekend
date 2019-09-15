#pragma once
#include <qwidget.h>

#include <QImage>
#include <qcolor.h>
#include <QPainter>

#include "vec3.h"
#include "ray.h"

#include "util.h"
#include "camera.h"

#include "hitablelist.h"
#include "sphere.h"

QT_BEGIN_NAMESPACE
class QImage;
class QPainter;
QT_END_NAMESPACE




class ImageWidget :
	public QWidget
{
	Q_OBJECT
public:
	ImageWidget();
	~ImageWidget();
	
public slots:
	void genImage();
	void saveImage();

protected:
	void paintEvent(QPaintEvent *paintevent);

private:
	void drawPixel(QPoint p, RTXW::vec3 c);
	

	QImage		*ptr_image_;

	QPoint image_offset_;
	float image_zoom_;

};
