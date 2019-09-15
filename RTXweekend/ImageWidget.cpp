#include "ImageWidget.h"


using namespace RTXW;

const int DEFAULT_WIDTH = 100;
const int DEFAULT_HEIGHT = 50;
const int SAMPLES_PER_PIXEL = 100;

ImageWidget::ImageWidget()
{

	ptr_image_ = new QImage(DEFAULT_WIDTH, DEFAULT_HEIGHT, QImage::Format::Format_RGB32);
	update();
	genImage();
	image_zoom_ = 4.0;
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
	vec3 lookfrom(1, 0.5, 0);
	vec3 lookto(0, 0, -1);
	float aperture = 2.0;
	camera cam(lookfrom, lookto, vec3(0, 1, 0), 60, float(DEFAULT_WIDTH) / float(DEFAULT_HEIGHT), aperture, (lookfrom - lookto).length());
	
	hitable * world = U::random_scene();

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
