# MyODBCDriver

A basic ODBC driver implementation in C++.

## Prerequisites

- CMake (version 3.10 or higher)
- C++ compiler with C++17 support
- ODBC Driver Manager (unixODBC on Linux/macOS, Windows ODBC on Windows)
- ODBC development headers and libraries

### Installing Dependencies

#### On macOS:
```bash
brew install unixodbc
```

#### On Ubuntu/Debian:
```bash
sudo apt-get install unixodbc-dev
```

## Building the Driver

1. Create a build directory:
```bash
mkdir build
cd build
```

2. Configure the project:
```bash
cmake ..
```

3. Build the driver:
```bash
make
```

4. Install the driver:
```bash
sudo make install
```

## Configuration

After installation, you need to register the driver with your ODBC Driver Manager:

### On macOS/Linux (unixODBC):

1. Add the following to `/etc/odbcinst.ini`:
```ini
[MyODBCDriver]
Description = My ODBC Driver
Driver = /usr/local/lib/libMyODBCDriver.dylib
```

2. Add the following to `/etc/odbc.ini`:
```ini
[MyDataSource]
Driver = MyODBCDriver
Server = your_server
Database = your_database
```

## Usage

You can now use this driver with any ODBC-compatible application. The connection string format is:

```
Driver={MyODBCDriver};Server=your_server;Database=your_database;
```

## Development

This is a basic ODBC driver implementation. To extend it for your specific needs:

1. Implement the connection logic in `SQLDriverConnect`
2. Add statement handling in a new `statement.cpp` file
3. Implement proper error handling in `SQLError`
4. Add support for your specific data types and SQL features

## License

This project is licensed under the MIT License - see the LICENSE file for details. 