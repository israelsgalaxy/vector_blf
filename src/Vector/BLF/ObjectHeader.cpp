/*
 * Copyright (C) 2013 Tobias Lorenz.
 * Contact: tobias.lorenz@gmx.net
 *
 * This file is part of Tobias Lorenz's Toolkit.
 *
 * Commercial License Usage
 * Licensees holding valid commercial licenses may use this file in
 * accordance with the commercial license agreement provided with the
 * Software or, alternatively, in accordance with the terms contained in
 * a written agreement between you and Tobias Lorenz.
 *
 * GNU General Public License 3.0 Usage
 * Alternatively, this file may be used under the terms of the GNU
 * General Public License version 3.0 as published by the Free Software
 * Foundation and appearing in the file LICENSE.GPL included in the
 * packaging of this file.  Please review the following information to
 * ensure the GNU General Public License version 3.0 requirements will be
 * met: http://www.gnu.org/copyleft/gpl.html.
 */

#include "ObjectHeader.h"

namespace Vector {
namespace BLF {

ObjectHeader::ObjectHeader() :
    ObjectHeaderBase(),
    objectFlags(ObjectFlags::TimeOneNans),
    reserved(),
    objectVersion(),
    objectTimeStamp()
{
    headerVersion = 1;
}

void ObjectHeader::read(AbstractFile & is)
{
    ObjectHeaderBase::read(is);
    is.read(reinterpret_cast<char *>(&objectFlags), sizeof(objectFlags));
    is.read(reinterpret_cast<char *>(&reserved), sizeof(reserved));
    is.read(reinterpret_cast<char *>(&objectVersion), sizeof(objectVersion));
    is.read(reinterpret_cast<char *>(&objectTimeStamp), sizeof(objectTimeStamp));
}

void ObjectHeader::write(AbstractFile & os)
{
    ObjectHeaderBase::write(os);
    os.write(reinterpret_cast<char *>(&objectFlags), sizeof(objectFlags));
    os.write(reinterpret_cast<char *>(&reserved), sizeof(reserved));
    os.write(reinterpret_cast<char *>(&objectVersion), sizeof(objectVersion));
    os.write(reinterpret_cast<char *>(&objectTimeStamp), sizeof(objectTimeStamp));
}

WORD ObjectHeader::calculateHeaderSize() const
{
    return
        ObjectHeaderBase::calculateHeaderSize() +
        sizeof(objectFlags) +
        sizeof(reserved) +
        sizeof(objectVersion) +
        sizeof(objectTimeStamp);
}

DWORD ObjectHeader::calculateObjectSize() const
{
    return calculateHeaderSize();
}

}
}
