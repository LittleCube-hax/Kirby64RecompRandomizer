#include "modding.h"
#include "recomputils.h"
#include "recompconfig.h"

#include "PR/ultratypes.h"
#include <ultra64.h>
#include <PR/gu.h>
#include <macros.h>
#include "D_8004A7C4.h"
#include "types.h"
#include "ovl0/ovl0_4.h"
#include "ovl0/ovl0_2.h"
#include "ovl0/ovl0_2_5.h"
#include "ovl0/ovl0_6.h"
#include "ovl1/save_file.h"

u8 ovl1_TamperCheck(void);

void func_800A6B18(void) ;


void load_overlay(u32);

extern s32 D_800D7288;
extern s32 gGameState;
extern u32 gCurrentLevel;
extern u32 gCurrentWorld;
extern s32 D_800D6B74;
extern s32 D_800D6B60;
extern u32 D_800D6B68;
extern u32 D_800D6B78;
extern u32 D_800BE500;
extern u32 D_800D6B98;
extern s32 D_800BE504, D_800D6B9C;
extern u8 D_800D6B84;
extern u32 D_800BE530;
extern s32 D_800D6F38, D_800D6F3C;
extern u32 D_800BE51C;
extern u32 D_800BE4FC, D_800BE518;
extern u32 D_800BE534;
extern u32 D_800BE520;
extern u32 D_800BE508, D_800BE50C;
extern u32 D_800BE538;
extern u32 D_800BE53C, D_800BE524;
extern u32 D_800BE510;
extern s32 D_800D6BA8;
extern u32 D_800D71E8;

extern s32 D_800D6B88;
extern s32 gKirbyLives;
extern f32 gKirbyHp;
extern s32 D_800D6E54;
extern f32 D_800D6E58;
extern f32 D_800D6E5C;
extern s32 gKirbyStars;
extern s32 D_800D6B7C;
extern s32 D_800D6B80;
extern s32 D_800D6B44;
extern s32 D_800D6F50;
extern s32 D_800EC9FC;
void func_80154D60_ovl6(u32, u32);

void load_overlay(u32 ovl);

void crash_screen_print_gobj_info(struct GObj *gobj);

extern u32 D_8003DE54;
extern struct GObjProcess *D_8004A7D0;
extern u32 D_80048D88, D_80048D8C, D_80048D90;

OSThread *crash_screen_print_page_3(void);


extern u32 D_800BE4F8;
extern u32 D_800D6B48;
extern u32 D_800D6F54;

extern void *D_800A2904; // struct

extern u32 D_800D6B18;
extern u8 D_800D6B00[], D_800BE3F0[];
void func_800A2B9C(void);

void func_800A2CE4(void);

void func_800A3058(void);

void func_800A30E8(void);

void load_menu_overlays(void);

extern u32 D_800BE4F8;
extern u32 D_800D6B8C;

void func_800A3228(void);

u16 func_800F8560(void);
s32 func_80151CEC_ovl4(s32 arg0);

int func_800BE320(s32*);
int func_800A2C80();
int func_800A3150(int);
int func_800B87E0();
int func_80158048_ovl4();
int func_800B8AD4(s32);
int func_800A3408();

s32 set_cutscene_watched(s32 arg0, s32 fileNum);

int func_80020C88();

int func_800B9C50(s32);
int func_800A2D5C();
int func_80159A54_ovl4();
int func_800A2D68();
int func_8015531C_ovl4();
int func_800A2E98();
int func_800F6AD4(int);
int func_800A74D8();
int func_80020C88_ovl1();
int func_800A3230();
int func_800A336C();
int func_800B9D60(s32, int);
int func_80159EFC_ovl4();
int func_800A36C0();
int func_800A34C8();
int func_8017F594_ovl5();
int func_8017CC3C_ovl5();
int func_801822AC_ovl5();
int func_801802A8_ovl5();
int func_8017ECA4_ovl5();
int func_80182FE8_ovl5();
int func_80185EEC_ovl5();
int func_80177A30_ovl5();
int func_8016FAB0_ovl5();
int func_80165370_ovl5();
int func_80179D48_ovl5();

