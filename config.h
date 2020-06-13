/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx          = 0;  /* border pixel of windows */
static const unsigned int snap              = 8;  /* snap pixel */
static const int          showbar           = 1;  /* 0 means no bar */
static const int          topbar            = 0;  /* 0 means bottom bar */
static const int          focusonwheel      = 0;
static const int          viewontag         = 1;  /* switch view on tag add */
static const int          swallowfloating   = 0;  /* 1 means swallow floating windows by default */

static const unsigned int gappih           = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv           = 10;  /* vert inner gap between windows */
static const unsigned int gappoh           = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov           = 10;  /* vert outer gap between windows and screen edge */
static const int          smartgaps        = 1;   /* 1 means no outer gap when there is only one window */

static const char        *fonts[]           = {
  "Noto Sans Mono:style=Regular:size=11",
  "Font Awesome 5 Brands:size=12",
  "Font Awesome 5 Free:size=12",
};

static const char         col_fg[]          = "#fbf1c7";   /* gruvbox fg0 */
static const char         col_bg[]          = "#282828";   /* gruvbox bg0 */
static const char         col_border[]      = "#504945";   /* gruvbox bg2 */
static const char         col_border_foc[]  = "#458588";   /* gruvbox blue */

static const char        *colors[][3] = {
	/*                   fg      bg              border   */
	[SchemeNorm]     = { col_fg, col_bg,         col_border },
	[SchemeSel]      = { col_fg, col_border_foc, col_border_foc  },

  /*                   text    background  n/a */
	[SchemeStatus]   = { col_fg, col_bg,  "#000000"  },         /* Statusbar right */
	[SchemeTagsSel]  = { col_fg, col_border_foc,  "#000000"  }, /* Tagbar left selected */
  [SchemeTagsNorm] = { col_fg, col_bg,  "#000000"  },         /* Tagbar left unselected */
  [SchemeInfoSel]  = { col_fg, col_bg,  "#000000"  },         /* infobar middle selected */
  [SchemeInfoNorm] = { col_fg, col_bg,  "#000000"  },         /* infobar middle unselected */
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "" };

#define TAG(NUM) 1 << (NUM - 1)
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class               instance    title      tags mask  iscentered  isfloating  isterminal  noswallow  monitor */
  { NULL,                NULL, "Event Tester",  0,         0,          1,          0,          1,         -1 },
  { "JetBrains Toolbox", NULL,       NULL,      0,         0,          1,          0,          0,         -1 },
  { "feh",               NULL,       NULL,      0,         1,          1,          0,          0,         -1 },
  { "st",                NULL,       NULL,      0,         0,          0,          1,          1,         -1 },
  { "Vivaldi-stable",    NULL,       NULL,      TAG(1),    0,          0,          0,          1,         -1 },
  { "discord",           NULL,       NULL,      TAG(2),    0,          0,          0,          1,         -1 },
  { "jetbrains-pycharm", NULL,       NULL,      TAG(3),    0,          0,          0,          1,         -1 },
  { "Steam",             NULL,       NULL,      TAG(8),    0,          0,          0,          1,         -1 },
  { "Steam",             NULL, "Friends List",  TAG(8),    0,          1,          0,          1,         -1 },
  { "Steam",             NULL, "Steam - News",  TAG(8),    0,          1,          0,          1,         -1 },
  { NULL,                NULL, "Zoom - Free Account",  0,  0,          1,          0,          1,         -1 },
  { "Lutris",            NULL,       NULL,      TAG(8),    0,          0,          0,          1,         -1 },
  { "Spotify",           NULL,       NULL,      TAG(9),    0,          0,          0,          1,         -1 },
};

/* layouts */
static const float mfact       = 0.50; /* factor of master area size [0.05..0.95] */
static const int   nmaster     = 1;    /* number of clients in master area */
static const int   resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int   decorhints  = 1;    /* 1 means respect decoration hints */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[\\]",     dwindle },
	{ "[M]",      monocle },

  { "HHH",      gaplessgrid },
  { "TTT",      bstack },

	{ "[]=",      tile },
	{ "><>",      NULL },

  { "|M|",      centeredmaster},
  { ">M<",      centeredfloatingmaster},

  { NULL,       NULL },   /* used for cyclelayouts */
};

