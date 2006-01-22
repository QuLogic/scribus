/*
For general Scribus (>=1.3.2) copyright and licensing information please refer
to the COPYING file provided with the program. Following this notice may exist
a copyright and/or license notice that predates the release of Scribus 1.3.2
for which a new license (GPL+exception) is in place.
*/
/***************************************************************************
                          mspinbox.h  -  description
                             -------------------
    begin                : Sat Jun 16 2001
    copyright            : (C) 2001 by Franz Schmid
    email                : Franz.Schmid@altmuehlnet.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef MSPINBOX_H
#define MSPINBOX_H

#include <qmap.h>
#include <qspinbox.h>
#include "scribusapi.h"

class FunctionParser;

/**
  *@author Franz Schmid
  */

class SCRIBUS_API MSpinBox : public QSpinBox  
{
	Q_OBJECT
	
public: 
	MSpinBox(QWidget *pa, int s);
	MSpinBox(double minValue, double maxValue, QWidget *pa, int s);
	~MSpinBox() {};
	double value();
	double minValue();
	double maxValue();
	QString mapValueToText(int value);
	int mapTextToValue(bool *ok);
	int Decimals;
	int Width;
	QLineEdit *ed;
	void setDecimals( int deci );
	bool isReadOnly() const;
	void setConstants(const QMap<QString, double>&);

public slots:
	void textChanged();
	void stepDown();
	void setMaxValue(double val);
	void setMinValue(double val);
	void setValue(double val);
	void setReadOnly(bool ro);
	void setValues(double min, double max, int deci, double val);
	void getValues(double *min, double *max, int *deci, double *val);

protected:
	bool eventFilter( QObject* ob, QEvent* ev );
	void setParameters( int s );
	void setFPConstants(FunctionParser &fp);
	bool readOnly;
	int oldLineStep;
	bool edited;
	QMap <QString, double> functionParserConstants;
};

#endif