RECOMP_PATCH void game_tick(s32 arg0) {
    s32 temp_t0;
    s32 temp_t0_2;
    s32 temp_t1;
    s32 temp_t1_2;
    s32 temp_t2;
    s32 temp_t3;
    s32 temp_t6;
    s32 temp_t6_2;
    s32 temp_t7;
    s32 temp_t9;
    s32 temp_v0;
    s32 temp_v1;

    func_800BE320(&D_800D7288);
    func_800A2B9C();
    func_800A6B18();
    load_overlay(1);
    func_800A2C80();
    func_800A3058();
    while (1) {

        func_800A2C80();
        switch (gGameState) {                           /* switch 1 */
            default:                                            /* switch 1 */
                continue;
            case 1:                                     /* switch 1 */
                load_overlay(2);
                func_80151CEC_ovl4(0);
                gGameState = 2;
                continue;
            case 2:                                     /* switch 1 */
                if (D_800D6B74 == 1) {
                    load_overlay(4);
                    func_80154D60_ovl6(0, 1);
                }
                gGameState = 3;
                D_800D6B60 = 3;
                continue;
            case 3:                                     /* switch 1 */
                load_overlay(2);
                if (func_80151CEC_ovl4(1) == 2) {
                    gGameState = 4;
                } else {
                    func_800A3228();
                    temp_t2 = gGameState;
                    gGameState = 0xA;
                    D_800D6B68 = temp_t2;
                }
                continue;
            case 4:                                     /* switch 1 */
                func_800A3150(5);
                gGameState = 5;
                D_800D6B60 = 5;
                continue;
            case 5:                                     /* switch 1 */
                load_overlay(2);
                if (func_80151CEC_ovl4(1) == 2) {
                    gGameState = 6;
                } else {
                    func_800A3228();
                    temp_t6 = gGameState;
                    gGameState = 0xA;
                    D_800D6B68 = temp_t6;
                }
                continue;
            case 6:                                     /* switch 1 */
                func_800A3150(6);
                gGameState = 7;
                D_800D6B60 = 7;
                continue;
            case 7:                                     /* switch 1 */
                load_overlay(2);
                if (func_80151CEC_ovl4(1) == 2) {
                    gGameState = 8;
                } else {
                    func_800A3228();
                    temp_t0 = gGameState;
                    gGameState = 0xA;
                    D_800D6B68 = temp_t0;
                }
                continue;
            case 8:                                     /* switch 1 */
                func_800A3150(3);
                gGameState = 9;
                D_800D6B60 = 9;
                continue;
            case 9:                                     /* switch 1 */
                load_overlay(2);
                if (func_80151CEC_ovl4(1) == 2) {
                    D_800D6B74 = 1;
                    gGameState = 2;
                } else {
                    func_800A3228();
                    temp_t3 = gGameState;
                    gGameState = 0xA;
                    D_800D6B68 = temp_t3;
                }
                continue;
            case 10:                                    /* switch 1 */
                load_menu_overlays();
                func_800A2CE4();
                func_800B87E0();
                func_80158048_ovl4();
                func_800B8AD4(D_800D6B88);
                if (gGameState == 0xB) {
                    func_800A3408();
                }
                continue;
            case 11:                                    /* switch 1 */
                if (check_cutscene_watched(1) == 0) {
                    load_overlay(4);
                    set_cutscene_watched(1, D_800D6B88);
                    func_800B9C50(D_800D6B88);
                    func_80154D60_ovl6(1, 2);
                }
                load_menu_overlays();
                func_800A2D5C();
                func_80159A54_ovl4();
                if (D_800D6B78 != 0) {
                    temp_t6_2 = gGameState;
                    gGameState = 0xA;
                    D_800D6B68 = temp_t6_2;
                } else {
                    D_800BE500 = D_800D6B98;
                    if (D_800BE500 == 6) {
                        D_800BE504 = D_800D6B9C;
                        func_800A2D68();
                        gGameState = 0xF;
                    } else {
                        gGameState = 0xC;
                        D_800D6B84 = 1;
                    }
                }
                continue;
            case 12:                                    /* switch 1 */
                load_menu_overlays();
                func_800A2D68();
                func_8015531C_ovl4();
                if (D_800D6B78 == 0) {
                    D_800BE530 = D_800D6B9C;
                    D_800BE504 = D_800D6B9C;
                    gGameState = 0xF;
                } else {
                    gGameState = 0xB;
                }
                D_800D6F38 = 0;
                continue;
            case 14:                                    /* switch 1 */
                gGameState = 0xF;
                continue;
            case 15:                                    /* switch 1 */
                func_800A30E8();
                D_800D6F3C = 0;
                func_800A2E98();
                func_800F6AD4(0);
                switch (D_800BE4F8) {                   /* switch 2 */
                    case 6:                             /* switch 2 */
                        gGameState = 0x11;
                        temp_t1 = gKirbyLives - 1;
                        gKirbyLives = temp_t1;
                        if (temp_t1 > 0) {
                            temp_v0 = func_800F8560();
                            switch (temp_v0) {          /* switch 4; irregular */
                                case 2:                 /* switch 4 */
                                    gKirbyHp = 6.0f;
                                    D_800D6E54 = 0;
                                    func_800A74D8();
                                    gGameState = 0xC;
                                    D_800D6B84 = 0;
                                    break;
                                default:                /* switch 4 */
                                case 9:                 /* switch 4 */
                                    gKirbyHp = 6.0f;
                                    D_800D6E54 = 0;
                                    D_800BE4FC = D_800BE518;
                                    D_800BE534 = D_800BE51C;
                                    D_800BE508 = D_800BE51C;
                                    D_800BE538 = D_800BE520;
                                    D_800BE50C = D_800BE520;
                                    D_800BE53C = D_800BE524;
                                    D_800BE510 = D_800BE53C;
                                    gGameState = 0xF;
                                    break;
                            }
                        }
                        func_800A74D8();
                        break;
                    case 2:                             /* switch 2 */
                        func_80020C88();
                        func_800A3230();
                        break;
                    case 3:                             /* switch 2 */
                        temp_v1 = D_800D6B9C + 1;
                        if (gCurrentLevel == ((u32) temp_v1) && gCurrentWorld == (D_800D6B98 + 1)) {
                            D_800D6B9C = temp_v1;
                            gCurrentLevel += 1;
                            func_800B9C50(D_800D6B88);
                            D_800D6B80 = 1;
                        }
                        func_800A74D8();
                        if (func_800F8560() != 9) {
                            gGameState = 0xC;
                            D_800D6B84 = 0;
                        } else {
                            gGameState = 0xB;
                            D_800D6B84 = 0;
                        }
                        break;
                    case 4:                             /* switch 2 */
                        switch (D_800BE500) {           /* switch 3 */
                            case 0:                     /* switch 3 */
                            case 1:                     /* switch 3 */
                            case 2:                     /* switch 3 */
                            case 3:                     /* switch 3 */
                            case 4:                     /* switch 3 */
                                if ((gCurrentWorld == (D_800D6B98 + 1)) && (gCurrentWorld < 7)) {
                                    gCurrentWorld += 1;
                                    gCurrentLevel = 1;
                                    D_800D6B7C = 1;
                                    func_800B9C50(D_800D6B88);
                                }
                                func_800A74D8();
                                func_800A336C();
                                if (D_800D6B7C != 0) {
                                    gGameState = 0xB;
                                } else {
                                    gGameState = 0xC;
                                }
                                break;
                            case 5:                     /* switch 3 */
                                func_800A74D8();
                                if (ovl1_TamperCheck() == 0) {
                                    gGameState = 0xB;
                                } else {
                                    if ((gCurrentWorld == (D_800D6B98 + 1)) && (gCurrentWorld < 7)) {
                                        gCurrentWorld += 1;
                                        gCurrentLevel = 1;
                                        func_800B9D60(D_800D6B88, 5);
                                    }
                                    func_800B9C50(D_800D6B88);
                                    gGameState = 0x12;
                                    if (D_800D6BA8 == 0x64) {
                                        gGameState = 0xC;
                                        if (check_cutscene_watched(0xD) == 0) {
                                            D_800BE500 = 6;
                                            D_800D6B98 = 6;
                                            D_800BE508 = 0;
                                            D_800BE504 = 0;
                                            D_800D6B9C = 0;
                                            load_overlay(4);
                                            set_cutscene_watched(0xD, D_800D6B88);
                                            func_800B9C50(D_800D6B88);
                                            func_80154D60_ovl6(0xD, 2);
                                            func_800A2D68();
                                            func_800A2E98();
                                            gGameState = 0xF;
                                        }
                                    }
                                }
                                break;
                        }
                        break;
                    case 7:                             /* switch 2 */
                        if ((gCurrentWorld == (D_800D6B98 + 1)) && (gCurrentWorld < 8)) {
                            gCurrentWorld = 8;
                            gCurrentLevel = 1;
                            func_800B9D60(D_800D6B88, 6);
                        }
                        func_800A74D8();
                        gGameState = 0x13;
                        break;
                    case 0:                             /* switch 2 */
                        func_800A74D8();
                        if (D_800BE500 != 6) {
                            gGameState = 0xC;
                        } else {
                            gGameState = 0xB;
                        }
                        D_800D6B84 = 0;
                        break;
                    default:                            /* switch 2 */
                        gGameState = 1;
                        break;
                }
                func_800B9C50(D_800D6B88);
                continue;
            case 16:                                    /* switch 1 */
            case 17:                                    /* switch 1 */
                load_menu_overlays();
                func_80159EFC_ovl4();
                gGameState = 1;
                continue;
            case 21:                                    /* switch 1 */
                load_overlay(4);
                func_80154D60_ovl6(D_800D71E8, 0x15);
                temp_t7 = gGameState;
                gGameState = 0x17;
                D_800D6B68 = temp_t7;
                continue;
            case 34:                                    /* switch 1 */
                func_800A36C0();
                continue;
            case 18:                                    /* switch 1 */
                load_overlay(4);
                set_cutscene_watched(0x11, D_800D6B88);
                set_cutscene_watched(0x13, D_800D6B88);
                func_800B9C50(D_800D6B88);
                func_80154D60_ovl6(0xE, 2);
                gGameState = 1;
                continue;
            case 19:                                    /* switch 1 */
                load_overlay(4);
                set_cutscene_watched(0xD, D_800D6B88);
                set_cutscene_watched(0x11, D_800D6B88);
                set_cutscene_watched(0x12, D_800D6B88);
                set_cutscene_watched(0x13, D_800D6B88);
                set_cutscene_watched(0x10, D_800D6B88);
                func_800B9C50(D_800D6B88);
                func_80154D60_ovl6(0xF, 0xA);
                gGameState = 1;
                continue;
            case 33:                                    /* switch 1 */
                func_800A34C8();
                continue;
            case 27:                                    /* switch 1 */
                load_menu_overlays();
                func_8017F594_ovl5();
                continue;
            case 28:                                    /* switch 1 */
                load_menu_overlays();
                func_8017CC3C_ovl5();
                continue;
            case 25:                                    /* switch 1 */
                load_menu_overlays();
                func_801822AC_ovl5();
                temp_t0_2 = gGameState;
                gGameState = 0xA;
                D_800D6B68 = temp_t0_2;
                continue;
            case 23:                                    /* switch 1 */
                load_menu_overlays();
                func_801802A8_ovl5();
                continue;
            case 22:                                    /* switch 1 */
                load_menu_overlays();
                func_8017ECA4_ovl5();
                temp_t9 = gGameState;
                gGameState = 0xA;
                D_800D6B68 = temp_t9;
                continue;
            case 26:                                    /* switch 1 */
                load_menu_overlays();
                func_80182FE8_ovl5();
                continue;
            case 24:                                    /* switch 1 */
                load_menu_overlays();
                func_80185EEC_ovl5();
                temp_t1_2 = gGameState;
                gGameState = 0xA;
                D_800D6B68 = temp_t1_2;
                continue;
            case 29:                                    /* switch 1 */
                load_menu_overlays();
                func_80177A30_ovl5();
                continue;
            case 30:                                    /* switch 1 */
                load_menu_overlays();
                func_8016FAB0_ovl5();
                continue;
            case 31:                                    /* switch 1 */
                load_menu_overlays();
                func_80165370_ovl5();
                continue;
        }
        load_menu_overlays();
        func_80179D48_ovl5();
    }
}