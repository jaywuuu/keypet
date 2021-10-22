#ifndef __render_h__
#define __render_h__

#include "SDLlib.h"
#include "types.h"

namespace KeyPet {

void render(Context &context, SDLRenderer &renderer);
void present(SDLRenderer &renderer);

} // namespace KeyPet

#endif /* __render_h__ */