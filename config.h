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
// 0 means bottom bar 
static const int topbar                     = 1;
// 0 means no extra bar
static const int extrabar                   = 1;
// 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height
static const int user_bh                    = 0;
// means the volume that MPD will increase or reduce, if 0 does nothing
static const unsigned int diff_volume       = 2;
// opacity for clients
static const double defaultopacity          = 0.9;
// ---------------------------------- Fonts ------------------------------------

static const char *fonts[]    = { "UbuntuMono Nerd Font:size=14:antialias=true:autohint:true" };
static const char dmenufont[] = { "UbuntuMono Nerd Font:size=12:antialias=true:autohint=true" };

// ---------------------------------- Colors -----------------------------------

static const char col_black[]       = "#000000";
static const char col_gray[]        = "#4c566a";
static const char col_white[]       = "#ffffff";
static const char col_purple[]      = "#6000ff";
static const char col_red[]         = "#ff0000";

static const char *colors[][3]          = {
//                          fg          bg              border
// Statusbar right
	[SchemeStatus]      = { col_white,  col_black,      col_black },
// Tagbar left selected
    [SchemeTagsSel]     = { col_white,  col_purple,     col_purple },
// Tagbar left unselected
    [SchemeTagsNorm]    = { col_white,   col_black,     col_black },
// infobar middle selected
    [SchemeInfoSel]     = { col_white,  col_purple,     col_purple },
// infobar middle unselected
    [SchemeInfoNorm]    = { col_white,  col_black,      col_black },
// border urgent
	[SchemeUrg]         = { col_white,  col_black,      col_red },
};

// -------------------------------- Workspaces ---------------------------------

static const char *tags[] = { " ", "﬏ ", " ", " ", " ", " ", " ", " ", " ", " " };

// ---------------------------------- Layouts ----------------------------------

// factor of master area size [0.05..0.95]
static const float mfact        = 0.50;
// number of clients in master area
static const int nmaster        = 1;
// 1 means respect size hints in tiled resizals
static const int resizehints    = 1;

static const Layout layouts[] = {
    // symbol   arrange function
    { "[T]",    tile }, // first entry is default
    { "[F]",    NULL }, // no layout function means floating behavior 
    { "[M]",    monocle },
    { "[D]",    deck },
    { NULL,     NULL },
};

// -------------------------------- Keybindings --------------------------------

#define MODKEY      Mod4Mask
#define ALTKEY      Mod1Mask
#define LowerVolume XF86XK_AudioLowerVolume
#define RaiseVolume XF86XK_AudioRaiseVolume
#define AudioMute   XF86XK_AudioMute
#define BrightUp    XF86XK_MonBrightnessUp
#define BrightDown  XF86XK_MonBrightnessDown

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

