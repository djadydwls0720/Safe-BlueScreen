#include <ntddk.h>

VOID Unload(IN PDRIVER_OBJECT DriverObject) {
    UNREFERENCED_PARAMETER(DriverObject);

    KeBugCheckEx(MANUALLY_INITIATED_CRASH, 0, 0, 0, 0);
}

NTSTATUS DriverEntry(IN PDRIVER_OBJECT DriverObject, IN PUNICODE_STRING RegistryPath) {
    UNREFERENCED_PARAMETER(RegistryPath);

    DriverObject->DriverUnload = Unload;
    DbgPrint("드라이버가 로드되었습니다. 언로드시 블루 스크린이 발생합니다.\n");

    return STATUS_SUCCESS;
}
