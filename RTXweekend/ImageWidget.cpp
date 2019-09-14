#include "ImageWidget.h"


using namespace RTXW;

const int DEFAULT_WIDTH = 400;
const int DEFAULT_HEIGHT = 200;
const int SAMPLES_PER_PIXEL = 100;

ImageWidget::ImageWidget()
{

	ptr_image_ = new QImage(DEFAULT_WIDTH, DEFAULT_HEIGHT, QImage::Format::Format_RGB32);
	update();
	genImage();
	image_zoom_ = 2.0;
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
	QRect rect = QRect((width() - image_zoom_ * ptr_image_->width()) / 2, (height() - image_zoom_ * ptr_image_->height()) / 2, image_zoom_ * ptr_image_->width(), image_zoom_ * ptr_image_->height());
	painter.drawImage(rect, *ptr_image_);
	image_offset_.setX((width() - image_zoom_ * ptr_image_->width()) / 2);
	image_offset_.setY((height() - image_zoom_ * ptr_image_->height()) / 2);
	painter.end();
}

void ImageWidget::drawPixel(QPoint p, RTXW::vec3 c) {
	c = sqrtv(c);
	ptr_image_->setPixelColor(p, QColor(
		int(255.99*c.r()),
		int(255.99*c.g()),
		int(255.99*c.b())
	));
}

void ImageWidget::genImage()
{
	camera cam;

	hitable *list[4];
	list[0] = new sphere(vec3(0, 0, -1), 0.5, new lambertain(vec3(0.8, 0.3, 0.3)));
	list[1] = new sphere(vec3(0, -100.5, -1), 100, new lambertain(vec3(0.8, 0.8, 0.0)));
	list[2] = new sphere(vec3(1, 0, -1), 0.5, new metal(vec3(0.8), 0.3));
	list[3] = new sphere(vec3(-1, 0, -1), 0.5, new metal(vec3(0.8, 0.6, 0.2), 1));
	hitablelist *world = new hitablelist(list, 4);

	for (int w = 0; w < DEFAULT_WIDTH; w++) {
		for (int h = DEFAULT_HEIGHT - 1; h >= 0; h--) {
			QPoint p(w, DEFAULT_HEIGHT - h - 1);
			vec3 c(0);
			for (size_t s = 0; s < SAMPLES_PER_PIXEL; s++) {
				float u = (float(w) + drand()) / float(DEFAULT_WIDTH);
				float v = (float(h) + drand()) / float(DEFAULT_HEIGHT);
				c += U::color(cam.getRay(u, v), world);
			}
			c /= SAMPLES_PER_PIXEL;
			drawPixel(p, c);
		}
	}
	update();
}
