// -------------------------------- Appearance ---------------------------------

// border pixel of windows
static const unsigned int borderpx          = 2;
// snap pixel 
static const unsigned int snap              = 32;
// horiz inner gap between windows
static const unsigned int gappih            = 6;
// vert inner gap between windows
static const unsigned int gappiv            = 6;
// horiz outer gap between windows and screen edge
static const unsigned int gappoh            = 6;
// vert outer gap between windows and screen edge
static const unsigned int gappov            = 6;
// 0 means no outer gaps
static unsigned int enableoutergaps         = 0;
// 0 means no inner gaps
static unsigned int enableinnergaps         = 1;
// 0: sloppy systray follows selected monitor, >0: pin systray to monitor X 
static const unsigned int systraypinning    = 0;
// systray spacing 
static const unsigned int systrayspacing    = 2;
// 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor
static const int systraypinningfailfirst    = 1;
// 0 means no systray
static const int showsystray                = 1;
// 0 means no bar 
static const int showbar                    = 1;
// 0 means no extra bar
static const int showextrabar               = 1;
// 0 means bottom bar 
static const int topbar                     = 1;
// separator between status bars
static const char statussep                 = ';';
// 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height
static const int user_bh                    = 0;
// 0 means no tag active on start
static const int startontag                 = 0;
// means the volume that MPD will increase or reduce, if 0 does nothing
static const unsigned int diff_volume       = 2;
// opacity for clients
static const double defaultopacity          = 0.9;
// ---------------------------------- Fonts ------------------------------------

static const char *fonts[]    = { "UbuntuMono Nerd Font:size=14:antialias=true:autohint:true" };
static const char dmenufont[] = { "UbuntuMono Nerd Font:size=12:antialias=true:autohint=true" };

// ---------------------------------- Colors -----------------------------------

static const char col_black[]       = "#000000";
static const char col_gray[]        = "#78869a";
static const char col_white[]       = "#ffffff";
static const char col_purple[]      = "#6000ff";
static const char col_red[]         = "#ff0000";

static const char *colors[][3]          = {
//                          fg          bg              border
// Statusbar right
	[SchemeStatus]      = { col_white,  col_black,      col_black },
// Tagbar left selected
    [SchemeTagsSel]     = { col_white,  col_purple,     col_purple },
// Tagbar left used by clients
    [SchemeTagsActive]  = { col_white,  col_black,      col_purple },
// Tagbar left unselected
    [SchemeTagsNorm]    = { col_gray,   col_black,      col_black },
// infobar middle selected
    [SchemeInfoSel]     = { col_white,  col_purple,     col_purple },
// infobar middle unselected
    [SchemeInfoNorm]    = { col_white,  col_black,      col_black },
// border urgent
	[SchemeUrg]         = { col_white,  col_black,      col_red },
};

// -------------------------------- Workspaces ---------------------------------

static const char *tags[] = { " ", "﬏ ", " ", " ", " ", " ", " ", " ", " ", " " };

// -------------------------------- Auto start ---------------------------------

static const char *const autostart[] = {
    "slstatus", NULL,
    "zsh", "-c", "while true; do; echo \"`checkupdates | wc -l `/`yay -Qu | wc -l`\" \
        > ~/.config/.updates; sleep 60; done", NULL,
	NULL /* terminate */
};

// ---------------------------------- Layouts ----------------------------------

// factor of master area size [0.05..0.95]
static const float mfact        = 0.50;
// number of clients in master area
static const int nmaster        = 1;
// 1 means respect size hints in tiled resizals
static const int resizehints    = 1;

#include "tatami.c"
static const Layout layouts[] = {
    // symbol   arrange function
	{ "|+|",    tatami },
    { "[T]",    tile }, // first entry is default
    { "[F]",    NULL }, // no layout function means floating behavior 
    { "[M]",    monocle },
    { "[D]",    deck },
    { NULL,     NULL },
};

// -------------------------------- Keybindings --------------------------------

#define MODKEY      Mod4Mask
#define ALTKEY      Mod1Mask

#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,  view,       {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,  toggleview, {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,  tag,        {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,  toggletag,  {.ui = 1 << TAG} },

// Helper for spawning shell commands in the pre dwm-5.0 fashion 
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

// Commands
static char dmenumon[2]         = "0";
static const char *termcmd[]    = { "alacritty", NULL };
static const char *dmenucmd[]   = {
    "dmenu_run", "-m", dmenumon,
    "-fn", dmenufont,
    NULL
};

