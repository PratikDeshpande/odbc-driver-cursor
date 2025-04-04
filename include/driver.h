#pragma once

#include <sql.h>
#include <sqlext.h>
#include <string>
#include <memory>

class ODBCDriver {
public:
    ODBCDriver();
    ~ODBCDriver();

    // Driver initialization and cleanup
    SQLRETURN SQL_API SQLDriverConnect(
        SQLHDBC hdbc,
        SQLHWND hwnd,
        SQLCHAR* szConnStr,
        SQLSMALLINT cbConnStr,
        SQLCHAR* szOutConnStr,
        SQLSMALLINT cbOutConnStr,
        SQLSMALLINT* pcbOutConnStr,
        SQLUSMALLINT fDriverCompletion
    );

    SQLRETURN SQL_API SQLDisconnect(SQLHDBC hdbc);
    SQLRETURN SQL_API SQLFreeHandle(SQLSMALLINT HandleType, SQLHANDLE Handle);

    // Connection attributes
    SQLRETURN SQL_API SQLSetConnectAttr(
        SQLHDBC hdbc,
        SQLINTEGER fAttribute,
        SQLPOINTER vParam,
        SQLINTEGER cbParam
    );

    // Error handling
    SQLRETURN SQL_API SQLError(
        SQLHENV henv,
        SQLHDBC hdbc,
        SQLHSTMT hstmt,
        SQLCHAR* szSqlState,
        SQLINTEGER* pfNativeError,
        SQLCHAR* szErrorMsg,
        SQLSMALLINT cbErrorMsgMax,
        SQLSMALLINT* pcbErrorMsg
    );

private:
    // Add private members as needed
    std::string m_lastError;
}; 