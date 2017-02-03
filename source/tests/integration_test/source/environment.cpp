/*
 *	MetaCall Library by Parra Studios
 *	Copyright (C) 2016 - 2017 Vicente Eduardo Ferrer Garcia <vic798@gmail.com>
 *
 *	A library for dynamic loading and linking shared objects at run-time.
 *
 */
#include <integration-test/environment.hpp>

#include <gmock/gmock.h>

#include <loader/loader.h>

#include <log/log.h>

#include <metacall/metacall.h>

void environment::SetUp() {
	log_configure("metacall",
		log_policy_format_text(),
		log_policy_schedule_sync(),
		log_policy_storage_sequential(),
		log_policy_stream_stdio(stdout));

	const char * py_scripts[] = { "example.py" };
	const char * cs_scripts[] = { "hello.cs" };

	metacall_load_from_file(py_scripts, 1);
	metacall_load_from_file(cs_scripts, 1);
}

void environment::TearDown() {
	loader_unload();

}
