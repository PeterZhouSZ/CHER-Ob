/*****************************************************************************
 * mapWidget.h
 *
 * Created: 08/7 2013 by uranusjr
 *
 * Copyright 2013 uranusjr. All rights reserved.
 *
 * This file may be distributed under the terms of GNU Public License version
 * 3 (GPL v3) as defined by the Free Software Foundation (FSF). A copy of the
 * license should have been included with this file, or the project in which
 * this file belongs to. You may also find the details of GPL v3 at:
 * http://www.gnu.org/licenses/gpl-3.0.txt
 *
 * If you have any questions regarding the use of this file, feel free to
 * contact the author of this file, or the owner of the project in which
 * this file belongs to.
 *****************************************************************************/

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include "mapView.h"
#include "mapCoordinateRegion.h"

class Information;

class MapWidget : public QWidget
{
    Q_OBJECT

public:
    MapWidget(QWidget *parent = 0, Information *mInformation = NULL);
    ~MapWidget();
	void startGeoMarking();
	void finishGeoMarking();
	void loadMark(QString name, mapCoordinate coord);
	void makeScreenshot(QString path);
	//// refresh() to be implemented! e.g. close and open another

public slots:
    void log(QString text, QString delimiter = QString("\n"));
    void log(const char *text, QString delimiter = QString("\n"));

private slots:
	void createMark();
    void onMapLoaded();
	void onMouseClicked(mapCoordinate latlong);
    void onMapBecameIdle();
    void onRegionChanged(mapCoordinateRegion region);

private:
	Information *refInformation;
	QVBoxLayout *mainLayout;
    mapView *_mapView;
	QPushButton *markButton;
    QWidget *_controls;
    QTextEdit *_logger;
    void buildControls();
	bool isLoaded;
};

#endif // WIDGET_H
