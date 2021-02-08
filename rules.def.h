/* See LICENSE file for copyright and license details. */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating	 opacity	monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           1.0,		-1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           1.0,		-1 },
};
