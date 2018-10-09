/*
* scm1.c
*
*
*/

#include <windows.h>
//#include "../lib/include/windows.h"
#include <stdio.h>

#define SERVICE_NAME "TestService"
#define SERVICE_DISP "Test Service 123"
#define SERVICE_EXEC "C:\\TestService.exe"

int main(void){
    SC_HANDLE sch = NULL;
    SC_HANDLE svc = NULL;

    sch = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
    if(sch == NULL){
        printf("ошибка OpenSCManager().\r\n");
        return(1);
    }

    svc =
        CreateService(sch,
        SERVICE_NAME,
        SERVICE_DISP,
        STANDARD_RIGHTS_REQUIRED,
        SERVICE_WIN32_OWN_PROCESS,
        SERVICE_DEMAND_START,
        SERVICE_ERROR_IGNORE,
        SERVICE_EXEC,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL);
    if(svc == NULL){
        CloseServiceHandle(sch);
        printf("ошибка CreateService().\r\n");
        return(1);
    }

    CloseServiceHandle(sch);
    CloseServiceHandle(svc);

    printf("*** сервис создан.\r\n");
    
    return(0);
}
