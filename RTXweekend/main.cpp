#include "RTXweekend.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RTXweekend w;
	w.show();
	return a.exec();
}
