#include "ImageWidget.h"
using namespace RTXW;

const int DEFAULT_WIDTH = 200;
const int DEFAULT_HEIGHT = 100;

ImageWidget::ImageWidget()
{

	ptr_image_ = new QImage(DEFAULT_WIDTH, DEFAULT_HEIGHT, QImage::Format::Format_RGB32);
	genImage();

}


ImageWidget::~ImageWidget()
{
	delete ptr_image_;
}

void ImageWidget::paintEvent(QPaintEvent *paintevent)
{
	QPainter painter;
	painter.begin(this);

	// Draw background
	painter.setBrush(Qt::lightGray);
	QRect back_rect(0, 0, width(), height());
	painter.drawRect(back_rect);

	// Draw image
	QRect rect = QRect((width() - ptr_image_->width()) / 2, (height() - ptr_image_->height()) / 2, ptr_image_->width(), ptr_image_->height());
	painter.drawImage(rect, *ptr_image_);
	image_offset_.setX((width() - ptr_image_->width()) / 2);
	image_offset_.setY((height() - ptr_image_->height()) / 2);
	painter.end();
}

void ImageWidget::genImage()
{
	camera cam;

	hitable *list[2];
	list[1] = new sphere(vec3(0, 0, -1), 0.5);
	list[0] = new sphere(vec3(0, -100.5, -1), 100);
	hitablelist *world = new hitablelist(list, 2);

	for (int w = 0; w < DEFAULT_WIDTH; w++) {
		for (int h = DEFAULT_HEIGHT - 1; h >= 0; h--) {
			QPoint p(w, DEFAULT_HEIGHT - h - 1);
			float u = float(w) / float(DEFAULT_WIDTH);
			float v = float(h) / float(DEFAULT_HEIGHT);
			vec3 c = U::color(cam.getRay(u, v), world);
			drawPixel(p, c);
		}
	}
	update();
}
