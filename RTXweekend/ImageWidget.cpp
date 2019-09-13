#include "ImageWidget.h"

const int DEFAULT_WIDTH  = 200;
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
	for (int w = 0; w < DEFAULT_WIDTH; w++) {
		for (int h = 0; h < DEFAULT_HEIGHT; h++) {
			QPoint p(w, h);
			float r = float(w) / float(DEFAULT_WIDTH);
			float g = float(h) / float(DEFAULT_HEIGHT);
			float b = 0.2f;
			drawPixel(p, vec3(r, g, b));
		}
	}
	update();
}
