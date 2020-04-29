# msgpack-dump

Simple CLI tool that dumps information about a Msgpack object

The input object is read as binary from stdin and the description is written on stdout.

# Installation

## Linux
You need gcc/clang on your computer, nothing else.

Run `make` and move `msgpack-dump` to your local bin folder, or `/usr/local/bin`.

## Windows
>Windows support is untested.

You need Visual Studio's C build tools installed.
Open a "Developer command prompt" and run build.bat


# Usage

Pipe your data to `msgpack-dump` and that's it.

By default, strings are not printed. If you want to enable string value output, pass the `--print-strings` flag.

## Reading hexadecimal data

`msgpack-dump` does not understand hex/base64 input, only binary.

If you need to convert, use standard tools.
Here's an example on how to read an hex string:
```bash
$ echo -n "ce0001e240c2" | xxd -r -p | ./msgpack-dump
Integer : 123456 (unsigned, 32)
Boolean : 0
```

# Limitations

This library is meant to be used with every messagepack object.
Unfortunately, this means that arrays and maps cannot be prettily printed with delimiters, as the array/map count might not reflect the actual number of messagepack objects.
For example, the library would not be able to read an array if it was packed like this:
```
pack_array_size(2)

// First object
pack_bool(true) // var a
pack_int(2) // var b

// Second object
pack_bool(false) // var a
pack_int(3) // var b
```


A flag might be introduced at a later date to enable array pretty printing if you have simple arrays.

Extensions are not supported (yet).

# Thanks

This project uses https://github.com/camgunz/cmp as a lightweight messagepack library