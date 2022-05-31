#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <xlivebg.h>

static int init(void *cls);
static void cleanup(void *cls);
static int start(long time_msec, void *cls);
static void resize(int x, int y);
static void stop(void *cls);
static void prop(const char *prop, void *cls);
static void draw(long time_msec, void *cls);
static unsigned int create_shader(const char *src, unsigned int type);
static unsigned int create_sdrprog(const char *vsrc, const char *psrc);

#define PROPLIST	\
	"proplist {\n"	\
	"	prop {\n"	\
	"		id = \"initialagents\"\n"	\
	"		desc = \"number of starting slime agents\"\n"	\
	"		type = \"number\"\n"	\
	"		range = [1, 1_000_000]\n"	\
	"	}\n"	\
	"}\n"

static struct xlivebg_plugin plugin = {
	"slime",
	"Slime",
	PROPLIST,
	XLIVEBG_20FPS,
}

