#ifndef __event_h__
#define __event_h__

#include "types.h"

namespace KeyPet {

enum EventSignal { EventSignal_None = 0, EventSignal_Quit };

int eventHandler(Context *ctx);

} // namespace KeyPet

#endif /* __event_h__ */