#include "mpdcontrol.c"
static Key keys[] = {

    // ------------------ Windows ------------------

    // Switch between windows
    { MODKEY,               44 /* j */,     focusstack,     {.i = +1 } },
    { MODKEY,               45 /* k */,     focusstack,     {.i = -1 } },

    // Change window sizes
    { MODKEY,               31 /* i */,     incnmaster,     {.i = +1 } },
    { MODKEY|ShiftMask,     31 /* i */,     incnmaster,     {.i = -1 } },
    { MODKEY|ShiftMask,     43 /* h */,		setmfact,       {.f = -0.05} },
    { MODKEY|ShiftMask,     46 /* l */,		setmfact,       {.f = +0.05} },

    // Toggle floating
    { MODKEY|ControlMask,   41 /* f */,		togglefloating, {0} },

    // Toggle always on top
	{ MODKEY|ControlMask,   28 /* t */,     togglealwaysontop, {0} },

    // Toggle bar
    { MODKEY|ControlMask,   56 /* b */,		togglebar,      {0} },
    { MODKEY|ALTKEY,        56 /* b */,		toggleextrabar, {0} },

    // Move windows in current stack
    { MODKEY|ShiftMask,     44 /* j */,		rotatestack,    {.i = +1 } },
    { MODKEY|ShiftMask,     45 /* k */,		rotatestack,    {.i = -1 } },

    // Cycle layouts
    { MODKEY,               23 /* tab */,   cyclelayout,    {.i = +1 } },
    { MODKEY|ShiftMask,     23 /* tab */,   cyclelayout,    {.i = -1 } },

    // Focus next - prev monitor
    { MODKEY,               60 /* period */,focusmon,       {.i = +1 } },
    { MODKEY,               59 /* comma */, focusmon,       {.i = -1 } },

    // Send window to next - prev monitor
    { MODKEY|ShiftMask,     60 /* period */,tagmon,         {.i = +1 } },
    { MODKEY|ShiftMask,     59 /* comma */, tagmon,         {.i = -1 } },

    // Change opacity for clients
	{ MODKEY|ShiftMask,		86 /* Add */,   changeopacity,	{.f = +0.1}},
	{ MODKEY|ShiftMask,		82 /*substract*/, changeopacity,{.f = -0.1}},

    // Kill window
    { MODKEY,               25 /* w */,		killclient,     {0} },

    // Restart dwm
    { MODKEY|ControlMask,   27 /* r */,		quit,           {1} },

    // Quit dwm
    { MODKEY|ControlMask,   24 /* q */,		quit,           {0} },


    // ------------------- Gaps --------------------
    
    // Increase - decrease all gaps
	{ MODKEY,               42 /* g */,     incrgaps,       {.i = +1 } },
	{ MODKEY|ShiftMask,     42 /* g */,     incrgaps,       {.i = -1 } },

    // Restore - toggle gaps
	{ MODKEY|ALTKEY,        42 /* g */,     defaultgaps,    {0} },
	{ MODKEY|ControlMask,   42 /* g */,     togglegaps,     {0} },
	{ MODKEY|ControlMask,   32 /* o */,     toggleoutergaps,{0} },
	{ MODKEY|ControlMask,   29 /* y */,     toggleinnergaps,{0} },

    // Increase - decrease inner gaps
	{ ALTKEY|ShiftMask,     45 /* k */,     incrigaps,      {.i = +1 } },
	{ ALTKEY|ShiftMask,     44 /* j */,     incrigaps,      {.i = -1 } },

    // Increase - decrease inner vertical gaps
	{ MODKEY,               29 /* y */,     incrivgaps,     {.i = +1 } },
	{ MODKEY|ShiftMask,     29 /* y */,     incrivgaps,     {.i = -1 } },

    // Increase - decrease inner horizontal gaps
	{ MODKEY,               32 /* o */,     incrihgaps,     {.i = +1 } },
	{ MODKEY|ShiftMask,     32 /* o */,     incrihgaps,     {.i = -1 } },

    // Increase - decrease outer gaps
	{ ALTKEY|ShiftMask,     43 /* h */,     incrogaps,      {.i = +1 } },
	{ ALTKEY|ShiftMask,     46 /* l */,     incrogaps,      {.i = -1 } },

    // Increase - decrease outer vertical gaps
	{ ALTKEY,               29 /* y */,     incrovgaps,     {.i = +1 } },
	{ ALTKEY|ShiftMask,     29 /* y */,     incrovgaps,     {.i = -1 } },

    // Increase - decrease outer horizontal gaps
	{ ALTKEY,               32 /* o */,     incrohgaps,     {.i = +1 } },
	{ ALTKEY|ShiftMask,     32 /* o */,     incrohgaps,     {.i = -1 } },


    // ---------------- Workspaces -----------------

    TAGKEYS(10 /* 1 */, 0)
    TAGKEYS(11 /* 2 */, 1)
    TAGKEYS(12 /* 3 */, 2)
    TAGKEYS(13 /* 4 */, 3)
    TAGKEYS(14 /* 5 */, 4)
    TAGKEYS(15 /* 6 */, 5)
    TAGKEYS(16 /* 7 */, 6)
    TAGKEYS(17 /* 8 */, 7)
    TAGKEYS(18 /* 9 */, 8)
    TAGKEYS(19 /* 0 */, 9)

    // Switch between the last label and the current
    { MODKEY,               61 /* slash */,     view,       {.ui = 0 } },

    // ------------------- Apps --------------------

    // dmenu
    { MODKEY|ALTKEY,        36 /* enter */,     spawn,      {.v = dmenucmd } },
    { MODKEY,               135 /* menu */,     spawn,      {.v = dmenucmd } },

    // rofi
    { MODKEY,               58 /* m */,         spawn,      SHCMD("rofi -show drun") },

    // Window nav (rofi)
    { MODKEY|ShiftMask,     58 /* m */,         spawn,      SHCMD("rofi -show") },

    // Terminal emulators
    { MODKEY,               36 /* enter */,     spawn,      {.v = termcmd } },
    { ALTKEY,               36 /* enter */,     spawn,      SHCMD("st") },
    { MODKEY|ShiftMask,     36 /* enter */,     spawn,      SHCMD("kitty") },

    // File explorers
    { MODKEY,               26 /* e */,         spawn,      SHCMD("pcmanfm") },
    { MODKEY|ShiftMask,     26 /* e */,			spawn,      SHCMD("thunar") },
    { MODKEY|ALTKEY,        26 /* e */,			spawn,      SHCMD("kitty -e ranger") },

    // Browsers
    { MODKEY,               56 /* b */,			spawn,      SHCMD("microsoft-edge-dev") },
    { MODKEY,               41 /* f */,			spawn,      SHCMD("firefox") },
    { MODKEY|ShiftMask,     56 /* b */,			spawn,      SHCMD("brave") },

    // Redshift
    { MODKEY,               27 /* r */,			spawn,      SHCMD("redshift -O 2400") },
    { MODKEY|ShiftMask,     27 /* r */,			spawn,      SHCMD("redshift -x") },

    // Screenshot
    { MODKEY,               39 /* s */,			spawn,      SHCMD("scrot -z '%Y-%m-%d-%H.%M.%S_$wx$h_scrot.png' -e 'mv $f ~/Pictures/Screenshots/'") },
    { MODKEY|ShiftMask,     39 /* s */,			spawn,      SHCMD("scre") },

    // Music Players
    { MODKEY,               33 /* p */,         spawn,      SHCMD("spotify") },

    // Messengers
    { MODKEY,               28 /* t */,			spawn,      SHCMD("telegram-desktop") },

    // Miscellaneous
    { MODKEY,               40 /* d */,			spawn,      SHCMD("droidcam") },
    { MODKEY,               52 /* z */,			spawn,      SHCMD("zoom") },


    // ----------------- Hardware ------------------

    // Volume
    {MODKEY,                20 /* minus */,     spawn,      SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -2%")},
    {MODKEY,                21 /* plus */,      spawn,      SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +2%")},
    {MODKEY,                22 /* backspc */,   spawn,      SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle")},


    // --------------------- MPD -------------------

    // Clients
    { MODKEY,               57 /* n */,			spawn,      SHCMD("alacritty -e ncmpcpp") },
    { MODKEY|ShiftMask,     57 /* n */,			spawn,      SHCMD("cantata") },

    // Previus or next song
    { MODKEY|ALTKEY,		44 /* j */,			mpdchange,	{.i = -1} },
	{ MODKEY|ALTKEY,        45 /* k */,     	mpdchange,	{.i = +1} },

    // Play or pause
    { MODKEY|ALTKEY,		65 /* space */,		mpdcontrol,	{0} },

    // Volume
    {MODKEY|ALTKEY,			20 /* minus */,		mpd_volume,	{.i = -diff_volume } },
    {MODKEY|ALTKEY,			21 /* plus */,		mpd_volume,	{.i = +diff_volume } },


    // ----------------- Keyboard layout ------------------

    // Change the xkbmap
    {MODKEY,				65 /* space */,		spawn,		SHCMD("xkbmap --rotate") },
};

// click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin 
static Button buttons[] = {
    // click            event mask  button       function         argument 
    { ClkLtSymbol,      0,          Button1,    setlayout,      {0} },
    { ClkLtSymbol,      0,          Button4,    cyclelayout,    {.i = +1 } },
    { ClkLtSymbol,      0,          Button5,    cyclelayout,    {.i = +1 } },
    { ClkLtSymbol,      0,          Button3,    setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,      0,          Button4,    zoom,           {0} },
    { ClkWinTitle,      0,          Button5,    zoom,           {0} },
    { ClkWinTitle,      MODKEY,     Button1,    spawn,          {.v = termcmd } },
    { ClkClientWin,     MODKEY,     Button1,    movemouse,      {0} },
    { ClkClientWin,     MODKEY,     Button2,    togglefloating, {0} },
    { ClkClientWin,     MODKEY,     Button3,    resizemouse,    {0} },
    { ClkTagBar,        0,          Button1,    view,           {0} },
    { ClkTagBar,        0,          Button3,    toggleview,     {0} },
    { ClkTagBar,        MODKEY,     Button1,    tag,            {0} },
    { ClkTagBar,        MODKEY,     Button3,    toggletag,      {0} },
};
