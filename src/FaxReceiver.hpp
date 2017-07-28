// hamfax -- an application for sending and receiving amateur radio facsimiles
// Copyright (C) 2001, 2004
// Christof Schmitt, DH1CS <cschmitt@users.sourceforge.net>
//  
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//  
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef FAXRECEIVER_HPP
#define FAXRECEIVER_HPP

#include <QObject>
#include <QString>
#include <QTimer>
#include <QVector>

class FaxReceiver : public QObject {
	Q_OBJECT
public:
	FaxReceiver(QObject* parent);
	void init(int sampleRate);
private:
	void decodeApt(const int& x);
	void decodePhasing(const int& x);
	void decodeImage(const int& x);
	enum { APTSTART, PHASING, IMAGE, DONE } state;
	int sampleRate;
	int currentValue;
	bool aptHigh;
	int aptTrans;    // APT low-high transitions
	int aptCount;    // samples counted for aptTrans
	int aptStartFreq;
	int aptStopFreq;
	bool aptStop;
	bool phaseHigh;
	int currPhaseLength;
	int currPhaseHigh;
	int phaseLines;
	int noPhaseLines;
	bool phaseInvers;
	double lpm;
	int txLPM;
	double lpmSum;
	int width;
	int imageSample;
	int lastCol;
	int lastRow;
	int pixel;
	int pixelSamples;
	bool color;
	QTimer* timer;
	QVector<unsigned char> rawData;
	QVector<unsigned char>::Iterator rawIt;
signals:
	void aptFound(int);
	void aptStopDetected(void);
	void setPixel(int, int, int, int);
	void startReception(void);
	void end(void);
	void startingPhasing(void);
	void phasingLine(double);
	void row(int);
	void bufferNotEmpty(bool);
	void imageWidth(int);
	void newSize(int, int, int, int);
	void imageStarts(void);
	void redrawStarts(void);
public slots:
	void decode(int*, int n);
        void setAptStartFreq(int f);
	void setAptStopFreq(int f);
	void setWidth(int width);
	void setPhasePol(bool pol);
	void skip(void);
	void endReception(void);
	void setColor(bool b);
	void correctLPM(double d);
	void correctWidth(int w);
	void releaseBuffer(void);
private slots:
        void adjustNext(void);
};

#endif
