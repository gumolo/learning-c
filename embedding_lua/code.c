// code.c

// Create and configure the Lua runtime inside the C program
#include <stdio.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

int c_hello(lua_State *L);

int main() {
// Initialize a Lua state and load the standard libraries.
lua_State *L = luaL_newstate();
luaL_openlibs(L);

// Expose the C function to Lua as a global symbol.
lua_register(L, "hello", c_hello);

// Load and execute a Lua script file from C.
luaL_dofile(L, "script.lua");

lua_close(L);
return 0;
}

// Define a C function that can be called from Lua.
int c_hello(lua_State *L) {
    const char *name = luaL_checkstring(L, 1);

    lua_pushfstring(L, "Hello, %s. We are learning how to embed Lua into C!", name);
    return 1;
}