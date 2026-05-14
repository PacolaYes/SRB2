
#include <libsm64.h>
#include "d_player.h"
#include "m_fixed.h"

#define MARIO_SCALE 1.0
#define SRB2_TO_SM64_POS(x) (FLOAT_TO_FIXED(x) * MARIO_SCALE)

void SM64_Init();
void SM64_HWRenderer();

void SM64_marioInit(player_t *p);
void SM64_LevelInit();
// SM64MarioState SM64_initMario();