﻿#include "pch.h"

static int read(lua_State* L)
{
	string s;
	cin >> s;
	lua_pushstring(L, s.c_str());
	return 1;
}

static int print(lua_State* L)
{
	const string s = luaL_tolstring(L, 1, nullptr);
	cout << s;
	return 1;
}

static int getc(lua_State* L)
{
	char c;
	cin.get(c);
	lua_pushinteger(L, c);
	return 1;
}

static int getch(lua_State* L)
{
	char c[2];
	cin.get(c[0]);
	c[1] = '\0';
	lua_pushstring(L, c);
	return 1;
}

static int getl(lua_State* L)
{
	string s;
	getline(cin,s);
	lua_pushstring(L, s.c_str());
	return 1;
}

static int sysdo(lua_State* L)
{
	const string command = luaL_tolstring(L, 1, nullptr);
	system(command.c_str());  // NOLINT(concurrency-mt-unsafe)
	return 1;
}

static int requireAllLibs(lua_State* L)
{
	luaL_openlibs(L);
	return 1;
}

static const luaL_Reg BF[] =
{
	{ "read", read },
	{ "print", print },
	{ "getch", getc },
	{ "getchar", getch },
	{ "getline", getl },
	{ "system", sysdo },
	{ "requireAllLibs", requireAllLibs },
	{ nullptr, nullptr }
};

extern "C" BF_API int luaopen_BF(lua_State* L)
{
	luaL_newlib(L, BF);
	return 1;
}