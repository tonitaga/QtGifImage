/****************************************************************************
** Copyright (c) 2013 Debao Zhang <hello@debao.me>
** All right reserved.
**
** Permission is hereby granted, free of charge, to any person obtaining
** a copy of this software and associated documentation files (the
** "Software"), to deal in the Software without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Software, and to
** permit persons to whom the Software is furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be
** included in all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
** NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
** LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
** OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
** WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**
****************************************************************************/
#ifndef GIF_IMAGE_Q_GIF_IMAGE_H_
#define GIF_IMAGE_Q_GIF_IMAGE_H_

#include <gifimage/qgifglobal.h>

#include <QList>
#include <QImage>
#include <QColor>
#include <QVector>

class QGifImagePrivate;

class QGifImage {
  Q_DECLARE_PRIVATE(QGifImage)

public:
  QGifImage();
  explicit QGifImage(const QString &fileName);
  explicit QGifImage(const QSize &size);

  ~QGifImage();

public:
  [[nodiscard]] QVector<QRgb> globalColorTable() const;
  [[nodiscard]] QColor backgroundColor() const;

  void setGlobalColorTable(const QVector<QRgb> &colors, const QColor &bgColor = QColor());
  [[nodiscard]] int defaultDelay() const;

  void setDefaultDelay(int internal);
  [[nodiscard]] QColor defaultTransparentColor() const;
  void setDefaultTransparentColor(const QColor &color);

  [[nodiscard]] int loopCount() const;
  void setLoopCount(int loop);

  [[nodiscard]] int frameCount() const;
  [[nodiscard]] QImage frame(int index) const;

  void addFrame(const QImage &frame, int delay = -1);
  void addFrame(const QImage &frame, const QPoint &offset, int delay = -1);

  void insertFrame(int index, const QImage &frame, int delay = -1);
  void insertFrame(int index, const QImage &frame, const QPoint &offset, int delay = -1);

  [[nodiscard]] QPoint frameOffset(int index) const;
  void setFrameOffset(int index, const QPoint &offset);

  [[nodiscard]] int frameDelay(int index) const;
  void setFrameDelay(int index, int delay);

  [[nodiscard]] QColor frameTransparentColor(int index) const;
  void setFrameTransparentColor(int index, const QColor &color);

  bool load(QIODevice *device);
  bool load(const QString &fileName);

  bool save(QIODevice *device) const;
  [[nodiscard]] bool save(const QString &fileName) const;

private:
  QGifImagePrivate *const d_ptr;
};

#endif // GIF_IMAGE_Q_GIF_IMAGE_H_
