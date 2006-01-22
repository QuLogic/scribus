/*
For general Scribus (>=1.3.2) copyright and licensing information please refer
to the COPYING file provided with the program. Following this notice may exist
a copyright and/or license notice that predates the release of Scribus 1.3.2
for which a new license (GPL+exception) is in place.
*/
#ifndef TABMANAGER_H
#define TABMANAGER_H

#include <qvariant.h>
#include <qdialog.h>
#include <qvaluelist.h>

#include "scribusapi.h"
#include "pageitem.h"

class QVBoxLayout;
class QHBoxLayout;
class QPushButton;
class Tabruler;

class SCRIBUS_API TabManager : public QDialog
{
	Q_OBJECT

public:
	TabManager( QWidget* parent, int dEin, QValueList<PageItem::TabRecord> inTab, double wid);
	~TabManager() {};
	Tabruler* TabList;
	QPushButton* OKButton;
	QPushButton* CancelButton;
	QValueList<PageItem::TabRecord> tmpTab;

public slots:
	void exitOK();

protected:
	QVBoxLayout* TabManagerLayout;
	QHBoxLayout* layout10;
	
	double docUnitRatio;
};

#endif // TABMANAGER_H