#include <X11/XF86keysym.h>
#include "mpdcontrol.c"
static Key keys[] = {

    // ------------------ Windows ------------------

    // Switch between windows
    { MODKEY,               XK_j,			focusstack,     {.i = +1 } },
    { MODKEY,               XK_k,			focusstack,     {.i = -1 } },

    // Change window sizes
    { MODKEY,               XK_i,			incnmaster,     {.i = +1 } },
    { MODKEY|ShiftMask,     XK_i,			incnmaster,     {.i = -1 } },
    { MODKEY|ShiftMask,     XK_h,			setmfact,       {.f = -0.05} },
    { MODKEY|ShiftMask,     XK_l,			setmfact,       {.f = +0.05} },

    // Toggle floating
    { MODKEY|ControlMask,   XK_f,			togglefloating, {0} },

    // Toggle always on top
	{ MODKEY|ControlMask,   XK_t,           togglealwaysontop, {0} },

    // Toggle bar
    { MODKEY|ControlMask,   XK_b,			togglebar,      {0} },
    { MODKEY|ALTKEY,        XK_b,           toggleextrabar, {0} },

    // Move windows in current stack
    { MODKEY|ShiftMask,     XK_j,			rotatestack,    {.i = +1 } },
    { MODKEY|ShiftMask,     XK_k,			rotatestack,    {.i = -1 } },

    // Cycle layouts
    { MODKEY,               XK_Tab,         cyclelayout,    {.i = +1 } },
    { MODKEY|ShiftMask,     XK_Tab,         cyclelayout,    {.i = -1 } },

    // Focus next - prev monitor
    { MODKEY,               XK_period,      focusmon,       {.i = +1 } },
    { MODKEY,               XK_comma,       focusmon,       {.i = -1 } },

    // Send window to next - prev monitor
    { MODKEY|ShiftMask,     XK_period,      tagmon,         {.i = +1 } },
    { MODKEY|ShiftMask,     XK_comma,       tagmon,         {.i = -1 } },

    // Change opacity for clients
	{ MODKEY|ShiftMask,		XK_KP_Add,      changeopacity,	{.f = +0.1}},
	{ MODKEY|ShiftMask,		XK_KP_Subtract, changeopacity,  {.f = -0.1}},

    // Kill window
    { MODKEY,               XK_w,			killclient,     {0} },

    // Restart dwm
    { MODKEY|ControlMask,   XK_r,			quit,           {1} },

    // Quit dwm
    { MODKEY|ControlMask,   XK_q,			quit,           {0} },


    // ------------------- Gaps --------------------
    
    // Increase - decrease all gaps
	{ MODKEY,               XK_g,           incrgaps,       {.i = +1 } },
	{ MODKEY|ShiftMask,     XK_g,           incrgaps,       {.i = -1 } },

    // Restore - toggle gaps
	{ MODKEY|ALTKEY,        XK_g,           defaultgaps,    {0} },
	{ MODKEY|ControlMask,   XK_g,           togglegaps,     {0} },
	{ MODKEY|ControlMask,   XK_o,           toggleoutergaps,{0} },
	{ MODKEY|ControlMask,   XK_y,           toggleinnergaps,{0} },

    // Increase - decrease inner gaps
	{ ALTKEY|ShiftMask,     XK_k,           incrigaps,      {.i = +1 } },
	{ ALTKEY|ShiftMask,     XK_j,           incrigaps,      {.i = -1 } },

    // Increase - decrease inner vertical gaps
	{ MODKEY,               XK_y,           incrivgaps,     {.i = +1 } },
	{ MODKEY|ShiftMask,     XK_y,           incrivgaps,     {.i = -1 } },

    // Increase - decrease inner horizontal gaps
	{ MODKEY,               XK_o,           incrihgaps,     {.i = +1 } },
	{ MODKEY|ShiftMask,     XK_o,           incrihgaps,     {.i = -1 } },

    // Increase - decrease outer gaps
	{ ALTKEY|ShiftMask,     XK_h,           incrogaps,      {.i = +1 } },
	{ ALTKEY|ShiftMask,     XK_l,           incrogaps,      {.i = -1 } },

    // Increase - decrease outer vertical gaps
	{ ALTKEY,               XK_y,           incrovgaps,     {.i = +1 } },
	{ ALTKEY|ShiftMask,     XK_y,           incrovgaps,     {.i = -1 } },

    // Increase - decrease outer horizontal gaps
	{ ALTKEY,               XK_o,           incrohgaps,     {.i = +1 } },
	{ ALTKEY|ShiftMask,     XK_o,           incrohgaps,     {.i = -1 } },


    // ---------------- Workspaces -----------------

    TAGKEYS(XK_1, 0)
    TAGKEYS(XK_2, 1)
    TAGKEYS(XK_3, 2)
    TAGKEYS(XK_4, 3)
    TAGKEYS(XK_5, 4)
    TAGKEYS(XK_6, 5)
    TAGKEYS(XK_7, 6)
    TAGKEYS(XK_8, 7)
    TAGKEYS(XK_9, 8)
    TAGKEYS(XK_0, 9)


    // ------------------- Apps --------------------

    // dmenu
    { MODKEY|ALTKEY,        XK_Return,      spawn,      {.v = dmenucmd } },
    { MODKEY,               XK_Menu,        spawn,      {.v = dmenucmd } },

    // rofi
    { MODKEY,               XK_m,			spawn,      SHCMD("rofi -show drun") },

    // Window nav (rofi)
    { MODKEY|ShiftMask,     XK_m,			spawn,      SHCMD("rofi -show") },

    // Terminal emulators
    { MODKEY,               XK_Return,      spawn,      SHCMD("alacritty") },
    { MODKEY|ShiftMask,     XK_Return,      spawn,      SHCMD("kitty") },

    // File explorers
    { MODKEY,               XK_e,			spawn,      SHCMD("pcmanfm") },
    { MODKEY|ShiftMask,     XK_e,			spawn,      SHCMD("thunar") },
    { MODKEY|ALTKEY,        XK_e,			spawn,      SHCMD("kitty -e ranger") },

    // Browsers
    { MODKEY,               XK_b,			spawn,      SHCMD("microsoft-edge-dev") },
    { MODKEY,               XK_f,			spawn,      SHCMD("firefox") },
    { MODKEY|ShiftMask,     XK_b,			spawn,      SHCMD("brave") },

    // Redshift
    { MODKEY,               XK_r,			spawn,      SHCMD("redshift -O 2400") },
    { MODKEY|ShiftMask,     XK_r,			spawn,      SHCMD("redshift -x") },

    // Screenshot
    { MODKEY,               XK_s,			spawn,      SHCMD("scrot -z '%Y-%m-%d-%H.%M.%S_$wx$h_scrot.png' -e 'mv $f ~/Pictures/Screenshots/'") },
    { MODKEY|ShiftMask,     XK_s,			spawn,      SHCMD("scre") },

    // Music Players
    { MODKEY,               XK_p,			spawn,      SHCMD("spotify") },

    // Messengers
    { MODKEY,               XK_t,			spawn,      SHCMD("telegram-desktop") },

    // Miscellaneous
    { MODKEY,               XK_d,			spawn,      SHCMD("droidcam") },
    { MODKEY,               XK_z,			spawn,      SHCMD("zoom") },


    // ----------------- Hardware ------------------

    // Volume
    {0,                     RaiseVolume,    spawn,      SHCMD("pamixer --increase 2")},
    {0,                     LowerVolume,    spawn,      SHCMD("pamixer --decrease 2")},
    {MODKEY,                XK_minus,       spawn,      SHCMD("pamixer --decrease 2")},
    {MODKEY,                XK_plus,        spawn,      SHCMD("pamixer --increase 2")},
    {MODKEY,                XK_equal,       spawn,      SHCMD("pamixer --increase 2")},
    {MODKEY|ShiftMask,      XK_equal,       spawn,      SHCMD("pamixer --toggle-mute")},
    {MODKEY|ShiftMask,      XK_minus,       spawn,      SHCMD("pamixer --toggle-mute")},
    {0,                     AudioMute,      spawn,      SHCMD("pamixer --toggle-mute")},

    // Brightness
    {0,						BrightUp,		spawn,		SHCMD("brightnessctl set +10%")},
    {0,						BrightDown,		spawn,		SHCMD("brightnessctl set 10%-")},


    // --------------------- MPD -------------------

    // Clients
    { MODKEY,               XK_n,			spawn,      SHCMD("alacritty -e ncmpcpp") },
    { MODKEY|ShiftMask,     XK_n,			spawn,      SHCMD("cantata") },

    // Previus or next song
    { MODKEY|ALTKEY,		XK_j,			mpdchange,	{.i = -1} },
	{ MODKEY|ALTKEY,        XK_k,     		mpdchange,	{.i = +1} },

    // Play or pause
    { MODKEY|ALTKEY,		XK_space,		mpdcontrol,	{0} },

    // Volume
    {ALTKEY,				RaiseVolume,	mpd_volume,	{.i = +diff_volume } },
    {ALTKEY,				LowerVolume,	mpd_volume,	{.i = -diff_volume } },
    {MODKEY|ALTKEY,			XK_minus,		mpd_volume,	{.i = -diff_volume } },
    {MODKEY|ALTKEY,			XK_plus,		mpd_volume,	{.i = +diff_volume } },
    {MODKEY|ALTKEY,			XK_equal,		mpd_volume,	{.i = +diff_volume } },


    // ----------------- Keyboard layout ------------------

    // Change the xkbmap
    {MODKEY,				XK_space,		spawn,		SHCMD("xkbmap --rotate") },
};

// click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin 
static Button buttons[] = {
    // click            event mask    button       function         argument 
    { ClkLtSymbol,      0,            Button1,     setlayout,       {0} },
    { ClkLtSymbol,      0,            Button3,     setlayout,       {.v = &layouts[2]} },
    { ClkWinTitle,      0,            Button2,     zoom,            {0} },
    { ClkStatusText,    0,            Button2,     spawn,           {.v = termcmd } },
    { ClkClientWin,     MODKEY,       Button1,     movemouse,       {0} },
    { ClkClientWin,     MODKEY,       Button2,     togglefloating,  {0} },
    { ClkClientWin,     MODKEY,       Button3,     resizemouse,     {0} },
    { ClkTagBar,        0,            Button1,     view,            {0} },
    { ClkTagBar,        0,            Button3,     toggleview,      {0} },
    { ClkTagBar,        MODKEY,       Button1,     tag,             {0} },
    { ClkTagBar,        MODKEY,       Button3,     toggletag,       {0} },
};
