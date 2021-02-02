// ------------------------------ Rules -----------------------------------
static const char PWA_WhatsApp[] = "crx__hnpfjngllnobngcgfapefoaidbinmjnm";

static const Rule rules[] = {
    /* xprop(1):
     * WM_CLASS(STRING) = instance, class
     * WM_NAME(STRING) = title
     */

	/* class                instance        title       tags mask   isfloating	 opacity	        monitor */
	{ "Gimp-2.10",          NULL,           NULL,       1<<5,       0,           1.0,		        -1 },
	{ "firefox",            NULL,           NULL,       1,          0,           0.9,		        -1 },
	{ "Microsoft-edge-dev", NULL,           NULL,       1,          0,           0.9,		        -1 },
	{ "Brave-browser",      NULL,           NULL,       1,          0,           0.9,	            -1 },
	{ "Microsoft-edge-dev", PWA_WhatsApp,   NULL,       1<<8,       0,           0.9,               -1 },
	{ "Alacritty",          NULL,           NULL,       1<<2,       0,           1.0,	            -1 },
	{ "Xephyr",             NULL,           NULL,       1<<9,       1,           1.0,		        -1 },
	{ "cantata",            NULL,           NULL,       1<<7,       0,           defaultopacity,	-1 },
	{ "kitty",              NULL,           NULL,       1<<2,       0,           1.0,		        -1 },
	{ "Spotify",            NULL,           NULL,       1<<7,       0,           defaultopacity,    -1 },
	{ "zoom",               NULL,           NULL,       1<<6,       0,           defaultopacity,    -1 },
	{ "zoom",               NULL,           "Chat",     1<<6,       1,           defaultopacity,    -1 },
	{ "Zathura",            NULL,           NULL,       1<<4,       0,           defaultopacity,    -1 },
	{ "TelegramDesktop",    NULL,           NULL,       1<<8,       0,           defaultopacity,    -1 },
	{ "Droidcam",           NULL,           NULL,       1<<9,       0,           defaultopacity,    -1 },
};


