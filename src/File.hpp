// hamfax -- an application for sending and receiving amateur radio facsimiles
// Copyright (C) 2001,2002
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

#ifndef FILE_HPP
#define FILE_HPP

#include <qobject.h>
#include <audiofile.h>
#include <qtimer.h>

class File : public QObject {
	Q_OBJECT
public:
	File(QObject* parent);
	~File(void);
	int startOutput(const QString& fileName);
	int startInput(const QString& fileName);
	void end(void);
private:
	static const int blockSize=512;
	AFfilehandle aFile;
	QTimer* timer;
signals:
	void data(short* buffer, int n);
	void next(int n);
	void deviceClosed(void);
public slots:
	void write(short* samples, int number);
	void timerSignal(void);
private slots:
        void read(void);
};

#endif
