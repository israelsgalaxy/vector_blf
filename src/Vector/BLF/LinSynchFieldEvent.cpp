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

#include "LinSynchFieldEvent.h"

#include <cstring>

namespace Vector {
namespace BLF {

LinSynchFieldEvent::LinSynchFieldEvent() :
    LinBusEvent(),
    synchBreakLength(),
    synchDelLength()
{
}

char * LinSynchFieldEvent::read(char * buffer)
{
    size_t size;

    // preceding data
    buffer = LinBusEvent::read(buffer);

    // synchBreakLength
    size = sizeof(synchBreakLength);
    memcpy((void *) &synchBreakLength, buffer, size);
    buffer += size;

    // synchDelLength
    size = sizeof(synchDelLength);
    memcpy((void *) &synchDelLength, buffer, size);
    buffer += size;

    return buffer;
}

char * LinSynchFieldEvent::write(char * buffer)
{
    size_t size;

    // preceding data
    buffer = LinBusEvent::write(buffer);

    // synchBreakLength
    size = sizeof(synchBreakLength);
    memcpy(buffer, (void *) &synchBreakLength, size);
    buffer += size;

    // synchDelLength
    size = sizeof(synchDelLength);
    memcpy(buffer, (void *) &synchDelLength, size);
    buffer += size;

    return buffer;
}

size_t LinSynchFieldEvent::calculateObjectSize()
{
    size_t size =
        LinBusEvent::calculateObjectSize() +
        sizeof(synchBreakLength) +
        sizeof(synchDelLength);

    return size;
}

}
}
