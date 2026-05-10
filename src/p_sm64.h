
#include <libsm64.h>
#include "d_player.h"

void SM64_Init();
void SM64_HWRenderer();

void SM64_marioInit(player_t *p);
void SM64_LevelInit();
// SM64MarioState SM64_initMario();

extern size_t numsurfaces;
extern struct SM64Surface* surfaces;