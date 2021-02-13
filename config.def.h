/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int showextrabar		= 1;		/* 0 means no extra bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int startontag         = 1;        /* 0 means no tag active on start */
static const char statussep		= ';';      /* separator between status bars */
static const int user_bh            = 0;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const unsigned int diff_volume = 2;      /* means the volume that MPD will increase or reduce, if 0 does nothing */
static const double defaultopacity  = 0.75;

static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_urgborder[]   = "#ff0000";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeStatus]		= { col_gray3, col_gray1,	"#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeTagsSel]		= { col_gray4, col_cyan,	"#000000"  }, // Tagbar left selected {text,background,not used but cannot be empty}
    [SchemeTagsNorm]	= { col_gray3, col_gray1,	"#000000"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
    [SchemeInfoSel]		= { col_gray4, col_cyan,	"#000000"  }, // infobar middle  selected {text,background,not used but cannot be empty}
    [SchemeInfoNorm]	= { col_gray3, col_gray1,	"#000000"  }, // infobar middle  unselected {text,background,not used but cannot be empty}
	[SchemeUrg]			= { col_gray4, col_cyan,	col_urgborder  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "[D]",      deck },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

#include "mpdcontrol.c"

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       33 /* p */,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             36 /* enter */, spawn,          {.v = termcmd } },
	{ MODKEY,                       56 /* b */,      togglebar,      {0} },
	{ MODKEY,                       56 /* b */,      toggleextrabar, {0} },
	{ MODKEY|ShiftMask,             44 /* j */,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             45 /* k */,      rotatestack,    {.i = -1 } },
	{ MODKEY,                       44 /* j */,      focusstack,     {.i = +1 } },
	{ MODKEY,                       45 /* k */,      focusstack,     {.i = -1 } },
	{ MODKEY,                       31 /* i */,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       40 /* d */,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       43 /* h */,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       46 /* l */,      setmfact,       {.f = +0.05} },
	{ MODKEY|Mod4Mask,              43 /* h */,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod4Mask,              46 /* l */,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    43 /* h */,      incrogaps,      {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    46 /* l */,      incrogaps,      {.i = -1 } },
	{ MODKEY|Mod4Mask|ControlMask,  43 /* h */,      incrigaps,      {.i = +1 } },
	{ MODKEY|Mod4Mask|ControlMask,  46 /* l */,      incrigaps,      {.i = -1 } },
	{ MODKEY|Mod4Mask,              19 /* 0 */,      togglegaps,     {0} },
	{ MODKEY|Mod4Mask|ShiftMask,    19 /* 0 */,      defaultgaps,    {0} },
	{ MODKEY,                       29 /* y */,      incrihgaps,     {.i = +1 } },
	{ MODKEY,                       32 /* o */,      incrihgaps,     {.i = -1 } },
	{ MODKEY|ControlMask,           29 /* y */,      incrivgaps,     {.i = +1 } },
	{ MODKEY|ControlMask,           32 /* o */,      incrivgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              29 /* y */,      incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask,              32 /* o */,      incrohgaps,     {.i = -1 } },
	{ MODKEY|ShiftMask,             29 /* y */,      incrovgaps,     {.i = +1 } },
	{ MODKEY|ShiftMask,             32 /* o */,      incrovgaps,     {.i = -1 } },
	{ MODKEY,                       36 /* enter */, zoom,           {0} },
	{ MODKEY,                       23 /* tab */,    view,           {0} },
	{ MODKEY|ShiftMask,             54 /* c */,      killclient,     {0} },
	{ MODKEY,                       28 /* t */,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       41 /* f */,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       58 /* m */,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       54 /* c */,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       65 /* space */,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             65 /* space */,  togglefloating, {0} },
	{ MODKEY|ShiftMask|ControlMask,	65 /* space */,  togglealwaysontop, {0} },
	{ MODKEY,                       19 /* 0 */,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             19 /* 0 */,      tag,            {.ui = ~0 } },
	{ MODKEY,                       59 /* comma */,  focusmon,       {.i = -1 } },
	{ MODKEY,                       60 /* period */, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             59 /* comma */,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             60 /* period */, tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,				86 /* Add */, changeopacity,  {.f = +0.1}},
	{ MODKEY|ShiftMask,				82 /* Subtract */, changeopacity,  {.f = -0.1}},
    TAGKEYS(						10 /* 1 */,				   0)
    TAGKEYS(						11 /* 2 */,				   1)
    TAGKEYS(						13 /* 3 */,				   2)
    TAGKEYS(						14 /* 4 */,				   3)
    TAGKEYS(						15 /* 5 */,				   4)
    TAGKEYS(						16 /* 6 */,				   5)
    TAGKEYS(						17 /* 7 */,				   6)
    TAGKEYS(						18 /* 8 */,				   7)
    TAGKEYS(						19 /* 9 */,				   8)
	{ MODKEY|ShiftMask,             24 /* q */,      quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask, 24 /* q */,      quit,           {1} }, 
	{ MODKEY,                       67 /* F1 */,     mpdchange,      {.i = -1} },
	{ MODKEY,                       68 /* F2 */,     mpdchange,      {.i = +1} },
	{ MODKEY,                       9 /* esc */, mpdcontrol,     {0} },
    { MODKEY,                       69 /* F3 */,     mpd_volume,     {.i = -diff_volume } },
    { MODKEY,                       70 /* F4 */,     mpd_volume,     {.i = +diff_volume } },
 };
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
