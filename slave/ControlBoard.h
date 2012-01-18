/*
 * Copyright 2012 Tuomas Kulve, <tuomas.kulve@snowcap.fi>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef _CONTROLBOARD_H
#define _CONTROLBOARD_H

#include <QString>
#include <QTcpSocket>

#define  CB_PWM1       1
#define  CB_PWM2       2
#define  CB_PWM3       3
#define  CB_PWM4       4
#define  CB_PWM5       5
#define  CB_PWM6       6
#define  CB_PWM7       7
#define  CB_PWM8       8


class ControlBoard : public QObject
{
  Q_OBJECT;

 public:
  ControlBoard(QString serialDevice);
  ~ControlBoard();
  bool init(void);
  void setPWMFreq(quint32 freq);
  void setPWMDuty(quint8 pwm, quint16 duty);
  void stopPWM(quint8 pwm);

 private slots:
  void readPendingSerialData();

 private:
  void parseSerialData(void);
  bool openSerialDevice(void);

  int serialFD;
  QString serialDevice;
  QTcpSocket serialPort;
  QByteArray serialData;
  bool enabled;
};

#endif
