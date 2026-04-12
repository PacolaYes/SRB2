
#include <stdlib.h>
#include <stdio.h>

#include <libsm64.h>
#include "p_sm64.h"

#include "doomdef.h"

#include "d_player.h"

#include "m_fixed.h"
#include "m_misc.h"

#include "z_zone.h"

void SM64_Init() {
    if (!FIL_FileExists("baserom.us.z64")) {
        I_Error("baserom.us.z64 not found!");
        return;
    }

    uint8_t *rom;

    size_t romSize = FIL_ReadFile("baserom.us.z64", &rom);

    if( rom == NULL )
    {
        I_Error("baserom.us.z64 not found!");
        //printf("\nFailed to read ROM file \"baserom.us.z64\"\n\n");
        return;
    }

    uint8_t *texture = (uint8_t*)malloc( 4 * SM64_TEXTURE_WIDTH * SM64_TEXTURE_HEIGHT );

    sm64_global_terminate();
    sm64_global_init(rom, texture );
    sm64_audio_init(rom);
}

void SM64_marioInit(player_t *p) {
    // TODO: this needs geometry to properly work, so figure that one out next
    int32_t marioId = sm64_mario_create( FIXED_TO_FLOAT(p->mo->x), FIXED_TO_FLOAT(p->mo->z), FIXED_TO_FLOAT(p->mo->y));
    CONS_Printf("marioID: %d\n", marioId);
    p->marioID = marioId;

    CONS_Printf("Mario initiated.\n");
}