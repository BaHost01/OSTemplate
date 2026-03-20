#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

extern int sys_write(const char*);
extern int sys_read(char*);

static int l_write(lua_State* L) {
    sys_write(lua_tostring(L,1));
    return 0;
}

static int l_read(lua_State* L) {
    char buf[64];
    sys_read(buf);
    lua_pushstring(L, buf);
    return 1;
}

void start_lua() {
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    lua_register(L, "write", l_write);
    lua_register(L, "read", l_read);

    luaL_dostring(L,
        "write('XMPL OS\\n')\n"
        "while true do\n"
        " write('xmpl> ')\n"
        " local cmd = read()\n"
        " if cmd == 'help' then write('help clear exit\\n')\n"
        " elseif cmd == 'exit' then break\n"
        " else write('unknown\\n') end\n"
        "end\n"
    );
}
