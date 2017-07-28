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

#ifndef PTT_HPP
#define PTT_HPP

#include "config.h"
#include <qstring.h>
#include <qfile.h>

#ifdef HAVE_LIBHAMLIB
#include <hamlib/rig.h>
#endif

class PTT {
public:
	PTT(void);
	~PTT(void);
	void set(void);
	void release(void);
private:
	QFile device;
#ifdef HAVE_LIBHAMLIB
        bool hamlibInit(void);
        void hamlibClose(void);
	void hamlibSetPtt(ptt_t aPtt);
	RIG  *hamlibRigPtr;
#endif

};

#endif
