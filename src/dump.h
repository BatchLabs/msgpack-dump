#include <stdlib.h>
#include "buffer.h"
#include "cmp.h"

#pragma once

typedef struct {
    buffer buffer;
    size_t position;
} msgpack_data;

msgpack_data make_msgpack_data(buffer buffer);

void dump_msgpack(buffer rawdata, bool print_strings);
void dump_msgpack_object(msgpack_data *raw_data, cmp_object_t* object, bool print_strings);
void dump_msgpack_string(msgpack_data *raw_data, cmp_object_t* object, uint32_t length, bool print_strings);