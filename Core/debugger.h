#ifndef debugger_h
#define debugger_h
#include <stdbool.h>
#include <stdint.h>
#include "gb_struct_def.h"
#include "symbol_hash.h"

#ifdef GB_INTERNAL
void GB_debugger_run(GB_gameboy_t *gb);
void GB_debugger_handle_async_commands(GB_gameboy_t *gb);
void GB_debugger_call_hook(GB_gameboy_t *gb, uint16_t call_addr);
void GB_debugger_ret_hook(GB_gameboy_t *gb);
void GB_debugger_test_write_watchpoint(GB_gameboy_t *gb, uint16_t addr, uint8_t value);
void GB_debugger_test_read_watchpoint(GB_gameboy_t *gb, uint16_t addr);
const GB_bank_symbol_t *GB_debugger_find_symbol(GB_gameboy_t *gb, uint16_t addr);
#endif

#ifdef GB_INTERNAL
bool /* Returns true if debugger waits for more commands. Not relevant for non-GB_INTERNAL */
#else
void
#endif
GB_debugger_execute_command(GB_gameboy_t *gb, char *input); /* Destroys input. */


void GB_debugger_load_symbol_file(GB_gameboy_t *gb, const char *path);
const char *GB_debugger_name_for_address(GB_gameboy_t *gb, uint16_t addr);
bool GB_debugger_evaluate(GB_gameboy_t *gb, const char *string, uint16_t *result, uint16_t *result_bank); /* result_bank is -1 if unused. */
void GB_debugger_break(GB_gameboy_t *gb);
bool GB_debugger_is_stopped(GB_gameboy_t *gb);
void GB_debugger_set_disabled(GB_gameboy_t *gb, bool disabled);
#endif /* debugger_h */
