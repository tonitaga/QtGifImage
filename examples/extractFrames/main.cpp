#include <QDebug>

#include <gifimage/qgifimage.h>

int main()
{
    QGifImage gif("test.gif");

    for (int i=0; i<gif.frameCount(); ++i) {
        QImage image = gif.frame(i);

        qDebug()<<QString("Frame %1: size %2X%3 at (%4, %5)").arg(i)
                  .arg(image.width()).arg(image.height())
                  .arg(image.offset().x()).arg(image.offset().y());

        image.save(QString("test_%1.png").arg(i));
    }

    return 0;
}