/* key definitions */
#define MOD Mod4Mask
#define ALT Mod1Mask
#define TAGKEYS(KEY, TAG) \
  { MOD,                          KEY,      view,           {.ui = 1 << (TAG - 1)} }, \
  { MOD|ControlMask,              KEY,      toggleview,     {.ui = 1 << (TAG - 1)} }, \
  { MOD|ShiftMask,                KEY,      tag,            {.ui = 1 << (TAG - 1)} }, \
  { MOD|ALT,                      KEY,      toggletag,      {.ui = 1 << (TAG - 1)} },
//#define SH(CMD) { .v = (const char*[]){ "/bin/sh", "-c", CMD, NULL } }
#include "movestack.c"

/* key bindings */
static Key keys[] = {
	/* modifier            key              function        argument */
	TAGKEYS(               XK_1,                            1)
	TAGKEYS(               XK_2,                            2)
	TAGKEYS(               XK_3,                            3)
	TAGKEYS(               XK_4,                            4)
	TAGKEYS(               XK_5,                            5)
	TAGKEYS(               XK_6,                            6)
	TAGKEYS(               XK_7,                            7)
	TAGKEYS(               XK_8,                            8)
	TAGKEYS(               XK_9,                            9)
  { MOD,                 XK_0,            view,           {.ui = ~0 } },
	{ MOD|ShiftMask,       XK_0,            tag,            {.ui = ~0 } },

	{ ALT,                 XK_Tab,          view,           {0} },
	{ MOD,                 XK_Tab,          view,           {0} },
	{ MOD,                 XK_q,            killclient,     {0} },
  { MOD,                 XK_b,            togglebar,      {0} },

  { MOD,                 XK_j,            focusstack,     {.i = +1 } },
	{ MOD,                 XK_k,            focusstack,     {.i = -1 } },
  { MOD|ShiftMask,       XK_j,            movestack,      {.i = +1 } },
  { MOD|ShiftMask,       XK_k,            movestack,      {.i = -1 } },
  { MOD,                 XK_h,            setmfact,       {.f = -0.05} },
  { MOD,                 XK_l,            setmfact,       {.f = +0.05} },
  { MOD,                 XK_f,            togglefullscr,  {0} },
	{ MOD|ShiftMask,       XK_Return,       zoom,           {0} },
	{ MOD|ShiftMask,       XK_space,        togglefloating, {0} },

  { MOD,                 XK_g,            togglegaps,     {0} },
  { MOD|ShiftMask,       XK_g,            defaultgaps,    {0} },
  { MOD,                 XK_bracketright, incrgaps,      {.i = +1} },
  { MOD,                 XK_bracketleft,  incrgaps,      {.i = -1} },
  { MOD|ShiftMask,       XK_bracketright, incrgaps,      {.i = +5} },
  { MOD|ShiftMask,       XK_bracketleft,  incrgaps,      {.i = -5} },

	{ MOD,                 XK_y,            setlayout,      {.v = &layouts[0]} },
	{ MOD|ShiftMask,       XK_y,            setlayout,      {.v = &layouts[1]} },
	{ MOD,                 XK_u,            setlayout,      {.v = &layouts[2]} },
	{ MOD|ShiftMask,       XK_u,            setlayout,      {.v = &layouts[3]} },
	{ MOD,                 XK_i,            setlayout,      {.v = &layouts[4]} },
  { MOD|ShiftMask,       XK_i,            setlayout,      {.v = &layouts[5]} },
	{ MOD,                 XK_o,            setlayout,      {.v = &layouts[6]} },
	{ MOD|ShiftMask,       XK_o,            setlayout,      {.v = &layouts[7]} },
	{ MOD,                 XK_space,        setlayout,      {0} },
	{ MOD,                 XK_p,            cyclelayout,    {.i = 0} },
	{ MOD|ShiftMask,       XK_p,            cyclelayout,    {.i = 1} },

	{ MOD|ShiftMask|ALT,   XK_F12,          quit,           {0} },
	{ MOD|ShiftMask,       XK_F12,          quit,           {1} },
};

/* mouse bindings */
/* ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* action               modifier key    button          function        argument */
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            ControlMask,    Button1,        toggleview,     {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },

	{ ClkLtSymbol,          0,              Button1,        cyclelayout,    {.i = 0} },
	{ ClkLtSymbol,          0,              Button3,        cyclelayout,    {.i = 1} },

	{ ClkClientWin,         MOD,            Button1,        movemouse,      {0} },
	{ ClkClientWin,         MOD,            Button2,        togglefloating, {0} },
	{ ClkClientWin,         MOD,            Button3,        resizemouse,    {0} },
};

