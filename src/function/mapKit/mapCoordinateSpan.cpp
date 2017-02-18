/*****************************************************************************
 * mapCoordinateSpan.cpp
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

#include "mapCoordinateSpan.h"

mapCoordinateSpan::mapCoordinateSpan() : _latitudeDelta(0.0), _longitudeDelta(0.0)
{
}

mapCoordinateSpan::mapCoordinateSpan(qreal latitudeDelta, qreal longitudeDelta) :
    _latitudeDelta(latitudeDelta), _longitudeDelta(longitudeDelta)
{
}

qreal mapCoordinateSpan::latitudeDelta() const
{
    return _latitudeDelta;
}

void mapCoordinateSpan::setLatitudeDelta(qreal latitudeDelta)
{
    _latitudeDelta = latitudeDelta;
}

qreal mapCoordinateSpan::longitudeDelta() const
{
    return _longitudeDelta;
}

void mapCoordinateSpan::setLongitudeDelta(qreal longitudeDelta)
{
    _longitudeDelta = longitudeDelta;
}

bool mapCoordinateSpan::operator==(const mapCoordinateSpan &other)
{
    return (latitudeDelta() == other.latitudeDelta())
           && (longitudeDelta() == other.longitudeDelta());
}