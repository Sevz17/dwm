/* See LICENSE file for copyright and license details. */

// ------------------------------ Rules -----------------------------------
static const char PWA_WhatsApp[] = "crx__hnpfjngllnobngcgfapefoaidbinmjnm";

static const Rule rules[] = {
    /* xprop(1):
     * WM_CLASS(STRING) = instance, class
     * WM_NAME(STRING) = title
     */

	/* class                instance        title       tags mask   isfloating	opacity		isterminal	noswallow	monitor */

	// No workspace
	{ "MEGAsync",			NULL,           NULL,       0,          1,          0.9,		0,			0,      	-1 },
	{ NULL,					NULL,		"Event Tester", 0,			0,		defaultopacity,	0,			1,			-1 }, /* xev */
	{ "feh",				NULL,           NULL,       0,			0,           1.0,		0,			0,      	-1 },


	// Workspace 
	{ "firefox",            NULL,           NULL,       1,          0,          0.9,		0,			0,			-1 },
	{ "Microsoft-edge-dev", NULL,           NULL,       1,          0,          0.9,		0,			0,			-1 },
	{ "Brave-browser",      NULL,           NULL,       1,          0,          0.9,		0,			0,			-1 },


	// Workspace ﬏
	{ "Java",				NULL,           "Eclipse",	1<<1,       1,          1.0,	    0,			0,			-1 },
	{ "Eclipse",			NULL,           NULL,       1<<1,       0,		defaultopacity,	0,			0,			-1 },


	// Workspace 
	{ "Alacritty",          NULL,           NULL,       1<<2,       0,           1.0,		1,			0,      	-1 },
	{ "kitty",              NULL,           NULL,       1<<2,       0,           1.0,		1,			0,      	-1 },
	{ "st",					NULL,           NULL,       1<<2,       0,           1.0,		1,			0,      	-1 },


	// Workspace 
	{ "VirtualBox Manager",	NULL,           NULL,       1<<3,       0,		defaultopacity,	0,			0,			-1 },
	{ "Pavucontrol",		NULL,           NULL,       1<<3,       0,		defaultopacity,	0,			0,			-1 },
	{ "Arandr",				NULL,           NULL,       1<<3,       0,		defaultopacity,	0,			0,			-1 },


	// Workspace 
	{ "Zathura",            NULL,           NULL,       1<<4,       0,      defaultopacity,	0,			0, 			-1 },
	{ NULL,					"libreoffice",  NULL,       1<<4,       0,          1.0,		0,			0,			-1 },
	{ NULL,					NULL,		"LibreOffice",	1<<4,		0,      defaultopacity,	0,			0,			-1 },
	{ "Thunar",				NULL,           NULL,       1<<4,       0,      defaultopacity,	0,			0, 			-1 },
	{ "Pcmanfm",			NULL,           NULL,       1<<4,       0,      defaultopacity,	0,			0, 			-1 },


	// Workspace 
	{ "Gimp-2.10",          NULL,           NULL,       1<<5,       0,           1.0,		0,			0,			-1 },
	{ "Gimp",				NULL,           NULL,       1<<5,       0,           1.0,		0,			0,			-1 },
	{ "Geeqie",				NULL,           NULL,       1<<5,       0,           1.0,		0,			0,			-1 },


	// Workspace 
	{ "zoom",               NULL,           NULL,       1<<6,       0,		defaultopacity,	0,			0,  		-1 },
	{ "zoom",               NULL,           "Chat",     1<<6,       1,		defaultopacity,	0,			0,  		-1 },
	{ "vlc",				NULL,           NULL,       1<<6,       0,		defaultopacity,	0,			0, 			-1 },


	// Workspace 
	{ "Spotify",            NULL,           NULL,       1<<7,       0,		defaultopacity, 0,			0,			-1 },
	{ "vlc",				NULL,           NULL,       1<<7,       0,		defaultopacity, 0,			0,			-1 },
	{ "cantata",            NULL,           NULL,       1<<7,       0,		defaultopacity,	0,			0,			-1 },


	// Workspace 
	{ "Microsoft-edge-dev", PWA_WhatsApp,   NULL,       1<<8,       0,		defaultopacity,	0,			0,			-1 },
	{ "TelegramDesktop",    NULL,           NULL,       1<<8,       0,		defaultopacity,	0,			0,			-1 },
	{ "discord",			NULL,           NULL,       1<<8,       0,		defaultopacity,	0,			0,			-1 },


	// Workspace 
	{ "Droidcam",           NULL,           NULL,       1<<9,       0,		defaultopacity,	0,			0,			-1 },
	{ "Xephyr",             NULL,           NULL,       1<<9,       1,           1.0,		0,			0,			-1 },
	{ "pyrogenesis",		NULL,           NULL,       1<<9,       1,           1.0,		0,			0,			-1 }, /* 0ad */
	{ "VirtualBox Machine",	NULL,           NULL,       1<<9,       1,           1.0,		0,			0,			-1 },
};
