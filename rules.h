// ------------------------------ Rules -----------------------------------
static const char PWA_WhatsApp[] = "crx__hnpfjngllnobngcgfapefoaidbinmjnm";

static const Rule rules[] = {
    /* xprop(1):
     * WM_CLASS(STRING) = instance, class
     * WM_NAME(STRING) = title
     */

	/* class                instance        title       tags mask   isfloating	 opacity	        monitor */

	// Workspace 
	{ "firefox",            NULL,           NULL,       1,          0,           0.9,		        -1 },
	{ "Microsoft-edge-dev", NULL,           NULL,       1,          0,           0.9,		        -1 },
	{ "Brave-browser",      NULL,           NULL,       1,          0,           0.9,	            -1 },


	// Workspace ﬏
	{ "Java",				NULL,           "Eclipse",	1<<1,       1,           1.0,	            -1 },
	{ "Eclipse",			NULL,           NULL,       1<<1,       1,           1.0,	            -1 },


	// Workspace 
	{ "Alacritty",          NULL,           NULL,       1<<2,       0,           1.0,	            -1 },
	{ "kitty",              NULL,           NULL,       1<<2,       0,           1.0,		        -1 },


	// Workspace 


	// Workspace 
	{ "Zathura",            NULL,           NULL,       1<<4,       0,           defaultopacity,    -1 },
	{ NULL,					"libreoffice",  NULL,       1<<4,       0,           1.0,		        -1 },


	// Workspace 
	{ "Gimp-2.10",          NULL,           NULL,       1<<5,       0,           1.0,		        -1 },


	// Workspace 
	{ "zoom",               NULL,           NULL,       1<<6,       0,           defaultopacity,    -1 },
	{ "zoom",               NULL,           "Chat",     1<<6,       1,           defaultopacity,    -1 },


	// Workspace 
	{ "Spotify",            NULL,           NULL,       1<<7,       0,           defaultopacity,    -1 },
	{ NULL,					NULL,           "Spotify",  1<<7,       0,           defaultopacity,    -1 },
	{ "cantata",            NULL,           NULL,       1<<7,       0,           defaultopacity,	-1 },


	// Workspace 
	{ "Microsoft-edge-dev", PWA_WhatsApp,   NULL,       1<<8,       0,           0.9,               -1 },
	{ "TelegramDesktop",    NULL,           NULL,       1<<8,       0,           defaultopacity,    -1 },


	// Workspace 
	{ "Droidcam",           NULL,           NULL,       1<<9,       0,           defaultopacity,    -1 },
	{ "Xephyr",             NULL,           NULL,       1<<9,       1,           1.0,		        -1 },
};
