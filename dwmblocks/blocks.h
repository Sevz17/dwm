static const Block blocks[] = {
//   Icon    Command                          Update Interval     Update Signal
	{"Mem:", "free --mega | awk '/^Mem/ { print $3\"M/\"$2\"M\" }'",	1,		0},
    { "  ", "checkupdates | wc -l",                 60,               0 },
    { "",    "volume",                               1,                0 },
    { "",    "date '+ %d/%m/%Y  %H:%M'",       1,              0 },
};
//free --mega -s 1 -c 10

// Sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "  ";
static unsigned int delimLen = 5;
