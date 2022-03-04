void bhv_nup_interact(void) {
    if (obj_check_if_collided_with_object(o, gMarioObject)) {
        play_sound(SOUND_GENERAL_COLLECT_1UP, gGlobalSoundSource);
#ifdef MUSHROOMS_HEAL
        gMarioState->healCounter   = 31;
#ifdef BREATH_METER
        gMarioState->breathCounter = 31;
#endif
#endif
        if (gMarioState->action & ACT_GROUND_POUND || gMarioState->action & ACT_GROUND_POUND_LAND) gMarioState->numLives += o->oBehParams2ndByte * 2;
        else gMarioState->numLives += o->oBehParams2ndByte;

#ifdef SAVE_NUM_LIVES
        save_file_set_num_lives(gMarioState->numLives);
#endif
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
#if ENABLE_RUMBLE
        queue_rumble_data(5, 80);
#endif
    }
}

void bhv_nup_loop(void) {
    bhv_nup_interact();
}